#ifndef INTCOUNTER_H_INCLUDED
#define INTCOUNTER_H_INCLUDED
#include<iostream>
using namespace std;


template <class T>
class IntCounter {
private:
	T* ptr;
	int* counter;

	void addReference();
	void removeReference();
	void freeMemory();

	void redirectPointers(T* newPtr, int* newCounter);
	void redirectPointers(const IntCounter<T>& rhs);

public:
	IntCounter();

	IntCounter(T* newPtr);
   	IntCounter(const IntCounter<T>& rhs);
	IntCounter<T>& operator=(const IntCounter<T>& rhs);
	~IntCounter();

	int get_count() const;
	int get_value() const;
};

#endif // INTCOUNTER_H_INCLUDED
