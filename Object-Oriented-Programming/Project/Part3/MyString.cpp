#include<iostream>
#include "MyString.h"
#include<cstring>

const int MAX_SIZE = 5000;

using namespace std;


MyString::MyString(){
   length = 0;
   str = new char[1];
   str[0] = '\0';
}

MyString::MyString(char symbol){
   length = 1;
   str = new char[2];
   str[0] = symbol;
   str[1] = '\0';
}

MyString::MyString(const char* _str){
   this->setLength(_str);
   this->setText(_str);
}

MyString::MyString(const MyString& other){
    this->length = other.getLength();
    this->str = new char[length+1];
    strcpy(this->str, other.str);
    this->str[length] = '\0';
}

MyString::~MyString(){

   delete[] str;
}

MyString& MyString::operator= (const MyString& other){

    if(this == &other) return *this;

    delete []str;
    length = other.getLength();
    str = new char[length+1];
    strcpy(this->str, other.str);
    str[length] = '\0';

    return *this;
}

MyString& MyString::operator=(const char* other)
    {
        if (this->length != 0 && this->str)
        {
            this->length = 0;
            delete[] this->str;
        }
        length = strlen(other);
        str = new char[length + 1];
for (int i=0; i < length; i++)
        str[i] = other[i];
        str[length] = '\0';
        return *this;
    }

char MyString::operator[] (int i) const {
    if (i >= length) return 1;
    return str[i];
}

void MyString::setText(const char* _str){
   if (_str){
        int len = strlen(_str);
        this -> str = new char[len+1];
        strcpy(this->str,_str);
        this->str[len] = '\0';

    } else{
        this -> str = new char[1];
        str[0] = '\0';
    }
}

void MyString::setLength(const char* _str){
   if (_str){
        int len = strlen(_str);
        this->length = len;
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

MyString& MyString::operator+= (const MyString& _str) {
    int len = length + _str.getLength();
    char* STR = new char[len+1];
    for (int i=0; i < length; i++)
          STR[i] = str[i];

    for (int i=0; i < _str.getLength(); i++)
        STR[length+i] = _str[i];
        STR[len] = '\0';
    delete[] str;
    length = len;
    str = STR;
    return *this;
}

MyString& MyString::operator+= (const char* _str) {
    int len = length + strlen(_str);
    char* STR = new char[len+1];
    for (int i=0; i < length; i++)
          STR[i] = str[i];

    for (int i=0; i < strlen(_str); i++)
        STR[length+i] = _str[i];
        STR[len] = '\0';
    delete[] str;
    length = len;
    str = STR;
    return *this;
}

MyString operator+ (const MyString& leftSTR, const MyString& rightSTR) {
    return MyString(leftSTR) += rightSTR;
}

MyString operator+ (const MyString& leftSTR, const char* rightSTR){
    return MyString(leftSTR) += MyString(rightSTR);
}

MyString operator+ (const char* leftSTR, const MyString& rightSTR) {
    return MyString(leftSTR) += rightSTR;
}

bool operator== (const MyString& leftSTR, const MyString& rightSTR){
    if (leftSTR.getLength() != rightSTR.getLength()) return false;

    int cap = leftSTR.getLength();
    int n = 0;
    while((n < cap) && (leftSTR[n] == rightSTR[n])){
        n++;
    }
    return (n == cap);
}

bool operator== (const MyString& leftSTR, const char* rightSTR) {
    return (leftSTR == MyString(rightSTR));
}

bool operator== (const char* leftSTR, const MyString& rightSTR) {
    return (MyString(leftSTR) == rightSTR);
}

bool operator!= (const MyString& leftSTR, const MyString& rightSTR){
    return !(leftSTR == rightSTR);
}

bool operator!= (const MyString& leftSTR, const char* rightSTR) {
    return !(leftSTR == rightSTR);
}

bool operator!= (const char* leftSTR, const MyString& rightSTR) {
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

bool operator> (const MyString& leftSTR, const char* rightSTR) {
    return (leftSTR > MyString(rightSTR));
}

bool operator> (const char* leftSTR, const MyString& rightSTR) {
    return (MyString(leftSTR) > rightSTR);
}

bool operator< (const MyString& leftSTR, const MyString& rightSTR){
    return !(leftSTR == rightSTR) && !(leftSTR > rightSTR);
}

bool operator< (const MyString& leftSTR, const char* rightSTR) {
    return !(leftSTR == rightSTR) && !(leftSTR > rightSTR);
}

bool operator< (const char* leftSTR, const MyString& rightSTR) {
    return !(leftSTR == rightSTR) && !(leftSTR > rightSTR);
}

void MyString::append(char symbol){
    int len = strlen(this->str);
    char* newStr = new char[len+2];
    strcpy(newStr, this->str);
    newStr[len] = symbol;
    newStr[len+1] = '\0';
    delete[] this->str;
    this->str = newStr;
}

bool MyString::ifEmpty() const{
    if(this->str)
    {
        if(this->length == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void MyString::print()const{

cout<<"Your string: "<<this->str<<endl;
}

ostream& operator<< (ostream& out, const MyString& _str) {
    if (_str.getLength() > 0) {
        for (int i=0; i < _str.getLength(); i++)
            out << _str[i];
    } else
        out << "";
    return out;
}

istream& operator>> (istream& in, MyString& _str) {
    char* input = new char[MAX_SIZE];
    in.getline(input,MAX_SIZE-1,'\n');
    _str = MyString(input);
    _str.str[_str.length] = '\0';
    delete[] input;

    return in;
}

const char* MyString::c_str() const {
     return this->str ;
}
