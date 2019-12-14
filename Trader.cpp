/*
 * Trader.cpp
 *
 *  Created on: 23 Sep 2019
 *      Author: Stephen
 */

#include "Trader.h"
#include <math.h>

Trader::Trader(string traderName, char traderType){
	this->traderName = traderName;
	this->traderType = traderType;
}

extern double *MINPRICE;
extern double *MAXPRICE;
extern int *MINQUANTITY;
extern int *MAXQUANTITY;

Bid* Trader::generateBid() const {
	double rPrice = (*MAXPRICE - *MINPRICE) * ( (double)rand() / (double)RAND_MAX ) + *MINPRICE;
	int rQuantity = rand() % *MAXQUANTITY + *MINQUANTITY;

	Bid *bid = new Bid(traderName, traderType, rPrice, rQuantity);

	return bid;
}





