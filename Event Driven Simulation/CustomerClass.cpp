#include "pch.h"
#include <iostream>
using namespace std;
#include "CustomerClass.h"

CustomerClass::CustomerClass() {
}
CustomerClass::CustomerClass(int ID, int arrival) {
	customerID = ID;
	arrivalTime = arrival;
}
int CustomerClass::getID() const{
	return customerID;
}

int CustomerClass::getTime() const{
	return arrivalTime;
}

void CustomerClass::setID(int ID) {
	customerID = ID;
}

void CustomerClass::setArrivalTime(int arrival) {
	arrivalTime = arrival;
}

// operator overloading cout
ostream& operator<<(ostream &os, const CustomerClass &iObj) {
	os << " Customer ID: " << iObj.getID() << \
		" Arrival Time: " << iObj.getTime() << endl;
	return os;
}