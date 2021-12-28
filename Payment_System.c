/*
 ============================================================================
 Name        : Payment_System.c
 Author      : Khaled
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "card.h"
#include "terminal.h"
#include "server.h"
#include "Payment_System.h"
#define MAX_TRANSACTION 5000
int main(void) {
	uint8_t u8_repeat = 1, u8_answer;
	ST_cardData_t str_cardInfo;
	ST_terminalData_t str_terminalInfo;
	str_terminalInfo.maxTransAmount = MAX_TRANSACTION;
	while(u8_repeat){
	fflush(stdin);
	printf("Please Enter Card data: \n");	fflush(stdout);
	readCard(&str_cardInfo);
	printf("Please Enter Terminal data: \n"); fflush(stdout);
	uint8_t status = getTerminalData(&str_terminalInfo);
	if(status){
		status = verifyData(&str_cardInfo, &str_terminalInfo);
		if(status){
			printf("The Transaction is APPROVED.\n"); fflush(stdout);
		}
		else{
			printf("The Transaction is DECLINED.\n"); fflush(stdout);
		}
	}
	else{
		printf("The Transaction is DECLINED.\n"); fflush(stdout);
	}
	printf("Do you want to continue (y/n)? \n"); fflush(stdout);
	scanf("%c", & u8_answer);
	if(u8_answer != 'y'){
		u8_repeat = 0;
	}
	}
	return 0;
}

/*
 * brief: check card data with terminal and server
 * param: (input) a pointer to a structure containing card info
 * param: (input) a pointer to structure containing transaction in terminal info
 * return: (output) 1 if transaction is approved and 0 otherwise
 */
uint8_t verifyData(ST_cardData_t* pstr_cardInfo, ST_terminalData_t* pstr_terminalInfo){
	//ٌcheck Date
	uint8_t u8_expireYear = (pstr_cardInfo -> cardExpirationDate[3] - '0') * 10 + (pstr_cardInfo -> cardExpirationDate[4] - '0');
	uint8_t u8_expireMonth = (pstr_cardInfo -> cardExpirationDate[0] - '0') * 10 + (pstr_cardInfo -> cardExpirationDate[1] - '0');
	uint8_t u8_transactionYear = (pstr_terminalInfo -> transactionDate[8] - '0') * 10 + (pstr_terminalInfo -> transactionDate[9] - '0');
	uint8_t u8_transactionMonth = (pstr_terminalInfo -> transactionDate[3] - '0') * 10 + (pstr_terminalInfo -> transactionDate[4] - '0');
	if((u8_expireYear < u8_transactionYear) || (u8_expireYear == u8_transactionYear && u8_expireMonth < u8_transactionMonth)){
		return 0;
	}
	if(pstr_terminalInfo -> transAmount > pstr_terminalInfo -> maxTransAmount){
		return 0;
	}
	float balance = getAccount(pstr_cardInfo -> primaryAccountNumber);
	if(balance == -1 || balance < pstr_terminalInfo -> transAmount){
		return 0;
	}
	return 1;

}
