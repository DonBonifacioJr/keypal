/*
 * keyscanner.h
 *
 *  Created on: Apr 21, 2025
 *      Author: adamj
 */

#ifndef INC_KEYSCANNER_H_
#define INC_KEYSCANNER_H_

#define NUM_ROWS 4
#define NUM_COLS 3

void SetAllCols();
void ResetAllCols();
void SetCol(int col);
int ReadRow(int row);
void ScanKeys();

#endif /* INC_KEYSCANNER_H_ */
