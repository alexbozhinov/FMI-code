#ifndef JSONARRAY_H_INCLUDED
#define JSONARRAY_H_INCLUDED

#include"MyString.h"
#include "JSONObject.h"
#include<iostream>
#include<cstring>
#include <fstream>

using namespace std;

template <class T>
class JSONArray;

template<class T>
ostream& operator<< ( ostream& , const JSONArray<T>&  );

template<class T>
class JSONArray{
public:
    JSONArray();
    JSONArray(const JSONObject<T>& );
    JSONArray(const JSONArray& );
    ~JSONArray();
    JSONArray<T>& operator= (const JSONArray& );
    JSONObject<T>& operator[](unsigned int i);
    unsigned int getCapacity()const;
    unsigned int getSize()const;
    void addElement(const JSONObject<T>& );
    void addElement(MyString , T );
    void print()const;
    void removeElement(MyString );
    bool ifEmpty() const;
    T returnByKey(MyString );
    ///part Task4
    void writeInFile(const char* );
    friend ostream& operator<< <>(ostream& , const JSONArray<T>& );

private:
    JSONObject<T>* JArray;
    unsigned int arrayCapacity = 0;
    unsigned int arraySize = 0;
};

#endif // JSONARRAY_H_INCLUDED
