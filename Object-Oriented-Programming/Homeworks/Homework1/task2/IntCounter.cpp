#include<iostream>
#include "IntCounter.h"

using namespace std;

int IntCounter::counter = 0;

IntCounter::IntCounter(){
   counter = 0;
   data = new int(0);
}

IntCounter::IntCounter(int* _data){
   this->counter = 1;
   this->setData(_data);
}

void IntCounter::setData(int* _data){
   this->data = _data;
}

int IntCounter::getCount()const{
   return this->counter;
}

int* IntCounter::getData()const{
   return this->data;
}

IntCounter::~IntCounter(){
  counter--;
    if(counter==0){
       delete data;
    }
}

IntCounter::IntCounter(const IntCounter& other){
   this->counter = other.getCount();
   other.counter++;
   this->setData(other.getData());
}

IntCounter& IntCounter::operator=(const IntCounter& other){
      if(this == &other) {return *this;}
      delete data;
      counter = other.getCount();
      data = new int;
      this->setData(other.getData());
      this->counter = other.getCount();
    return *this;
}
