/****************************************************************************
 *
 * Copyright (c) 2023 STMicroelectronics - All Rights Reserved
 *
 * License terms: STMicroelectronics Proprietary in accordance with licensing
 * terms SLA0098 at www.st.com.
 *
 * THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
 * INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 * DO NOT EDIT: Automatically generated file
 *****************************************************************************/

#include <uart_cfg.h>
#include <irq.h>

/* Internal configuration data.*/


/* Exported configuration APIs.*/

void uart_cfg1(uart_driver_t *udp) {

	/* Configure UART driver instance.*/
	(void)uart_set_prio(udp, IRQ_PRIORITY_15);
	(void)uart_set_rx_drv_mode(udp, UART_RX_DRV_MODE_INT_SYNC);
	(void)uart_set_tx_drv_mode(udp, UART_TX_DRV_MODE_INT_SYNC);
	(void)uart_set_fifo_enable(udp, false);
	(void)uart_set_baud(udp, UART_BAUDRATE_38400);
	(void)uart_set_presc(udp, UART_PRESCALER_DIV1);
	(void)uart_set_parity(udp, UART_PARITY_NONE);
	(void)uart_set_over(udp, UART_OVERSAMPLING_16);
	(void)uart_set_sbit(udp, UART_STOPBIT_1);
}
