#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include<iostream>
#include<string>
#include<vector>
#include "Cart.h"
#include "OnlineOrder.h"


using namespace std;

class User{

public:
   User();
   User(string, string);

   string getUsername()const;
   bool checkUser(string, string)const;
   Cart& getCart();
   vector<OnlineOrder>& getOrders();

private:
    void setUsername(string );
    void setPassword(string );

    string username;
    string password;
    Cart cart;
    vector<OnlineOrder> orders;
};


#endif // USER_H_INCLUDED
