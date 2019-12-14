/*
 * Buyer.h
 *
 *  Created on: 23 Sep 2019
 *      Author: Stephen
 */

#ifndef BUYER_H_
#define BUYER_H_

#include "Trader.h"

class Buyer : public Trader{
public:
	Buyer(string traderName) : Trader(traderName, 'B'){}
	~Buyer(){}

};

#endif /* BUYER_H_ */
