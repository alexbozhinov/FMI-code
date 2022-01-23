#include<iostream>
#include "MyArray.h"

using namespace std;

template<class T>
MyArray<T>::MyArray(){
   arrayCapacity = 0;
   arraySize = 0;
   arrayData = NULL;
}

template<class T>
MyArray<T>::MyArray(unsigned int number){
   arrayCapacity = number;
   arraySize = number;
   arrayData = new T[number];
}

template<class T>
MyArray<T>::MyArray(unsigned int number, const T& value){
   arrayCapacity = number;
   arraySize = number;
   arrayData = new T[number];
     for(int i=0; i<number; i++){
        arrayData[i] = value;
     }
}

template<class T>
MyArray<T>::~MyArray(){
   delete[] arrayData;
}

template<class T>
MyArray<T>::MyArray(const MyArray<T>& other){
   arrayCapacity = other.arraySize;
   arraySize = other.arraySize;
   arrayData = new T[arraySize];
   for(int i=0; i<arraySize; i++){
      arrayData[i] = other.arrayData[i];
   }
}

template<class T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T>& other){
   if (this != &other) {
		delete[] arrayData;
		arrayCapacity = other.arraySize;
		arraySize = other.arraySize;
		arrayData = new T[arraySize];
		for(int i=0; i<arraySize; i++){
            arrayData[i] = other.arrayData[i];
		}
	}
	return *this;
}

template<class T>
unsigned int MyArray<T>::getCapacity()const{
   return arrayCapacity;
}

template<class T>
unsigned int MyArray<T>::getSize()const{
   return arraySize;
}

template<class T>
T& MyArray<T>::operator[](unsigned int i){
   if (i >= arraySize) {
        cout << "Error: Out of bounds!"<<endl;
	}
	return arrayData[i];
}

template<class T>
void MyArray<T>::clearArray(){
   	delete[] arrayData;
	arrayCapacity = 0;
	arraySize = 0;
	arrayData = NULL;
}

template<class T>
void MyArray<T>::resizeArray(unsigned int number){
   if (number == 0) {
		clearArray();
	}
	else {
		if (number > arrayCapacity) {
			arrayCapacity = number;
			T* tempArrayData = new T[number];
			for (int i = 0; i < arraySize; i++)
				tempArrayData[i] = arrayData[i];
			delete[] arrayData;
			arrayData = tempArrayData;
		}
		arraySize = number;
	}
}

template<class T>
void MyArray<T>::resizeArray(unsigned int number, const T& value){
   	if (number == 0) {
		clearArray();
	}
	else {
		if (number > arrayCapacity) {
			arrayCapacity = number;
			T* tempArrayData = new T[number];
			for (int i = 0; i < arraySize; i++)
				tempArrayData[i] = arrayData[i];
			delete[] arrayData;
			arrayData = tempArrayData;
		}
		if (number > arraySize) {
			for (int i = arraySize; i < number; i++)
				arrayData[i] = value;
		}
		arraySize = number;
	}
}

template<class T>
bool MyArray<T>::ifEmpty()const{
   return arraySize == 0;
}

template<class T>
void MyArray<T>::addBack(const T& newElement){
   if (arraySize == arrayCapacity) {
		arrayCapacity += arrayCapacity / 2 + 1;
		T* tempArrayData = new T[arrayCapacity];
		for (int i = 0; i < arraySize; i++)
			tempArrayData[i] = arrayData[i];
		delete[] arrayData;
		arrayData = tempArrayData;
	}
	arrayData[arraySize++] = newElement;
}

template<class T>
void MyArray<T>::removeBack(){
   if (arraySize > 0) {
		arraySize--;
		if (arraySize == 0)
			clearArray();
	}
}

template<class T>
T MyArray<T>::getElementAt(unsigned int position)const{
   return arrayData[position-1];
}

template<class T>
void MyArray<T>::addElementAt(unsigned int position, const T& newElement){
		arrayCapacity += arrayCapacity / 2 + 1;
		T* tempArrayData = new T[arrayCapacity];
		for (int i = 0; i < position - 1; i++){
			tempArrayData[i] = arrayData[i];
		}
		tempArrayData[position - 1] = newElement;
		for(int i = position; i< arraySize + 1; i++){
            tempArrayData[i] = arrayData[i-1];
		}
		delete[] arrayData;
		arrayData = tempArrayData;
		arraySize = arraySize+1;
}

template<class T>
void MyArray<T>::removeElementAt(unsigned int position){
    int errorCounter = 0;
   	for(int i=0; i<arraySize; i++){
        if(i+1!= position){
                errorCounter++;
        }
   	}

   	if(errorCounter == arraySize) {
            cout<<"Error! You are trying to remove an inexistent key!"<<endl;
    }
    else{

   ///	int remIndex; position


   	T swapper = arrayData[arraySize - 1];
   	arrayData[arraySize - 1] = arrayData[position - 1];
   	arrayData[position - 1] = swapper;

     if(arraySize > 0){
        arraySize--;
        if(arraySize == 0){
           clearArray();
        }
     }
   int changeIndex = position - 1;
   for(int i = position - 1;i < arraySize - 1; i++){
     swapper = arrayData[changeIndex];
     arrayData[changeIndex] = arrayData[i+1];
     arrayData[i+1] = swapper;
     changeIndex++;
   }
}
}

























