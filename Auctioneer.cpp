/*
 * Auctioneer.cpp
 *
 *  Created on: 23 Sep 2019
 *      Author: Stephen
 */

#include "Auctioneer.h"
using namespace std;
#include <iostream>
#include <algorithm>

Auctioneer::Auctioneer(vector<Bid*> &bids) {
	this->bids = &bids;
	for (Bid *b : bids) {
		if (b->getType() == 'B')
			buyBids.push_back(b);
		else
			sellBids.push_back(b);
	}

	sortVector(buyBids, false);
	sortVector(sellBids, true);

}

void Auctioneer::sortVector(vector<Bid*> &v, bool greater) const {
	if (greater) {
		sort(v.begin(), v.end(), [](Bid *lhs, Bid *rhs) {
			return lhs->getPrice() > rhs->getPrice();
		});
	} else
		sort(v.begin(), v.end(), [](Bid *lhs, Bid *rhs) {
			return lhs->getPrice() < rhs->getPrice();
		});
}

void Auctioneer::runAuction() {
	do {
		residualBids.clear();
		matchBids();
		sellBids = residualBids;
		sortVector(sellBids, true);
	} while (!residualBids.empty());

	sort(bids->begin(), bids->end(), [](Bid *lhs, Bid *rhs) {
				return lhs->getID() < rhs->getID();
			});

}

void Auctioneer::matchBids() {
	for (Bid *s : sellBids) {
		for (Bid *b : buyBids) {
			if (b->isMatched())
				continue;
			if (*b > *s) {
				if (*b == *s) {
					matchedBids.push_back(new Match(b, s));
					break;
				} else if (*b  < *s) {
					int residualQuantity = s->getQuantity() - b->getQuantity();

					s->setQuantity(s->getQuantity() - residualQuantity);
					matchedBids.push_back(new Match(b, s));

					Bid *residual = new Bid(s, residualQuantity);
					residualBids.push_back(residual);
					bids->push_back(residual);
					break;
				}
			}
		}
	}

}

vector<Match*>* Auctioneer::getMatches() {
	return &matchedBids;
}

