/*
 * Simulator.h
 *
 *  Created on: 24 Sep 2019
 *      Author: stephenbyatt
 */

#ifndef SIMULATOR_H_
#define SIMULATOR_H_

#include "Auctioneer.h"
#include "Buyer.h"
#include "Seller.h"

#include <vector>
#include <fstream>

class Simulator {
	Auctioneer *auctioneer;
	vector<Trader*> traders;
	vector<Bid*> bids;

	string names[20] = { "Noah", "William", "James", "Logan", "Benjamin",
			"Mason", "Elijah", "Oliver", "Jacob", "Lucas", "Michael",
			"Alexander", "Ethan", "Daniel", "Matthew", "Aiden", "Henry",
			"Joseph", "Jackson", "Samuel" };

public:
	Simulator();
	~Simulator();
	void startAuction();
	void generateTraders();
	void outputBids() const;
	void outputMatches() const;

};

#endif /* SIMULATOR_H_ */
