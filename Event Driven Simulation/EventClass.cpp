#include "pch.h"
#include <iostream>
using namespace std;
#include "Constants.h"
#include "EventClass.h"

EventClass::EventClass() {
}

EventClass::EventClass(int endTime, int type, int id) {
	endTimeOfEvent = endTime;
	eventType = type;
	customerID = id;
}

int EventClass::getID() const{
	return customerID;
}

int EventClass::getType() const{
	return eventType;
}

int EventClass::getTime() const{
	return endTimeOfEvent;
}

void EventClass::setTime(int time) {
	endTimeOfEvent = time;
}

bool EventClass::operator<=(const EventClass compare) {
	// compare time directly
	// new arrival comes after previous complete
	// thus new arrival would be put behind
	if (endTimeOfEvent <= compare.endTimeOfEvent) {
		return true;
	}
	return false;
}

// operator overloading cout
ostream& operator<<(ostream &os, const EventClass &iObj) {
	os << " Cusomer ID: " << iObj.getID() << \
		" Happen Time: " << iObj.getTime() << " Event Type: ";
	if (iObj.getType() == ARRIVAL) {
		os << "Arrival" << endl;
	}
	else {
		os << "Complete" << endl;
	}
	return os;
}