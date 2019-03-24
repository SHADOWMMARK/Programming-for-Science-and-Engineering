#ifndef _EVENT_CLASS_H_
#define _EVENT_CLASS_H_
using namespace std;

class EventClass {
private:
	int endTimeOfEvent; // end of time 
	int eventType; // type of event arrival or complete
	int customerID; // ID of customer
public:
	EventClass(); // constructor
	EventClass(int endTime, int type, int id);
	int getID() const; // get ID
	int getType() const; // get event type
	int getTime() const; // get end time
	void setTime(int time); // set end time
	// operator overloading and compare time
	bool operator<=(const EventClass compare);

};

ostream& operator<<(ostream &os, const EventClass &iObj);
#endif