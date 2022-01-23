#ifndef JSONOBJECT_H_INCLUDED
#define JSONOBJECT_H_INCLUDED

#include"MyString.h"
#include<iostream>
#include<cstring>

using namespace std;

template <class T>
class JSONObject;

template<class T>
ostream& operator<< ( ostream& , const JSONObject<T>&  );

template <class T>
class JSONObject{

public:
    JSONObject();
    JSONObject(MyString, T);
    JSONObject(const JSONObject<T>& );
    JSONObject<T>& operator=(const JSONObject<T>& );
    MyString getKey()const;
    T getValue()const;
    void print()const;
    friend ostream& operator<< <>(ostream& , const JSONObject<T>& );

private:
    void setKey(MyString );
    void setValue(T );

    MyString key;
    T value;
};

#endif // JSONOBJECT_H_INCLUDED
