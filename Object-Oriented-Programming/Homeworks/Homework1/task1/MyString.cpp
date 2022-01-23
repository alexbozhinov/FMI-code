#include<iostream>
#include "MyString.h"
#include<cstring>

using namespace std;


MyString::MyString(){
   length = 0;
   str = new char[0];
}

MyString::MyString(char symbol){
   length = 1;
   str = new char(symbol);
}

MyString::MyString(const char* _str){
   this->setLength(_str);
   this->setText(_str);
}

MyString::MyString(const MyString& other){
    this->length = other.getLength();
    this->str = new char[length];
    this->setText(other.getText());
    this->setLength(other.getText());
}

MyString::~MyString(){

   delete[] str;
}

MyString& MyString::operator= (const MyString& other){

    if(this == &other) return *this;

    delete str;
    length = other.getLength();
    str = new char[length];

    this->setText(other.getText());
    this->setLength(other.getText());
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

    } else{
        this -> str   = new char[0];
    }
}

void MyString::setLength(const char* _str){
   if (_str){
        int n = 0;
        while (_str[n] != '\0') n++;
        this->length = n;
    } else{
        length = 0;
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

void MyString::append(char symbol){
    int len = getLength();
    this->str[len] = symbol;
    this->str[len+1] = '\0';
    this->length++;
}

/*void MyString::read(){
    cout<<"Input your string: ";
    cin.getline(str, 1000, '\n');
}  */

void MyString::print()const{

cout<<"Your string: "<<this->str<<endl;
}

ostream& operator<< (ostream& out, const MyString& _str){
    if (_str.getLength() > 0){
         for (int i=0; i < _str.getLength(); i++)
             out << _str[i];
    } else
            out << "";
    return out;
}

/*
istream& operator>> (istream& in, MyString& _str)
{
    char* input = new char[1000];
    in >> input;
    _str = MyString(input);
    delete[] input;

    return in;
}
*/
