#include"JSONArray.h"
#include<iostream>
#include<cstring>
#include"MyString.h"
#include <fstream>

using namespace std;

template<class T>
JSONArray<T>::JSONArray(){
   	arraySize = 0;
	arrayCapacity = 0;
	JArray = NULL;
}

template<class T>
JSONArray<T>::JSONArray(const JSONObject<T>& value ){
  arraySize ++;
  arrayCapacity = arraySize;
  JArray = new JSONObject<T>[arraySize];
  for (int i = 0; i < arraySize; i++)
     JArray[i] = value;
}

template<class T>
JSONArray<T>::JSONArray(const JSONArray& other){
   	arraySize = other.arraySize;
	arrayCapacity = other.arraySize;
	JArray = new JSONObject<T>[arraySize];

	for (int i = 0; i < arraySize; i++)
		JArray[i] = other.JArray[i];
}

template<class T>
JSONArray<T>::~JSONArray(){
   delete[]JArray;
}

template<class T>
JSONArray<T>& JSONArray<T>::operator=(const JSONArray& other){
   	if (this != &other) {
		delete[] JArray;
		arraySize = other.arrSize;
		arrayCapacity = other.arrayCapacity;
		JArray = new JSONObject<T>[arraySize];

        for (int i = 0; i < arraySize; i++)
		    JArray[i] = other.JArray[i];
	}
	return *this;
}

template<class T>
JSONObject<T>& JSONArray<T>::operator[](unsigned int i) {
	if (i >= arraySize) {
		cout << "Error: Out of bounds!"<<endl;
	}
	return JArray[i];
}

template<class T>
unsigned int JSONArray<T>::getCapacity()const{
   return arrayCapacity;
}

template<class T>
unsigned int JSONArray<T>::getSize()const{
   return arraySize;
}

template<class T>
bool JSONArray<T>::ifEmpty()const{
   return arraySize==0;
}

template<class T>
void JSONArray<T>::addElement(const JSONObject<T>& newElement){
   	if (arraySize == arrayCapacity) {
		arrayCapacity += arrayCapacity / 2 + 1;
		JSONObject<T>* newArray = new JSONObject<T>[arrayCapacity];
		for (int i = 0; i < arraySize; i++)
			newArray[i] = JArray[i];
		delete[] JArray;
		JArray = newArray;
	}
	JArray[arraySize++] = newElement;
}

template<class T>
void JSONArray<T>::addElement(MyString newKey, T newValue){
    JSONObject<T> newElement(newKey, newValue);
   	if (arraySize == arrayCapacity) {
		arrayCapacity += arrayCapacity / 2 + 1;
		JSONObject<T>* newArray = new JSONObject<T>[arrayCapacity];
		for (int i = 0; i < arraySize; i++)
			newArray[i] = JArray[i];
		delete[] JArray;
		JArray = newArray;
	}
	JArray[arraySize++] = newElement;
}

template<class T>
void JSONArray<T>::print()const{
   //cout<<"Capacity: "<<getCapacity()<<endl;
   //cout<<"Size: "<<getSize()<<endl;
   cout<<"JSON array: ";
   cout<<"{ "<<endl;
   for(int i=0;i<arraySize;i++){
       cout<<JArray[i].getKey()<<" : "<<JArray[i].getValue()<<endl;
   }
   cout<<"}"<<endl;
   cout<<endl<<endl;
}

template<class T>
void JSONArray<T>::removeElement(MyString remKey){
    int errorCounter = 0;
   	for(int i=0;i<arraySize;i++){
        if(JArray[i].getKey()!= remKey){
                errorCounter++;
        }
   	}

   	if(errorCounter == arraySize) {
            cout<<"Error! You are trying to remove an inexistent key!"<<endl;
    }

   	int remIndex;

   	for(int i=0;i<arraySize;i++){
        if(JArray[i].getKey() == remKey) remIndex = i;
   	}

   	JSONObject<T> swapper = JArray[arraySize - 1];
   	JArray[arraySize - 1] = JArray[remIndex];
   	JArray[remIndex] = swapper;

     if(arraySize>0){
        arraySize--;
        if(arraySize==0){
            delete[]JArray;
            arrayCapacity = 0;
            arraySize = 0;
            JArray = NULL;
        }
     }
   int changeIndex = remIndex;
   for(int i=remIndex;i<arraySize-1;i++){
     swapper = JArray[changeIndex];
     JArray[changeIndex] = JArray[i+1];
     JArray[i+1] = swapper;
     changeIndex++;
   }

}

template<class T>
T JSONArray<T>::returnByKey(MyString retKey){
int errorCounter = 0;
for(int i=0;i<arraySize;i++){
    if(JArray[i].getKey()!=retKey) errorCounter++;
}

if(errorCounter == arraySize) {
    cout<<"Error! You are trying to get an inexistent object!"<<endl;
       return 0;
}

T valueToReturn;
for(int i=0;i<arraySize;i++){
    if(JArray[i].getKey()==retKey) valueToReturn = JArray[i].getValue();
}
return valueToReturn;
}

///part Task 4
template<class T>
ostream& operator<< (ostream& out, const JSONArray<T>& _array) {
    if ( _array.getSize()> 0) {
            out << "{ \n";
        for (int i=0; i < _array.getSize(); i++)
            out << _array.JArray[i];
            out <<"}\n";
    } else
        out << "";
    return out;
}

template<class T>
void JSONArray<T>::writeInFile(const char* filename){
ofstream myfile;
  myfile.open (filename, std::ofstream::out | std::ofstream::app);
  myfile << "{\n";
  for(int i=0;i<getSize();i++){
    myfile << JArray[i];
  }
  myfile << "}\n";
  myfile.close();
}

