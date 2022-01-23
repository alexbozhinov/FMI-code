#include "JSONObject.h"
#include"MyString.h"
#include<iostream>
#include<cstring>

using namespace std;

template <class T>
JSONObject<T>::JSONObject(){
   key = "";
   value = NULL;
}

template<class T>
JSONObject<T>::JSONObject(MyString _key, T _value){
   this->setKey(_key);
   this->setValue(_value);
}

template<class T>
JSONObject<T>::JSONObject(const JSONObject<T>& other ){
    value = other.value;
	key = other.key;
}

template<class T>
void JSONObject<T>::setKey(MyString _key){
   this->key = _key;
}
template<class T>
void JSONObject<T>::setValue(T _value){
   this->value = _value;
}

template<class T>
MyString JSONObject<T>::getKey()const{
   return this->key;
}

template<class T>
T JSONObject<T>::getValue()const{
   return this->value;
}

template<class T>
JSONObject<T>& JSONObject<T>::operator=(const JSONObject<T>& other){
if (this != &other) {
		value = other.value;
		key = other.key;
	}
	return *this;
}

template<class T>
void JSONObject<T>::print()const{
   cout<<key<<" : "<<value<<endl;
}

template<class T>
ostream& operator<< (ostream& out, const JSONObject<T>& _JObject) {
            out << _JObject.key << " : " << _JObject.value <<"\n";
    return out;
}

