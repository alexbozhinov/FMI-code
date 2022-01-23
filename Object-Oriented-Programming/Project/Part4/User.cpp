#include<iostream>
#include<string>
#include<vector>
#include "User.h"

using namespace std;

User::User(){
username = "";
password = "";
}

User::User(string _username, string _password){
   this->setUsername(_username);
   this->setPassword(_password);
}

void User::setUsername(string _username){
   this->username = _username;
}

void User::setPassword(string _password){
   this->password = _password;
}

string User::getUsername()const{
   return this->username;
}

bool User::checkUser(string _username, string _password)const{
   if(_username == username && _password == password) return true;
   else return false;
}

Cart& User::getCart(){
   return this->cart;
}

vector<OnlineOrder>& User::getOrders(){
   return this->orders;
}
