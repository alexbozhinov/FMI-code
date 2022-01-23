#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED
#include<iostream>
using namespace std;

class MyString{
private:
    char* content;
public:
    MyString();
    MyString(const char* input);

    MyString(const MyString& from);

    MyString& operator=(const MyString& from);

    ~MyString();

    void append(char to_append);
    void print();


    friend ostream& operator<< (ostream& , const MyString& );
    friend istream& operator>> (istream& , MyString& );
};

#endif // MYSTRING_H_INCLUDED
