#ifndef _TUSB_CONFIG_H_
#define _TUSB_CONFIG_H_

#include "stm32u5xx_hal.h"

#define CFG_TUSB_MCU                 OPT_MCU_STM32U5
#define CFG_TUSB_OS                  OPT_OS_NONE

#define BOARD_DEVICE_RHPORT_NUM      0
#define BOARD_DEVICE_RHPORT_SPEED    OPT_MODE_FULL_SPEED
#define CFG_TUSB_RHPORT0_MODE        (OPT_MODE_DEVICE | OPT_MODE_FULL_SPEED)

// Enable device stack
#define CFG_TUD_ENABLED              1

// USB Class support
#define CFG_TUD_HID                  1

// HID buffer size
#define CFG_TUD_HID_EP_BUFSIZE       64

#endif /* _TUSB_CONFIG_H_ */
