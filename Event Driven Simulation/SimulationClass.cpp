#include "pch.h"
#include <iostream>
using namespace std;
#include "random.h"
#include "Constants.h"
#include "LinkedNodeClass.h"
#include "EventClass.h"
#include "CustomerClass.h"
#include "FIFOQueueClass.h"
#include "SortedListClass.h"
#include "SimulationClass.h"

SimulationClass::SimulationClass(int close, int min, int max, \
    double mean, double stdDev, double percent, int lengthLimit){
    closeTime = close;
    uniformMin = min;
    uniformMax = max;
    normalMean = mean;
    normalStd = stdDev;
    percentOfNotWait = percent;
    lengthOfNotWait = lengthLimit;

    clock = INITIAL_TIME;
    isServerFree = true;

    // customer information
    totalNumOfCustomer = INITIAL_SUM_NUMBER;
    numOfNotWait = INITIAL_SUM_NUMBER;
    numOfCustomerWasInQueue = INITIAL_SUM_NUMBER;

    // other statistical information
    totalServiceTime = INITIAL_SUM_NUMBER;
    totalWaitingTime = INITIAL_SUM_NUMBER;
    lengthOfLongestLine = INITIAL_SUM_NUMBER;
    longestWaitTime = INITIAL_SUM_NUMBER;

    // event list initialization
    eventList.insertValue(EventClass(INITIAL_TIME, ARRIVAL, INITIAL_ID + 1));
}

int SimulationClass::getQueueLength() {
    return customerQueue.getNumElems();
}

// generate event for a customer at certain time
// and add this event to event list
void SimulationClass::generateEvent(int type, int customerId) {
    int DeltaTime;
    int eventTime;
    if (type == ARRIVAL) {
        // arrival event
        DeltaTime = getUniform(uniformMin, uniformMax);
        eventTime = clock + DeltaTime;
        eventList.insertValue(EventClass(eventTime, ARRIVAL, customerId));
    }
    else {
        // complete event
        DeltaTime = getNormal(normalMean, normalStd);
        // record every service time
        // recent percentage -- total service time/closing time
        totalServiceTime = totalServiceTime + DeltaTime;
        eventTime = clock + DeltaTime;
        eventList.insertValue(EventClass(eventTime, COMPLETE, customerId));
    }
}

// check if the customer wants to wait or not
bool SimulationClass::willCustomerWait() {
    int randomNum = getUniform(PROB_GENERATE_MIN, PROB_GENERATE_MAX);
    // within that percent range
    if (randomNum <= (percentOfNotWait * PROB_GENERATE_MAX)) {
        // length of queue is too long
        if (getQueueLength() > lengthOfNotWait) {
            return false;
        }
        return true;
    }
    return true;
}

