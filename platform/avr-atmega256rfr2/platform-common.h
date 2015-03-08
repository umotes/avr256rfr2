/** 
 * \brief Compiler and Platform specific definitions and typedefs common to
 * all platforms.  
 *
 * platform-common.h provides PLATFORM_HEADER defaults and common definitions.
 * This head should never be included directly, it should only be included
 * by the specific PLATFORM_HEADER used by your platform.
 *
 * See platform-common.h for source code.
 *@{
 */

/**
 * @addtogroup stm32w-cpu
 * @{ */

/** \file hal/micro/generic/compiler/platform-common.h
 * See \ref platform_common for detailed documentation.
 *
 * <!--(C) COPYRIGHT 2010 STMicroelectronics. All rights reserved.        -->
 */


#ifndef PLATFORMCOMMON_H_
#define PLATFORMCOMMON_H_
////////////////////////////////////////////////////////////////////////////////
// Many of the common definitions must be explicitly enabled by the 
//  particular PLATFORM_HEADER being used
////////////////////////////////////////////////////////////////////////////////


#define TRUE  1
#define HIGH 1
#define FALSE 0
#define LOW 0
#ifndef NULL
#define NULL ((void *)0)
#endif

#define BIT(x) (1U << (x))  // Unsigned avoids compiler warnings re BIT(15)

#define SETBIT(reg, bit)      reg |= BIT(bit)
#define SETBITS(reg, bits)    reg |= (bits)
#define CLEARBIT(reg, bit)    reg &= ~(BIT(bit))
#define CLEARBITS(reg, bits)  reg &= ~(bits)
#define READBIT(reg, bit)     (reg & (BIT(bit)))
#define READBITS(reg, bits)   (reg & (bits))

#define PORT_PIN_0 0x01
#define PORT_PIN_1 0x02
#define PORT_PIN_2 0x04
#define PORT_PIN_3 0x08
#define PORT_PIN_4 0x10
#define PORT_PIN_5 0x20
#define PORT_PIN_6 0x40
#define PORT_PIN_7 0x80
#define PORT_PIN_ALL 0xFF

#define LEDS_PBDIR DDRB // port direction register
#define LEDS_PBOUT PORTB // port register

#define LEDS_PEOUT PORTE // port register
#define LEDS_PEDIR DDRE // port direction register

#define READ  1
#define WRITE 0

#define LEDS_POWER  0x01 //red led
#define LEDS_STATUS 0x02 // green led
#define LEDS_USER   0x10 // yellow led

#define MAX_INT8U_VALUE 0xFF
#define MAX_INT16U_VALUE 0xFFFF
#define MAX_INT32U_VALUE 0xFFFFFFFF

#define LEDS_CONF_RED    0x01
#define LEDS_CONF_GREEN  0x02
#define LEDS_CONF_YELLOW 0x10


#define LEDS_RED      0x01
#define LEDS_GREEN    0x02
#define LEDS_YELLOW   0x10





#endif //PLATFORMCOMMON_H_

/** @}  END addtogroup */
/** @} */

