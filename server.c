/*
 * server.c
 *
 *  Created on: Dec 27, 2021
 *      Author: Khaled Ali
 */
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "server.h"

ST_accountBalance_t database[] ={
		{ "123456789", 100.00},
		{ "234567891", 6000.00},
		{ "567891234", 3250.25},
		{ "456789123", 1500.12},
		{ "258649173", 500.00},
		{ "654823719", 2100.00},
		{ "971362485", 0.00},
		{ "793148625", 1.00},
		{ "123123456", 10.12},
		{ "456789321", 0.55},
};

/*
 * brief: get balance of the account with the number specified
 * param: (input) a pointer to the account number
 * return: (output) account balance if exists and -1 otherwise
 */
float getAccount(uint8_t* pu8_accountNumber){
	for(uint8_t index = 0; index < NUMBER_OF_ACCOUNTS; index++){
		if(!strcmp(pu8_accountNumber, database[index].primaryAccountNumber)){
			return database[index].balance;
		}
	}
	return -1;
}
