/*
 * card.h
 *
 *  Created on: Dec 27, 2021
 *      Author: Khaled Ali
 */

#ifndef CARD_H_
#define CARD_H_

#include <stdint.h>

typedef struct
{	uint8_t cardHolderName[25];
	uint8_t primaryAccountNumber[20];
	uint8_t cardExpirationDate[6];
}ST_cardData_t;

void readCard(ST_cardData_t* pstr_cardInfo);

#endif /* CARD_H_ */
