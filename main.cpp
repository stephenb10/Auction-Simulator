/*
 * I hereby certify that no part of this assignment has been copied from any other student’s work or
 * from any other source. No part of the code has been written/produced for me by another person
 * or copied from any other source.
 * I hold a copy of this assignment that I can produce if the original is lost or damaged.
 */


const int numseller = 10;
const int *NUMSELLER = &numseller;

const int numbyer = 10;
const int *NUMBUYER = &numbyer;

const double minprice = 50;
const double *MINPRICE = &minprice;

const double maxprice = 150;
const double *MAXPRICE = &maxprice;

const int minquantity = 1;
const int *MINQUANTITY = &minquantity;

const int maxquantity = 50;
const int *MAXQUANTITY = &maxquantity;

#include "Simulator.h"
#include <time.h>


int main() {
	srand(time(NULL));

	Simulator sim;
	sim.startAuction();


	return 0;
}
