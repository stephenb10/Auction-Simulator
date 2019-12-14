/*
 * MatchBids.cpp
 *
 *  Created on: 23 Sep 2019
 *      Author: Stephen
 */

#include "Match.h"

string addTabToString(string s) {
	int spaceBetween = 10;
	int firstCol = 20;
	string st = s;
	int spaceLeft = firstCol - s.size() + spaceBetween;
	for (int i = 0; i < spaceLeft; i++) {
		st += " ";
	}

	return st;
}

Match::Match(Bid *b, Bid *s) :
		buyBid(b), sellBid(s) {
	b->setMatched();
	s->setMatched();
	clearingPrice = (b->getPrice() + s->getPrice()) / 2;
}

string Match::toString() const {
	string s = "";
	// Name
	s += addTabToString(
			buyBid->getName() + " Bid " + std::to_string(buyBid->getID()));
	s += sellBid->getName() + " Bid " + std::to_string(sellBid->getID()) + "\n";

	// Type
	s += addTabToString("Type B");
	s += "Type A\n";

	// Price
	s += addTabToString(Bid::priceToString(buyBid->getPrice()));
	s += Bid::priceToString(sellBid->getPrice()) + "\n";

	// Quantity
	s += addTabToString("x" + std::to_string(buyBid->getQuantity()));
	s += "x" + std::to_string(sellBid->getQuantity()) + "\n";

	// Clearing Price
	s += "Clearing Price " + Bid::priceToString(clearingPrice);

	return s;
}
