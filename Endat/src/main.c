/****************************************************************************
*
* Copyright (c) 2024 STMicroelectronics - All Rights Reserved
*
* License terms: STMicroelectronics Proprietary in accordance with licensing
* terms SLA0098 at www.st.com.
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* EVALUATION ONLY - NOT FOR USE IN PRODUCTION
*****************************************************************************/

#include <test_env.h>
#include <uart_cfg.h>


//HRTIM1_B2 = 86
//HRTIM1_B1 = 87
//HRTIM1_A2 = 88
//HRTIM1_A1 = 89

//pin_gpio_4_1 = 86
//pin_gpio_4_2 = 87
//pin_gpio_4_3 = 88
//pin_gpio_4_4 = 89


#define CLK_ON  gpio_set_pin(PIN_GPIO4_1)
#define CLK_OFF gpio_clear_pin(PIN_GPIO4_1)

#define D_OUT_ON  gpio_set_pin(PIN_GPIO4_2)
#define D_OUT_OFF gpio_clear_pin(PIN_GPIO4_2)

#define DE_ON  gpio_set_pin(PIN_GPIO4_3)
#define DE_OFF gpio_clear_pin(PIN_GPIO4_3)

#define DIN PIN_GPIO4_4

/*
const uint8_t MODE_RESET = 0b101010;
const uint8_t MODE_MRS   = 0b001110;
const uint8_t MODE_RECEIVE_TEST = 0b110001;
*/

GPIO_TypeDef *p_pin_in;
uint32_t pin_mask;


GPIO_TypeDef *p_pin_clk;
uint32_t pin_mask_clk;


void EnDat_Command(unsigned long ec_data_out, unsigned char ec_data_in_clk,
        unsigned long long *ec_pos, unsigned char *ec_status,
							unsigned char ec_mode_type);

void EnDat_Mode_Command (unsigned int emc_mode, unsigned int emc_adr, unsigned int *emc_data, unsigned char *emc_status);

void Clock_Test() {
	CLK_ON;
	CLK_OFF;
	CLK_ON;
	CLK_OFF;
	CLK_ON;
	CLK_OFF;
}

void EnDat_Mode_Command (unsigned int emc_mode, unsigned int emc_adr, unsigned int *emc_data, unsigned char *emc_status)
{
  unsigned long data_out;		// 32-bit value containing the bitstream that is sent to the encoder
  unsigned long long pos;		// 64-bit variable for positon / address + data
  unsigned int stored_adr;		// store address for F-Type II calculation
  int i;						// auxiliary variable
  unsigned int ec_adr = 0;		// needed to sort address
  unsigned int ec_data = 0;		// needed to sort data

  // store address for later F-Type II calculation
  stored_adr = emc_adr;
  // these mode commands have a 30bit datastream that is sent to the encoder:
  // 6bit mode command + 8bit address + 16bit data
  // to make sending routine easier the bitstream is sorted accordingly

  // reverse data direction of address
  for (i=0; i < 8; i++)
   {
     ec_adr <<= 1;
     ec_adr += ((emc_adr & 1));
     emc_adr >>= 1;
   };
  // reverse data direction of data
  for (i=0; i < 16; i++)
   {
    ec_data <<= 1;
    ec_data += ((*emc_data & 1));
     *emc_data >>= 1;
   };
   // and connect all data to a bitstream that can be sent accordingly to
   // EnDat definition by sending starting with LSB
  data_out = emc_mode + ((long)ec_adr<<6) + ((long)ec_data<<14);

  // Send EnDat mode command; 24 bit are read in from encoder: 8 bit address + 16 bit data
  EnDat_Command (data_out, 24, &pos, emc_status, 1);

  /*emc_adr = (pos & 0xFF);		// address is lower 8 bit of pos
  *emc_data = (pos & 0xFFFF0000) >> 16; // data is mid 16 bit of pos
*/

  emc_adr = (pos & 0xFF0000);
  *emc_data = (pos & 0xFFFF);
  // and check for F-tpye 2: sent and received address differ --> set bit 2
  if (stored_adr != emc_adr)
    *emc_status += 4;
};


