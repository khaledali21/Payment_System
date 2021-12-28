/*
 * card.c
 *
 *  Created on: Dec 27, 2021
 *      Author: Khaled Ali
 */

#include <stdio.h>
#include <stdint.h>
#include "card.h"



/*
 * brief: Read card info from the client
 * param: (input) a pointer to a structure containing card info
 */
void readCard(ST_cardData_t* pstr_cardInfo){
	printf("Please Enter the Card Holder Name: \n"); fflush(stdout);
	gets(pstr_cardInfo -> cardHolderName);
	printf("Please Enter the Primary Account Number: \n");fflush(stdout);
	gets(pstr_cardInfo -> primaryAccountNumber);
	printf("Please Enter the card's Expire Date: \n");fflush(stdout);
	gets(pstr_cardInfo -> cardExpirationDate);
}
