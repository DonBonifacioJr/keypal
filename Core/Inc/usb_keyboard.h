/*
 * usb_keyboard.h
 *
 *  Created on: Apr 17, 2025
 *      Author: adamj
 */

#ifndef INC_USB_KEYBOARD_H_
#define INC_USB_KEYBOARD_H_

#include "stm32f4xx.h"

void USB_Send_Key_Press(char c, uint8_t modifier);

void USB_Send_Key_Release(char c, uint8_t modifier);

void USB_Send_All_Keys_Released(uint8_t modifier);


#endif /* INC_USB_KEYBOARD_H_ */
