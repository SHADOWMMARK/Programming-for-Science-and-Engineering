#ifndef _SIMULATION_CLASS_H_
#define _SIMULATION_CLASS_H_
using namespace std;

class SimulationClass {
private:
	SortedListClass<EventClass> eventList;
	FIFOQueueClass<CustomerClass> customerQueue;
	int closeTime;
	int uniformMin;
	int uniformMax;
	double normalMean;
	double normalStd;
	double  percentOfNotWait; // percentage of not waiting 
	int lengthOfNotWait; // max length of not waiting

	int clock;
	bool isServerFree;  // Server free or busy
	int totalNumOfCustomer;
	int numOfNotWait;
	int numOfCustomerWasInQueue;
	int totalServiceTime; 
	int lengthOfLongestLine; // length of the FIFOQueue
	int totalWaitingTime; 
	int longestWaitTime;

public:
	// constructor
    SimulationClass(int close, int min, int max, \
		double mean,double stdDev, double percent, int lengthLimit);

	// generate event for a customer at certain time
	// and add this event to event list
	void generateEvent(int type, int customerId);

	// get length of line
	int getQueueLength();

	// check if the customer wants to wait or not
	bool willCustomerWait();

	// handle the whole process
	void handleEvent();

	// print things
	void print();

};

#endif
