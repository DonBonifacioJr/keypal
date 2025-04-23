/*
 * keyboard.h
 *
 *  Created on: Apr 22, 2025
 *      Author: adamj
 */
#include "usb_device.h"
#include "usbd_customhid.h"

void ReleaseAllKeys(USBD_HandleTypeDef hUsbDeviceFS,uint8_t modifier);
