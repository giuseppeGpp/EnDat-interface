################################################################################
# Project makefile.
################################################################################

# 'Stellar SDK' project values
PROJECTNAME := Endat
SDKID := StellarESDK-1.8.0

# Please Update it if you move your workspace
STELLAR_E_SDK_RELATIVE_PATH := ../../SDKS/$(SDKID)
TEST_ROOT_DIR := $(STELLAR_E_SDK_RELATIVE_PATH)
PROJECT_COMMON_DIR := $(STELLAR_E_SDK_RELATIVE_PATH)/Projects/SDKTests/CommonBuild

################################################################################
# Define device (sr5e1)
# Define board :
# sr5e1 ==> (evbe7000p/evbe7000s/evbe3000p/evbe7000e/evbe3000e/evbe3000d)
# WARNING : your board should match with your device
################################################################################

CONFIG_DEVICE := sr5e1
CONFIG_BOARD := steval_ttm007a
CONFIG_TARGET_MEMORY ?= ram # ram or nvm

include $(PROJECT_COMMON_DIR)/make/test_defs.mk

ifeq ($(wildcard $(STELLAR_E_SDK_BUILD_SYSTEM_DIR)/StellarESDK.mk),)
$(error $(STELLAR_E_SDK_BUILD_SYSTEM_DIR)/StellarESDK.mk does not exist)
$(error Install the $(SDKID) or Correct STELLAR_E_SDK_RELATIVE_PATH)
endif

################################################################################
# Project builds
################################################################################
BUILD_OS_OSAL                  := 1
BUILD_DRIVERS_DMA              := 1
BUILD_DRIVERS_UART             := 1

################################################################################
# Add project files
################################################################################

# Application name
APP_NAME := $(PROJECTNAME)

# C sources
C_SRCS += \
	src/main.c \
	cfg/uart_cfg.c
# C includes
################################################################################
# PLEASE UPDATE IT FOR GENERATED CODE
# DO NOT FORGET TO CLEAN THE PROJECT 
# FOR THE DEPENDENCIES FILES
################################################################################
C_INCS += \
	include/ \
	src-gen/ \
 	src-gen/$(CONFIG_DEVICE) \
 	cfg
################################################################################
# Include 'Stellar SDK' top level makefile
################################################################################
include $(STELLAR_E_SDK_BUILD_SYSTEM_DIR)/StellarESDK.mk

################################################################################
# Define 'Stellar E SDK' compiling target
################################################################################
all: default-all


