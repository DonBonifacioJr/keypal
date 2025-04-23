/*
 * keyboard.c
 *
 *  Created on: Apr 22, 2025
 *      Author: adamj
 */


#include "keyboard.h"
#include "usb_device.h"
#include "usbd_customhid.h"

void ReleaseAllKeys(USBD_HandleTypeDef hUsbDeviceFS,uint8_t modifier)
{
	uint8_t HIDreport[9];
	uint8_t index = 0;
	HIDreport[index++] = modifier;
	HIDreport[index++] = 0;
	HIDreport[index++] = 0;
	HIDreport[index++] = 0;
	HIDreport[index++] = 0;
	HIDreport[index++] = 0;
	HIDreport[index++] = 0;
	HIDreport[index++] = 0;

	USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, HIDreport, index);
}
