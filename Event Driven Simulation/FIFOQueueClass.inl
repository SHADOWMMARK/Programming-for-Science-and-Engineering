#include "pch.h"
#include <iostream>
using namespace std;
#include "LinkedNodeClass.h"
#include "FIFOQueueClass.h"

template <class DT>
//Default Constructor. Will properly initialize a queue to
//be an empty queue, to which values can be added.
FIFOQueueClass<DT>::FIFOQueueClass() {
    head = 0;
    tail = 0;
}

template <class DT>
//Clears the stack to an empty state without resulting in any
//memory leaks.
void FIFOQueueClass<DT>::clear() {
    LinkedNodeClass<DT>* toDeletePtr = head;
    LinkedNodeClass<DT>* currentPtr = head;
    // delete dynamic allocation nodes one by one
    while (currentPtr != 0) {
        currentPtr = currentPtr->getNext();
        delete toDeletePtr;
        toDeletePtr = currentPtr;
    }
    head = 0;
    tail = 0;
}

//Destructor. Responsible for making sure any dynamic memory
//associated with an object is freed up when the object is
//being destroyed.
template <class DT>
FIFOQueueClass<DT>::~FIFOQueueClass() {
    clear();
}

//Prints out the contents of the stack. All printing is done
//on one line, using a single space to separate values, and a
//single newline character is printed at the end.

// a queue should print out the first thing that was inserted first

template <class DT>
void FIFOQueueClass<DT>::print() const {
	LinkedNodeClass<DT>* printPtr = tail;
	while (printPtr != 0) {
		cout << printPtr->getValue();
		// cout << " ";
		printPtr = printPtr->getPrev();
	}
	cout << endl;
}

template <class DT>
//Returns the number of nodes contained in the stack.
int FIFOQueueClass<DT>::getNumElems() const {
    int countNumber = 0;
    LinkedNodeClass<DT>* countPtr = head;
    while (countPtr != 0) {
        countNumber = countNumber + 1;
        countPtr = countPtr->getNext();
    }
    return countNumber;
}

template <class DT>
//Inserts the value provided (newItem) into the queue.
void FIFOQueueClass<DT>::enqueue(const DT &newItem) {
    // put the new node in the head position
    LinkedNodeClass<DT>* insertStackPtr;
    if (head == 0) {
        insertStackPtr = new LinkedNodeClass<DT>(0, newItem, 0);
        // head and tail point to this node
        // the only node in this list
        head = insertStackPtr;
        tail = insertStackPtr;
    }
    else {
        // insert at the first position
        insertStackPtr = new LinkedNodeClass<DT>(0, newItem, head);
        insertStackPtr->setBeforeAndAfterPointers();
        // update head and tail
        head = insertStackPtr;
    }
}

template <class DT>
//Attempts to take the next item out of the queue. If the
//queue is empty, the function returns false and the state
//of the reference parameter (outItem) is undefined. If the
//queue is not empty, the function returns true and outItem
//becomes a copy of the next item in the queue, which is
//removed from the data structure.
bool FIFOQueueClass<DT>::dequeue(DT &outItem) {
    if (getNumElems() == 0) {
        // list is empty
        head = 0;
        tail = 0;
        return false;
    }
    else if (getNumElems() == 1) {
        // only one element here
        LinkedNodeClass<DT>* temp;
        temp = head;
        outItem = temp->getValue();
        delete temp;
        temp = 0;
        // initialize
        head = 0;
        tail = 0;
        return true;
    }
    else {
        // list is not empty then remove the head and more than one
        outItem = tail->getValue();
        // delete the pointer and first dynamic allocation node
        tail = tail->getPrev();
        delete tail->getNext();
        tail->setNextPointerToNull();
        return true;
    }
}



