/*
 * Payment_System.h
 *
 *  Created on: Dec 28, 2021
 *      Author: Khaled Ali
 */

#ifndef PAYMENT_SYSTEM_H_
#define PAYMENT_SYSTEM_H_
#include <stdint.h>
#include "server.h"
#include "card.h"
#include "terminal.h"
#define MAX_TRANSACTION 5000

uint8_t verifyData(ST_cardData_t* pstr_cardInfo, ST_terminalData_t* pstr_terminalInfo);

#endif /* PAYMENT_SYSTEM_H_ */
