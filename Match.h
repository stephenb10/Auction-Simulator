/*
 * MatchBid.h
 *
 *  Created on: 23 Sep 2019
 *      Author: Stephen
 */

#ifndef MATCH_H_
#define MATCH_H_

#include "Bid.h"

class Match{
private:
	double clearingPrice;
	Bid *buyBid;
	Bid *sellBid;

public:
	Match(Bid* b, Bid* s);
	~Match(){}
	string toString() const;
};



#endif /* MATCH_H_ */