void EnDat_Command(unsigned long ec_data_out, unsigned char ec_data_in_clk,
        unsigned long long *ec_pos, unsigned char *ec_status,
							unsigned char ec_mode_type) {

	unsigned char n_cnt[3] = {0,0,0};	    // number of clocks to send
	unsigned int data_in[3] = {0,0,0};	    // position is max. 48-bit --> 3x16bit variable
	unsigned int data_in_copy[3] = {0,0,0};
	int i,a;                                    // auxiliary varibles
	unsigned int  Data_Out_Clk = 6;             // number of clocks to send; default for position command --> "6"
	unsigned int crc_in = 0;                    // CRC sent from the encoder
	unsigned int crc_out = 0;                   // CRC calculated based on the read-in data
	unsigned int f_bit = 0;                     // EnDat F1 bit
	unsigned int ex = 0;                        // auxiliary variable for CRC calculation
	unsigned int ff[5] = {1,1,1,1,1};           // Flip-Flop for CRC calculation
	char bit_in;

	uint32_t data_in_test = 0;
	uint32_t tmp_test = 0;

	if (ec_data_in_clk < 33) {
		n_cnt[0] = 16;
		n_cnt[1] = ec_data_in_clk-16;
		n_cnt[2] = 0;
	} else {
		n_cnt[0] = 16;
		n_cnt[1] = 16;
		n_cnt[2] = ec_data_in_clk - 32;
	}

	if (ec_data_in_clk < 17) {
		n_cnt[0] = ec_data_in_clk;
		n_cnt[1] = 0;
		n_cnt[2] = 0;
	}

	// if the mode command is of type "1", the n_cnt variable is defined in that way that
	// the lower 16 bit contain the address
	// and the mid 16 bit contain the data
	if (ec_mode_type == 1) {
		n_cnt[0] = 8;
		n_cnt[1] = 16;
		n_cnt[2] = 0;
		Data_Out_Clk = 30;
	}

	// first part of EnDat communication is to send data to the encoder
	// mode-command
	// and address and data for mode-commands type "1"
	// two clocks to switch data direction at the beginning
	// two clocks after sending data to the encoder --> "Data_Out_Clk + 4"


	for ( i = 0; i < (Data_Out_Clk+4) ; i++) {
		CLK_OFF;

		//after first clock pulse, data enable on
		if (i == 1)
			DE_ON;

		//after sending the data, data enable off to listen for
		//the start bit
		if (i == (Data_Out_Clk + 2))
			DE_OFF;

		if (i > 1) {
			if (ec_data_out & 1)
				D_OUT_ON;
			else
				D_OUT_OFF;

			ec_data_out >>= 1;
		}

		//osal_delay_microsec(5);
		CLK_ON;
		//osal_delay_microsec(5);
	}


	CLK_OFF;
	osal_delay_microsec(2);

	//polling start bit
	while(!gpio_read_pin(DIN)) {
	//while(!(p_pin_in->IDR & pin_mask)) {

		CLK_ON;
		//osal_delay_microsec(5);
		CLK_OFF;
		//osal_delay_microsec(5);
		//can the encoder have enough time to send data so i can see it in readPin?
	}

	if (ec_mode_type == 0) {
		CLK_ON;
		//osal_delay_microsec(5);
		CLK_OFF;
		//osal_delay_microsec(5);
		//f_bit = (gpio_read_pin(DIN) ? 1:0);
		f_bit = (p_pin_in->IDR & pin_mask ? 1:0);

		// calculate CRC
		ex = ff[4] ^ f_bit;
		ff[4] = ff[3];
		ff[3] = ff[2] ^ ex;
		ff[2] = ff[1];
		ff[1] = ff[0] ^ ex;
		ff[0] = ex;
	}




	//Parte del codice ottimizzato, il crc e il bit shift devono essere fatti dopo
	for (i = 0;i < ec_data_in_clk; i++) {
		p_pin_clk->BSRR = pin_mask_clk;
		data_in_test <<= 1;
		CLK_OFF;

		bit_in = ((p_pin_in->IDR & pin_mask)) ? 1:0;
		data_in_test += bit_in;
	}


	// finally the 5 bit for CRC need to be read
	// CRC is send MSB first, shift direction is accordingly
	for (i=0; i < 5; i++) {
		CLK_ON;
		//osal_delay_microsec(5);
		crc_in <<= 1;
		CLK_OFF;
		//osal_delay_microsec(5);
		crc_in += ((p_pin_in->IDR & pin_mask)) ? 1:0;

	};

	// set CLK-line to high to finish transmission; the high-time must be > 30 µs (ellapse of recovery time I)
	// due to that it can be an advantage to calculate CRC after finishing transmission
	CLK_ON;

	int bitmask = 1 << (ec_data_in_clk - 1);


	if (ec_mode_type == 0) {

		for(int i = 0; i < ec_data_in_clk; i++) {
			bit_in = (data_in_test & bitmask) ? 1:0;

			ex = ff[4] ^ bit_in;
			ff[4] = ff[3];
			ff[3] = ff[2] ^ ex;
			ff[2] = ff[1];
			ff[1] = ff[0] ^ ex;
			ff[0] = ex;

			tmp_test += bit_in << i;
			bitmask >>= 1;
		}

		*ec_pos = tmp_test;
	} else {

		for(int i = 0; i < ec_data_in_clk; i++) {
			bit_in = (data_in_test & bitmask) ? 1:0;

			ex = ff[4] ^ bit_in;
			ff[4] = ff[3];
			ff[3] = ff[2] ^ ex;
			ff[2] = ff[1];
			ff[1] = ff[0] ^ ex;
			ff[0] = ex;

			bitmask >>= 1;
		}
		*ec_pos = data_in_test;
	}




	osal_delay_microsec(30);

	// calculate position value


	// CRC value must be sorted to calculate the final value
	crc_out = 0;
	for (i=4; i>=0; i--) {
		ff[i] = ff[i] ? 0 : 1;
		crc_out <<= 1;
		crc_out |= ff[i];
	};

	// calculate status
	// bit0: F-bit
	// bit1: CRC check
	*ec_status = f_bit;
	if (crc_in != crc_out){
		*ec_status = *ec_status + 2;
	}
}



