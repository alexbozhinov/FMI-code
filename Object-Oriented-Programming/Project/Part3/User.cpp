#include<iostream>
#include "MyString.h"
#include "User.h"

using namespace std;

User::User(){
username = "";
password = "";
}

User::User(MyString _username, MyString _password){
   this->setUsername(_username);
   this->setPassword(_password);
}

void User::setUsername(MyString _username){
   this->username = _username;
}

void User::setPassword(MyString _password){
   this->password = _password;
}

MyString User::getUsername()const{
   return this->username;
}

void User::printUser()const{
   cout<<"Username: "<<username<<endl;
}

bool User::checkUser(MyString _username, MyString _password)const{
   if(_username == username && _password == password) return true;
   else return false;
}
