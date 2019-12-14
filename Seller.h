/*
 * Seller.h
 *
 *  Created on: 23 Sep 2019
 *      Author: Stephen
 */

#ifndef SELLER_H_
#define SELLER_H_

#include "Trader.h"

class Seller : public Trader{
public:
	Seller(string traderName) :	Trader(traderName, 'A') {}
	~Seller(){}
};


#endif /* SELLER_H_ */