void Endat_startup() {
	//hal delay 20

	//first clock pulse after power-up hard reset.
	CLK_ON;
	osal_delay_microsec(5);

	CLK_OFF;
	osal_delay_microsec(5);

	CLK_ON;
	osal_delay_microsec(5);


	DE_OFF; //data enable disattivato

	//delay 30 microsecond
	osal_delay_microsec(30);


	//Sending reset mode command
	//Set MRS Code
	//read error register
	//delete error

}


// definition of constants
// definition of 6-bit values for mode commands
const unsigned int mode_pos     = 0x38;
const unsigned int mode_MRS     = 0x1C;
const unsigned int mode_send    = 0x31;
const unsigned int mode_receive = 0x0E;
const unsigned int mode_reset   = 0x15;
const unsigned int mode_test 	= 0b00100011;
// definition or MRS-codes for EnDat parameter
const unsigned int MRS_E21_1 = 0xA1;
const unsigned int MRS_E21_2 = 0xA3;
const unsigned int MRS_E21_3 = 0xA5;
const unsigned int MRS_OP_Conditions = (unsigned int) 0xB9;

const unsigned int MRS_OP_Parameters = 0b10100111;

unsigned int Data;			// data for parameters read from the encoder

// declaration of variables
unsigned int Pos_Bit;			// nr. of bits for positon, EnDat 2.1 parameter word 13
unsigned long Data_Out;			// data sent to the encoder
unsigned char Error_Status;		// error status: bit0 = F1; bit1 = CRC error; bit2 = F-type II
unsigned int Data;			// data for parameters read from the encoder
unsigned long Meas_Step;		// measuring step or nr. of measuring steps per revolution; EnDat 2.1 parameter word 20 + 21
unsigned long Meas_Step_Copy;		// local copy for calculation
unsigned int Meas_Step_Bit;		// especially for rotary encoders the bit-count of Meas_Step must be calculated
unsigned int Revolutions;		// for multiturn encoders, EnDat 2.1 word 17
unsigned int Enc_Model;			// type of encoder, EnDat 2.1 word 14
unsigned long long Enc_Position;	// 64-bit variable for the 48-bit encoder position
unsigned int MT_Value;			// actual number of revolutions; for multiturn encoder
float Pos_Final;			// position in µm or deg


