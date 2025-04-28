/*
 * keypal_L1.h
 *
 *  Created on: Apr 21, 2025
 *      Author: adamj
 */

#ifndef INC_KEYMAPS_KEYPAL_L1_H_
#define INC_KEYMAPS_KEYPAL_L1_H_

uint16_t KEY_MAP[3][4][3] = {{
		/*	KP1		KP2		KP3	*/
			{0x59,	0x5A,	0x5B},
		/*	KP4		KP5		KP6	*/
			{0x5C,	0x5D,	0x5E},
		/*	KP7		KP8		KP9	*/
			{0x5F,	0x60,	0x61},
		/*	LCRTL	KP0			*/
			{0xE0,	0x62,	0x00}
},{
		/*	Q		W		E	*/
			{0x14,	0x1A,	0x08},
		/*	A		S		D	*/
			{0x04,	0x16,	0x07},
		/*	Z		X		C	*/
			{0x1D,	0x1B,	0x06},
		/*	CTRl	SHFT	*/
			{0xE0,	0xE1,	0x00}
},{
		/*	E		M		B	*/
			{0x08,	0x10,	0x05},
		/*	E		D		D	*/
			{0x08,	0x07,	0x07},
		/*	E		D		!	*/
			{0x08,	0x07,	0x1E},
		/*	BKSP	SHFT	*/
			{0x2A,	0xE5,	0x00}
}};


#endif /* INC_KEYMAPS_KEYPAL_L1_H_ */
