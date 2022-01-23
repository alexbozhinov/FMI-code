#include "User.h"
#include<iostream>
#include<cstring>

using namespace std;

User::User() = default;
User::User(const char* _username, const char* _password){

    this->setUsername(_username);
    this->setPassword(_password);
}

void User::setAllU(const char* _username, const char* _password){

   strcpy(this->username, _username);
   strcpy(this->password, _password);
}

void User::setUsername(const char* _username){
   strcpy(this->username, _username);
}

void User::setPassword(const char* _password){
   strcpy(this->password, _password);
}

void User::printClient()const{

   cout<<"Client username: "<<this->username<<endl;
   cout<<endl;
}
