/*
 * usb_keyboard.c
 *
 *		Functions to help send USB reports for key presses
 *		These reports are to be send in every packet for the USB protocol
 *		The format of this report is standard and can be found for HID keyboard
 *		The report has a max of 6 keys at 1 time. :O
 *
 *  Created on: Apr 17, 2025
 *      Author: adamj
 */


#include "usb_keyboard.h"
#include "usb_device.h"
#include "usbd_custom_hid_if.h"

// Report so that it send a single key to be pressed
void USB_Send_Key_Press(char c, uint8_t modifier)
{
	uint8_t report[9];
	uint8_t index = 0;

	report[index++] = modifier;
	report[index++] = 0x00;
	// Only programmed for one press at a time, Might add additional functionality later
	report[index++] = (uint8_t)c;
	report[index++] = 0x00;
	report[index++] = 0x00;
	report[index++] = 0x00;
	report[index++] = 0x00;
	report[index++] = 0x00;

	CUSTOM_HID_SendReport_FS(report, index);
}

// Report send to release a key
void USB_Send_Key_Release(char c, uint8_t modifier)
{
	uint8_t report[9];
	uint8_t index = 0;

	report[index++] = modifier;
	report[index++] = 0x00;
	// Only programmed for one press at a time, Might add additional functionality later
	report[index++] = (uint8_t)c;
	report[index++] = 0x00;
	report[index++] = 0x00;
	report[index++] = 0x00;
	report[index++] = 0x00;
	report[index++] = 0x00;

	CUSTOM_HID_SendReport_FS(report, index);
}

// Report to release all the keys
void USB_Send_All_Keys_Released(uint8_t modifier)
{
	uint8_t report[9];
	uint8_t index = 0;

	report[index++] = modifier;
	report[index++] = 0x00;
	report[index++] = 0x00;
	report[index++] = 0x00;
	report[index++] = 0x00;
	report[index++] = 0x00;
	report[index++] = 0x00;
	report[index++] = 0x00;

	CUSTOM_HID_SendReport_FS(report, index);
}