// handle the whole process
void SimulationClass::handleEvent() {

    while ((eventList.getNumElems() != 0)) {
        // handle eventlist
        EventClass currentEvent;
        // take the earliest event from event list
        eventList.removeFront(currentEvent);

        clock = currentEvent.getTime();
        // print out over closing time here
        // report what happens here
        // event time report according to time 
        cout << "At time " << clock << endl;
        // customer ID report
        cout << " Customer " << currentEvent.getID();
        // event type report
        if (currentEvent.getType() == ARRIVAL) {
            cout << " Arrives" << endl;
        }
        else {
            cout << " Completes and leaves" << endl;
        }

        if (currentEvent.getType() == ARRIVAL) {
            // record total number of customers
            totalNumOfCustomer += 1;
            // arrival event type
            if (isServerFree) {
                // free server then schedule complete event
                isServerFree = false;
                generateEvent(COMPLETE, currentEvent.getID());
            }
            else {
                // check before put into FIFOqueue
                int tempID = currentEvent.getID();
                if (willCustomerWait()) {
                    // customer would wait and put him into FIFOqueue
                    // clock time is the arrival time
                    customerQueue.enqueue(CustomerClass(tempID, clock));

                    // report the customer put into the queue
                    cout << " Customer " << tempID << \
                        " was put into the waiting line" << endl;

                    // Percent that customer had to wait inline
                    numOfCustomerWasInQueue += 1;
                    if (customerQueue.getNumElems() > lengthOfLongestLine) {
                        // Longest line -- count the number of customers
                        lengthOfLongestLine = customerQueue.getNumElems();
                    }
                }
                else {
                    // customer won't wait and let him go
                    // Number of customers arrived but not served
                    numOfNotWait += 1;
                    // report not waiting customer information
                    cout << " Customer " << tempID;
                    cout << " Leaves without being served" << endl;
                }
                cout << " Total number of customer in waiting line now is: ";
                cout << customerQueue.getNumElems() << endl;
                cout << " Waiting line details:" << endl;
                customerQueue.print();

            }
            // generate a new customer after handling previous one
            // check whether its arrival time is before closing time
            int tryTime = getUniform(uniformMin, uniformMax) + clock;
            if (tryTime < closeTime) {
                eventList.insertValue(EventClass(tryTime, \
                    ARRIVAL, totalNumOfCustomer+1));
            }
        }
        else {
            // complete event type
            isServerFree = true;
            // FIFOqueue not empty
            if (customerQueue.getNumElems() != 0) {
                // take the first customer
                CustomerClass currentCustomer;
                customerQueue.dequeue(currentCustomer);

                // report current customer's state
                cout << " Customer " << currentCustomer.getID();
                cout << " has been taken from the waiting line";
                cout << "and starts being served" << endl;

                int tempWaitingTime = clock - currentCustomer.getTime();
                if (tempWaitingTime > longestWaitTime) {
                    longestWaitTime = tempWaitingTime;
                }
                cout << " This customer has been waiting for ";
                cout << tempWaitingTime << " unit time" << endl;
                cout << " Total number of customers in waiting line now is: ";
                cout << customerQueue.getNumElems() << endl;
                cout << " Waiting line details:" << endl;
                customerQueue.print();

                totalWaitingTime = totalWaitingTime + tempWaitingTime;
                generateEvent(COMPLETE, currentCustomer.getID());
                isServerFree = false;
            }
        }
        cout << endl;
    }
}

void SimulationClass::print() {
    // customer information output
    cout << endl;
    cout << "Total Number of customers that showed up: ";
    cout << totalNumOfCustomer << endl;
    cout << "Number of customers left due to excessive line length: ";
    cout << numOfNotWait << endl;
    cout << "The longest the line was throughout the simulation: ";
    cout << lengthOfLongestLine << endl;
    cout << "Number of customers used to stay in the queue: ";
    cout << numOfCustomerWasInQueue << endl;

    cout << "Percentage of customers had to wait in line: ";
    int numOfServedPeople = totalNumOfCustomer - numOfNotWait;
    double percentOfCustomersWaitInLine;
    percentOfCustomersWaitInLine = ONE_HUNDRED_PERCENT * \
        double(numOfCustomerWasInQueue) / double(numOfServedPeople);
    cout << percentOfCustomersWaitInLine << "%" << endl;

    // time information
    double percentOfBusyTime;
    percentOfBusyTime = ONE_HUNDRED_PERCENT * \
        double(totalServiceTime) / double(clock);
    cout << "Percentage of time the server was busy helping customers: ";
    cout << percentOfBusyTime << "%" << endl;

    // total waiting time of all the customers
    cout << "Total waiting Time: ";
    cout << totalWaitingTime << endl;

    // average waiting time of customers in waiting line
    cout << "Average waiting Time: ";
    double averageWaitTime = \
        double(totalWaitingTime) / double(numOfCustomerWasInQueue);
    if (numOfCustomerWasInQueue == INITIAL_SUM_NUMBER) {
        cout << INITIAL_SUM_NUMBER << endl;
    }
    else {
        cout << averageWaitTime << endl;
    }

    // longest waiting time
    cout << "The longest waiting Time: ";
    cout << longestWaitTime << endl;

    // Total serving time after closing
    if (clock - closeTime > 0) {
        cout << "Extra Serving Time: ";
        cout << clock - closeTime << endl;
    }
    else {
        cout << "No extra serving time and ";
        cout << (closeTime - clock) <<\
            " unit time left before closing" << endl;
    }

}