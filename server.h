/*
 * server.h
 *
 *  Created on: Dec 27, 2021
 *      Author: Khaled Ali
 */

#ifndef SERVER_H_
#define SERVER_H_
#include <stdint.h>

typedef struct
{
	uint8_t primaryAccountNumber[20];
	float balance;
} ST_accountBalance_t;

#define NUMBER_OF_ACCOUNTS 10
#define NOT_FOUND -1

float getAccount(uint8_t* pu8_accountNumber);

#endif /* SERVER_H_ */
