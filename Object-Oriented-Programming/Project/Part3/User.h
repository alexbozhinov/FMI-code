#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include "MyString.h"
#include<iostream>

using namespace std;

class User{

public:
    User();
    User(MyString, MyString);

    MyString getUsername()const;
    bool checkUser(MyString, MyString)const;
    void printUser()const;
private:
    void setPassword(MyString );
    void setUsername(MyString );
    MyString username;
    MyString password;

};


#endif // USER_H_INCLUDED
