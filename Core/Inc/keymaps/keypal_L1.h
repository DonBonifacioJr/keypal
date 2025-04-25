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
		/*	KP1		KP2		KP3	*/
			{0x59,	0x5A,	0x5B},
		/*	KP4		KP5		KP6	*/
			{0x5C,	0x5D,	0x5E},
		/*	KP7		KP8		KP9	*/
			{0x5F,	0x60,	0x61},
		/*			KP0		*/
			{0x00,	0x62,	0x00}
},{
		/*	KP1		KP2		KP3	*/
			{0x59,	0x5A,	0x5B},
		/*	KP4		KP5		KP6	*/
			{0x5C,	0x5D,	0x5E},
		/*	KP7		KP8		KP9	*/
			{0x5F,	0x60,	0x61},
		/*			KP0		*/
			{0x00,	0x62,	0x00}
}};


#endif /* INC_KEYMAPS_KEYPAL_L1_H_ */
