#include "intCounter.h"
#include<iostream>
using namespace std;

template <class T>
IntCounter<T>::IntCounter(){
ptr = NULL;
counter = new int(0);
}

template <class T>
void IntCounter<T>::addReference() {
	*(this->counter) += 1;
}

template <class T>
void IntCounter<T>::removeReference() {
	*(this->counter) -= 1;
}

template <class T>
void IntCounter<T>::freeMemory() {
	delete this->ptr;
	delete this->counter;
}

template <class T>
void IntCounter<T>::redirectPointers(T* newPtr, int* newCounter) {
	this->ptr = newPtr;
	this->counter = newCounter;
}

template <class T>
void IntCounter<T>::redirectPointers(const IntCounter<T>& rhs) {
	this->redirectPointers(rhs.ptr, rhs.counter);
}

template <class T>
IntCounter<T>::IntCounter(T* newPtr) {
	this->redirectPointers(newPtr, new int(1));
	// this->ptr = ptr;
	// this->counter = new int(1);
}

template<class T>
IntCounter<T>::IntCounter(const IntCounter<T>& rhs) {
	this->redirectPointers(rhs);
	this->addReference();
}

template<class T>
IntCounter<T>& IntCounter<T>::operator=(const IntCounter<T>& rhs) {
	// Two objects are the same if they have the same pointer int* ptr,
	// which is different from the usual check in operator=
	if (this->ptr != rhs.ptr) {
    	// Remove reference from the old pointer and check if deletion is due
    	this->removeReference();
    	if (this->get_count() == 0) {
        	this->freeMemory();
    	}

    	// Point the variables to the new pointer and add a reference
    	this->redirectPointers(rhs);
    	this->addReference();
}
	return *this;
}

template<class T>
IntCounter<T>::~IntCounter() {
	this->removeReference();
	if (this->get_count() == 0) {
    	this->freeMemory();
	}
}

template<class T>
int IntCounter<T>::get_count() const {
	return *this->counter;
}

template<class T>
int IntCounter<T>::get_value() const {
	return *this->ptr;
}
