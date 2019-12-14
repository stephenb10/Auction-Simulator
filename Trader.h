/*
 * Trader.h
 *
 *  Created on: 23 Sep 2019
 *      Author: Stephen
 */

#ifndef TRADER_H_
#define TRADER_H_

#include "Bid.h"
#include <stdlib.h>

class Trader{
protected:
	string traderName;
	char traderType;

public:
	Trader(string traderName, char traderType);
	~Trader(){}
	Bid *generateBid() const;
};



#endif /* TRADER_H_ */
