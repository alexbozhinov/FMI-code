#include<iostream>
#include "MyString.h"
#include<cstring>

using namespace std;

const int SIZE = 5000;
MyString::MyString(){
   length = 1;
   str = new char[1];
   str[0] = '\0';
}

MyString::MyString(char symbol){
   length = 2;
   str = new char(symbol);
   str[length-1] = '\0';
}

MyString::MyString(const char* _str){
   this->setLength(_str);
   this->setText(_str);
}

MyString::MyString(const MyString& other){
    this->length = other.getLength();
    this->str = new char[length+1];
    this->setText(other.getText());
    this->setLength(other.getText());
    this->str[length] = '\0';
}

MyString::~MyString(){

   delete[] str;
}

MyString& MyString::operator= (const MyString& other){

    if(this == &other) return *this;

    delete[] str;
    length = other.getLength();
    this->str = new char[length+1];
    this->setText(other.getText());
    this->setLength(other.getText());
    str[length] = '\0';
    return *this;
}

char MyString::operator[] (int i) const {
    if (i >= length) return 1;
    return str[i];
}

void MyString::setText(const char* _str){
   if (_str){
        int n = 0;
        while (_str[n] != '\0') n++;
        this -> str = new char[n];
        strcpy(this->str,_str);
        str[n] = '\0';

    } else{
        this -> str   = new char[1];
        str[0] = '\0';
    }
}

void MyString::setLength(const char* _str){
   if (_str){
        int n = 0;
        while (_str[n] != '\0') n++;
        this->length = n;
    } else{
        length = 1;
    }
}

int MyString::getLength()const{
   return this->length;
}

const char* MyString::getText()const{
   return this->str;
}

bool operator== (const MyString& leftSTR, const MyString& rightSTR){
    if (leftSTR.getLength() != rightSTR.getLength()) return false;

    int cap = leftSTR.getLength();
    int n = 0;
    while((n < cap) && (leftSTR[n] == rightSTR[n])){
        n++;
    }
    return (n==cap);
}

bool operator!= (const MyString& leftSTR, const MyString& rightSTR){
    return !(leftSTR == rightSTR);
}

bool operator> (const MyString& leftSTR, const MyString& rightSTR){
    int c;
    if(leftSTR.getLength()<rightSTR.getLength()) {
        c = leftSTR.getLength();
    }else{
        c = rightSTR.getLength();
    }
    int n = 0;
    while ((n < c) && (leftSTR[n] == rightSTR[n])){
        n++;
    }
    if (n == c) return (leftSTR.getLength() > rightSTR.getLength());

    if ( (('A'<=leftSTR[n]&&leftSTR[n]<='Z') || ('a'<=leftSTR[n]&&leftSTR[n]<='z')) &&
         (('A'<=rightSTR[n]&&rightSTR[n]<='Z') || ('a'<=rightSTR[n]&&rightSTR[n]<='z')) )
    {
        char symbolLeft = leftSTR[n];
        char symbolRight = rightSTR[n] ;
        if (symbolLeft != symbolRight) return (symbolLeft > symbolRight);
    }
    return leftSTR[n] > rightSTR[n];
}

bool operator< (const MyString& leftSTR, const MyString& rightSTR){
    return !(leftSTR == rightSTR) && !(leftSTR > rightSTR);
}

void MyString::append(char to_append)
{
    int len = strlen(this->str);
    char* new_content = new char[len + 2];
    strcpy(new_content, this->str);
    new_content[len] = to_append;
    new_content[len + 1] = '\0';
    delete[] this->str;
    this->str = new_content;
}

void MyString::print()const{

cout<<"Your string: "<<this->str<<endl;
}

ostream& operator<< (ostream& out, const MyString& _str) {
    if (strlen(_str.str) > 0) {
        for (int i=0; i < strlen(_str.str); i++)
            out << _str.str[i];
    } else
        out << "";
    return out;
}

istream& operator>> (istream& in, MyString& _str) {
    char* input = new char[SIZE];
    in.getline(input,SIZE-1,'\n');
    _str = MyString(input);
    _str.str[strlen(_str.str)] = '\0';
    delete[] input;

    return in;
}
