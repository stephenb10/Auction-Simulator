/*
 * Simulator.cpp
 *
 *  Created on: 24 Sep 2019
 *      Author: stephenbyatt
 */

#include "Simulator.h"
using std::endl;

string horizontalLine() {
	string s = "";
	for (int i = 0; i < 60; i++)
		s += "-";
	return s;
}

int getNumberOfUnmatchedBids(const vector<Bid*> &bids, char type){
	int i =0;
	for(Bid* b : bids)
	{
		if(!b->isMatched() && b->getType() == type)
			i++;
	}
	return i;
}

Simulator::Simulator() {
	generateTraders();
	auctioneer = new Auctioneer(bids);
}

Simulator::~Simulator() {
	delete auctioneer;
}

extern int *NUMSELLER;
extern int *NUMBUYER;

void Simulator::generateTraders() {
	for (int i = 0; i < *NUMSELLER + *NUMBUYER; i++) {
		Trader *t;
		if (i < *NUMBUYER)
			t = new Buyer(names[i]);
		else
			t = new Seller(names[i]);

		traders.push_back(t);
		bids.push_back(t->generateBid());
	}
}

void Simulator::startAuction() {
	outputBids();
	auctioneer->runAuction();
	outputMatches();
}

void Simulator::outputBids() const {
	std::ofstream fout;

	fout.open("bids.txt");

	fout << "Double Auction Simulator" << endl << endl;

	fout << "Buy Bids" << endl << horizontalLine() << endl;

	for (Bid *b : bids) {
		if(b->getType() == 'B')
			fout << b->toString() << endl;
	}

	fout << "Sell Bids" << endl << horizontalLine() << endl;

	for (Bid *b : bids) {
			if(b->getType() == 'A')
				fout << b->toString() << endl;
		}
	fout.close();
}

void Simulator::outputMatches() const {
	std::ofstream fout;


	fout.open("bids.txt", std::ios_base::app);

	fout << "Matched Bids" << endl << horizontalLine() << endl;
	fout << auctioneer->getMatches()->size() << " matches" << endl << endl;

	for (Match *mb : *auctioneer->getMatches()) {
		fout << mb->toString() << endl << endl;
	}

	fout << "Unmatched Buy Bids" << endl << horizontalLine() << endl;
	fout << getNumberOfUnmatchedBids(bids, 'B') << " unmatched" << endl << endl;

		for (Bid *b : bids) {
			if(b->getType() == 'B' && !b->isMatched())
				fout << b->toString() << endl;
		}

	fout << "Unmatched Sell Bids" << endl << horizontalLine() << endl;
	fout << getNumberOfUnmatchedBids(bids, 'A') << " unmatched" << endl << endl;

		for (Bid *b : bids) {
				if(b->getType() == 'A' && !b->isMatched())
					fout << b->toString() << endl;
			}
	fout.close();

}