int main(void)
{
    /* Enable interrupts.*/
    osal_sys_unlock();

	test_env_init((TestInit_t)
                  (TEST_INIT_CLOCK    |
                   TEST_INIT_GPIO     |
                   TEST_INIT_BOARD    |
                   TEST_INIT_IRQ      |
                   TEST_INIT_OSAL));

    /* Application main loop */
    uart_init(&DRV_UART3);
    uart_cfg1(&DRV_UART3);
    uart_start(&DRV_UART3);

    //Clock_Test();

    Endat_startup();
	osal_delay_microsec(200);

    (void)uart_write(&DRV_UART3, (uint8_t *)"Hello World!!!\n\r", 16U);



    gpio_port_t port = gpio_iounpack_port(DIN);
    gpio_pin_t pin   = gpio_iounpack_pin(DIN);
    p_pin_in = gpio_dev_get_port_reg_ptr(port);
    pin_mask = (1U << pin);

    gpio_port_t port_ = gpio_iounpack_port(PIN_GPIO4_1);
	gpio_pin_t pin_   = gpio_iounpack_pin(PIN_GPIO4_1);
	p_pin_clk  = gpio_dev_get_port_reg_ptr(port_);
	pin_mask_clk = 1U << pin_;



    //send reset to the encoder
    EnDat_Mode_Command (mode_reset, 0, &Data, &Error_Status);
    (void)uart_write(&DRV_UART3, (uint8_t *)"Reset status\n\r", 14U);
    //(void)uart_write(&DRV_UART3, Error_Status ,1U);
    (void)uart_write(&DRV_UART3, (uint8_t *)"\n\r", 2U);

    EnDat_Mode_Command (mode_test, MRS_OP_Conditions, &Data, &Error_Status);


    // set MRS Code to operating conditions --> to read error register
	EnDat_Mode_Command (mode_MRS, MRS_OP_Conditions, &Data, &Error_Status);

	//read error register
	EnDat_Mode_Command (mode_send, 0, &Data, &Error_Status);
	//(void)uart_write(&DRV_UART3, Data, sizeof(Data));

	if (Data != 0) {
	     EnDat_Mode_Command (mode_receive, 0, &Data, &Error_Status);
	     EnDat_Mode_Command (mode_reset, 0, &Data, &Error_Status);
	     EnDat_Mode_Command (mode_MRS, MRS_OP_Conditions, &Data, &Error_Status);
	     EnDat_Mode_Command (mode_send, 0, &Data, &Error_Status);

	}

	// set MRS Code to EnDat 2.1 parameter area, first 16 addresses
	EnDat_Mode_Command (mode_MRS, MRS_E21_1, &Data, &Error_Status);

	// read number of bits to send for position, EnDat 2.1 parameter word 13
	EnDat_Mode_Command (mode_send, 13, &Data, &Error_Status);
	Pos_Bit = Data & 0x3F;

	// read encoder type, EnDat 2.1 parameter word 14
	EnDat_Mode_Command (mode_send, 14, &Data, &Error_Status);
	Enc_Model = ((Data >> 12) & 0x000F);

	// set MRS Code to EnDat 2.1 parameter area, middle 16 addresses //
	EnDat_Mode_Command (mode_MRS, MRS_E21_2, &Data, &Error_Status);

	// read value for measuring step or steps per revolution, EnDat 2.1 parameter word 20 + 21
	// word 20 --> lower 16 bit
	EnDat_Mode_Command (mode_send, 4, &Data, &Error_Status);
	Meas_Step = Data;

	// word 21 --> upper 16 bit
	EnDat_Mode_Command (mode_send, 5, &Data, &Error_Status);

	// connect word 20 + 21 to the overall 32-bit value //
	Meas_Step += ((long)Data << 16);

	// calculate nr. of bits for measuring steps; only relevant for rotary encoders
	Meas_Step_Copy = (Meas_Step -1);
	Meas_Step_Bit = 0;
	while (Meas_Step_Copy > 0){
		Meas_Step_Copy >>= 1;
		Meas_Step_Bit++;
	};

	// read number of revolutions, EnDat 2.1 parameters, word 17
	  EnDat_Mode_Command (mode_send, 1, &Data, &Error_Status);
	  Revolutions = Data;
	/*
	// set MRS Code to EnDat 2.1 parameter area, first 16 addresses
	EnDat_Mode_Command (mode_MRS, MRS_E21_1, &Data, &Error_Status);

	EnDat_Mode_Command (mode_send, 13, &Data, &Error_Status);
	Pos_Bit = Data & 0x3F;

	// read encoder type, EnDat 2.1 parameter word 14
	EnDat_Mode_Command (mode_send, 14, &Data, &Error_Status);
	Enc_Model = ((Data >> 12) & 0x000F);			// only upper 4 bit are of interest


	// set MRS Code to EnDat 2.1 parameter area, middle 16 addresses //
	EnDat_Mode_Command (mode_MRS, MRS_E21_2, &Data, &Error_Status);
	//Serial.print("MRS 0xA3 command sent, Status: ");
	//Serial.println(Error_Status);

	// read value for measuring step or steps per revolution, EnDat 2.1 parameter word 20 + 21
	// word 20 --> lower 16 bit
	EnDat_Mode_Command (mode_send, 4, &Data, &Error_Status);
	Meas_Step = Data;

	// word 21 --> upper 16 bit
	EnDat_Mode_Command (mode_send, 5, &Data, &Error_Status);
*/
	// connect word 20 + 21 to the overall 32-bit value //
	//Meas_Step += ((long)Data << 16);
	/*Serial.print("Measuring Step or Measuring steps per revolution: ");
	Serial.println(Meas_Step);
	Serial.print("and status: ");
	Serial.println(Error_Status);
*/
	// calculate nr. of bits for measuring steps; only relevant for rotary encoders
	//Meas_Step_Copy = (Meas_Step -1);
	//Meas_Step_Bit = 0;
	/*while (Meas_Step_Copy > 0)
	{
	 Meas_Step_Copy >>= 1;
		 Meas_Step_Bit++;
	};*/
	/*Serial.print("Measuring Step or Measuring steps per revolution in bit: ");
	Serial.println(Meas_Step_Bit);
*/
	// read number of revolutions, EnDat 2.1 parameters, word 17
	//EnDat_Mode_Command (mode_send, 1, &Data, &Error_Status);

	  /*reading temperature sensor type*/
	    EnDat_Mode_Command (mode_MRS, MRS_OP_Parameters, &Data, &Error_Status);
		EnDat_Mode_Command (mode_send, 9, &Data, &Error_Status);
		EnDat_Mode_Command (mode_send, 10, &Data, &Error_Status);
		EnDat_Mode_Command (mode_send, 11, &Data, &Error_Status);



	for ( ; ; ) {
		//EnDat_Mode_Command(mode_pos, Pos_Bit, &Data, &Error_Status);
	    //Pos_Final = 360*( (float) Data / Meas_Step);
		Data_Out = mode_pos;
		EnDat_Command (Data_Out, Pos_Bit, &Enc_Position, &Error_Status, 0);

		if(Enc_Model == 12) {
			Pos_Final = 360*(((float)Enc_Position) / Meas_Step);
		}
		//Endat_startup();
		//(void)uart_write(&DRV_UART3, (uint8_t *)"Hello World!!!\n\r", 16U);

    	//output = Endat_sendModeCommand(MODE_RECEIVE_TEST, 4);
		/*DE_OFF;
		osal_delay_microsec(5);

		DE_ON;
		osal_delay_microsec(5);
*/
		/*CLK_ON;
    	osal_delay_microsec(5);

    	CLK_OFF;*/
    	/*
    	output = gpio_read_pin(DIN);
    	if (output) {
    		CLK_OFF;
            (void)uart_write(&DRV_UART3, (uint8_t *)"Hello World!!!\n\r", 16U);
    	} else {
    		CLK_ON;
    	}
		*/
    	/*osal_delay_microsec(5);
    	CLK_ON;
    	osal_delay_microsec(5);
    	CLK_OFF;*/
    }
}
