#include<iostream>
#include<cstring>
#include "MyString.h"

const int SIZE = 5000;

using namespace std;

MyString::MyString()
{
    content = new char[1];
    content[0] = '\0';
}

MyString::MyString(const char* input)
{
    int len = strlen(input);
    this->content = new char[len + 1];

    strcpy(this->content, input);
    this->content[len] = '\0';
}
MyString::MyString(const MyString& from)
{
    int len = strlen(from.content);
    this->content = new char[len + 1];
    strcpy(this->content, from.content);
    this->content[len] = '\0';
}

MyString& MyString::operator=(const MyString& from)
{
    if(this != &from)
    {
   	 delete[] content;

   	 int len = strlen(from.content);
   	 this->content = new char[len + 1];
   	 strcpy(this->content, from.content);
   	 this->content[len] = '\0';
    }
    return *this;
}

MyString::~MyString()
{
    delete[] this->content;
}

void MyString::append(char to_append)
{
    int len = strlen(this->content);
    char* new_content = new char[len + 2];
    strcpy(new_content, this->content);
    new_content[len] = to_append;
    new_content[len + 1] = '\0';
    delete[] this->content;
    this->content = new_content;
}

void MyString::print()
{
    std::cout << this->content << std::endl;
}

ostream& operator<< (ostream& out, const MyString& _str) {
    if (strlen(_str.content) > 0) {
        for (int i=0; i < strlen(_str.content); i++)
            out << _str.content[i];
    } else
        out << "";
    return out;
}

istream& operator>> (istream& in, MyString& _str) {
    char* input = new char[SIZE];
    in.getline(input,SIZE-1,'\n');
    _str = MyString(input);
    _str.content[strlen(_str.content)] = '\0';
    delete[] input;

    return in;
}

