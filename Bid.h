/*
 * Bid.h
 *
 *  Created on: 23 Sep 2019
 *      Author: Stephen
 */

#ifndef BID_H_
#define BID_H_

#include <iomanip>
#include <sstream>
using std::string;

class Bid {
private:
	string traderName;
	int bidID;
	char bidType;
	double price;
	int quantity;
	bool matched;

public:

	Bid(string tName, char bType, double bPrice, int bQuantity);
	Bid(Bid *b, int q);

	string getName() const;
	int getID() const;
	char getType() const;
	double getPrice() const;
	void setQuantity(int x);
	int getQuantity() const;
	bool isMatched() const;
	void setMatched();

	string toString() const;
	static string priceToString(double p);
	static int count;

	bool operator <(Bid &b) const ;
	bool operator >(Bid &b) const ;
	bool operator ==(Bid &b) const ;

};

#endif /* BID_H_ */
