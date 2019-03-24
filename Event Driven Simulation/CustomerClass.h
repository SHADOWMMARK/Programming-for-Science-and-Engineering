#ifndef _CUSTOMER_CLASS_H_
#define _CUSTOMER_CLASS_H_
using namespace std;

class CustomerClass {
private:
	int customerID;
	int arrivalTime;
public:
	// constructor
	CustomerClass();
	CustomerClass(int ID, int arrival);
	// get customerID
	int getID() const;
	// record arrival time
	int getTime() const;
	// set customerID
	void setID(int ID);
	// set arrival time
	void setArrivalTime(int arrival);
};

ostream& operator<<(ostream &os, const CustomerClass &iObj);

#endif