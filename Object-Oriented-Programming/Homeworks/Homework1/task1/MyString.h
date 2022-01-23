#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED

#include<cstring>
#include<iostream>
using namespace std;

class MyString{

public:
    MyString();
    MyString(char );
    MyString(const char* );
    MyString(const MyString& );
    ~MyString();
    MyString& operator= (const MyString& );
    char  operator[] (int ) const;

    void setText(const char* );
    void setLength(const char* );

    int getLength()const;
    const char* getText()const;

    void append(char );

    void print()const;
    //void read();
    friend bool operator== (const MyString& , const MyString& );
    friend bool operator> (const MyString& , const MyString& );
    friend bool operator!= (const MyString& , const MyString& );
    friend bool operator< (const MyString& , const MyString& );
    friend ostream& operator<< (ostream& , const MyString& );
    //friend istream& operator>> (istream& , MyString& );

private:
   char* str;
   unsigned int length;
};





#endif // MYSTRING_H_INCLUDED
