#ifndef MYARRAY_H_INCLUDED
#define MYARRAY_H_INCLUDED

#include<iostream>

using namespace std;

template <class T>
class MyArray{

public:
	MyArray();
	MyArray(unsigned int );
	MyArray(unsigned int , const T& );
	MyArray(const MyArray<T>&);
	~MyArray();

	unsigned int getSize() const;
	unsigned int getCapacity() const;

	T& operator[](unsigned int );
	MyArray<T>& operator=(const MyArray<T>&);
	void resizeArray(unsigned int );
	void resizeArray(unsigned int , const T& );
	void addBack(const T& );
	void removeBack();
	void clearArray();
	bool ifEmpty() const;
	T getElementAt(unsigned int )const;
	void addElementAt(unsigned int, const T&);
	void removeElementAt(unsigned int );

private:
	unsigned int arraySize;
	unsigned int arrayCapacity;
	T* arrayData;
};
#endif // MYARRAY_H_INCLUDED
