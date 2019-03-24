#include "pch.h"
#include <iostream>
using namespace std;
#include "LinkedNodeClass.h"

//The ONLY constructor for the linked node class - it takes 
// in the newly created node's information and assigns.
template <class T>
LinkedNodeClass<T>::LinkedNodeClass(LinkedNodeClass<T> *inPrev, \
	const T &inVal, LinkedNodeClass<T> *inNext) {
	prevNode = inPrev;
	nodeVal = inVal;
	nextNode = inNext;
}

template <class T>
//Returns the value stored within this node.
T LinkedNodeClass<T>::getValue() const {
	return nodeVal;
}

template <class T>
//Returns the address of the node that follows this node.
LinkedNodeClass<T>* LinkedNodeClass<T>::getNext() const {
	return nextNode;
};

template <class T>
//Returns the address of the node that comes before this node.
LinkedNodeClass<T>* LinkedNodeClass<T>::getPrev() const {
	return prevNode;
}

template <class T>
//Sets the object¡¯s next node pointer to NULL.
void LinkedNodeClass<T>::setNextPointerToNull() {
	nextNode = 0;
}

template <class T>
//Sets the object's previous node pointer to NULL.
void LinkedNodeClass<T>::setPreviousPointerToNull() {
	prevNode = 0;
}

template <class T>
// change the previous and next nodes pointing to this node
// if "this" node is set up such that its prevNode
//pointer points to a node (call it "A"), and "this" node's
//nextNode pointer points to a node (call it "B"), then calling
//setBeforeAndAfterPointers results in the node we're calling
//"A" to be updated so its "nextNode" points to "this" node, and
//the node we're calling "B" is updated so its "prevNode" points
//to "this" node, but "this" node itself remains unchanged.
void LinkedNodeClass<T>::setBeforeAndAfterPointers() {
	if (prevNode != 0) {
		if (nextNode != 0) {
			// two nodes exist 
			// middle of the list
			prevNode->nextNode = this;
			nextNode->prevNode = this;
		}
		else {
			prevNode->nextNode = this;
		}
	}
	else {
		// prevNode == 0
		if (nextNode != 0) {
			nextNode->prevNode = this;
		}
	}
}