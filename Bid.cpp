/*
 * Bid.cpp
 *
 *  Created on: 23 Sep 2019
 *      Author: Stephen
 */

#include "Bid.h"

int Bid::count = 1;

bool Bid::operator ==(Bid &b) const{
	return quantity == b.getQuantity();
}
bool Bid::operator <(Bid &b) const {
	return quantity < b.getQuantity();
}
bool Bid::operator >(Bid &b) const {
	return price > b.getPrice();
}

string Bid::priceToString(double p) {
	std::ostringstream streamObj;
	streamObj << std::fixed << std::setprecision(2) << p;

	string s = streamObj.str();

	return "$" + s;
}

Bid::Bid(string tName, char bType, double bPrice, int bQuantity) {
	traderName = tName;
	bidType = bType;
	price = bPrice;
	quantity = bQuantity;
	bidID = count;
	matched = false;
	count++;
}

Bid::Bid(Bid *b, int q) {
	if (b->getName().find("Residual") != std::string::npos)
		traderName = b->getName();
	else
		traderName = b->getName() + " Residual";

	bidID = b->getID();
	bidType = b->getType();
	price = b->getPrice();
	matched = false;
	quantity = q;
}

string Bid::getName() const {
	return traderName;
}

int Bid::getID() const {
	return bidID;
}

char Bid::getType() const{
	return bidType;
}

double Bid::getPrice() const {
	return price;
}

void Bid::setMatched() {
	matched = true;
}

bool Bid::isMatched() const {
	return matched;
}

int Bid::getQuantity() const {
	return quantity;
}

void Bid::setQuantity(int x) {
	quantity = x;
}

string Bid::toString() const {
	string s = "";
	s += traderName + " Bid " + std::to_string(bidID);
	s += "\nType ";
	s += bidType;
	s += "\n" + Bid::priceToString(price);
	s += "\nx" + std::to_string(quantity) + "\n";
	return s;
}

