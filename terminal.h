/*
 * terminal.h
 *
 *  Created on: Dec 27, 2021
 *      Author: Khaled Ali
 */

#ifndef TERMINAL_H_
#define TERMINAL_H_

#include <stdint.h>

typedef struct
{	float transAmount;
	float maxTransAmount;
	uint8_t transactionDate[11];
}ST_terminalData_t;

uint8_t getTerminalData(ST_terminalData_t* pstr_terminalInfo);

#endif /* TERMINAL_H_ */
