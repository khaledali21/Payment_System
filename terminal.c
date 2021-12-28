/*
 * terminal.c
 *
 *  Created on: Dec 27, 2021
 *      Author: Khaled Ali
 */


#include <stdio.h>
#include <stdint.h>
#include "terminal.h"



/*
 * brief: Read Terminal data from the client
 * param: (input) a pointer to structure containing transaction in terminal info
 */
uint8_t getTerminalData(ST_terminalData_t* pstr_terminalInfo){
	printf("Please Enter the transaction Amount: \n"); fflush(stdout);
	scanf("%f", &pstr_terminalInfo -> transAmount);
	fflush(stdin);
	if(pstr_terminalInfo -> transAmount > pstr_terminalInfo -> maxTransAmount)
	{
		return 0;
	}
	printf("Please Enter transaction Date: \n"); fflush(stdout);
	gets(pstr_terminalInfo -> transactionDate);
	return 1;
}
