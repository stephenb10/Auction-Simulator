/*
 * Auctioneer.h
 *
 *  Created on: 23 Sep 2019
 *      Author: Stephen
 */

#ifndef AUCTIONEER_H_
#define AUCTIONEER_H_

#include <vector>
#include "Match.h"
using std::vector;

class Auctioneer {
	vector<Bid*> *bids;
	vector<Bid*> buyBids;
	vector<Bid*> sellBids;
	vector<Bid*> residualBids;
	vector<Match*> matchedBids;
public:

	Auctioneer(vector<Bid*> &bids);
	~Auctioneer(){}
	void matchBids();
	void sortVector(vector<Bid*> &v, bool greater) const;
	void runAuction();
	vector<Match*> *getMatches();

};

#endif /* AUCTIONEER_H_ */
