#ifndef INTCOUNTER_H_INCLUDED
#define INTCOUNTER_H_INCLUDED

#include<iostream>
using namespace std;

class IntCounter{

   public:

       IntCounter();
       IntCounter(int* );
       ~IntCounter();
       IntCounter(const IntCounter& );
       IntCounter& operator=(const IntCounter& );
       int getCount()const;
       int* getData()const;
       void setData(int* );

   private:
       int* data;
       static int counter;
};

#endif // INTCOUNTER_H_INCLUDED
