#ifndef ONLINEORDER_H_INCLUDED
#define ONLINEORDER_H_INCLUDED

#include<iostream>
#include<fstream>
#include<cstdio>
#include "MyString.h"
#include "MyArray.h"
#include<stdlib.h>
//#include "MyArray.cpp"
#include "Ingredient.h"
#include "User.h"
#include "Ingredient.h"
#include "FoodItem.h"
#include "Salad.h"
#include "Menu.h"
#include "Restaurant.h"
//#include "USER_MENU.h"
//#include "ADMIN_MENU.h"
//#include "CLIENT_MENU.h"
#include "Cart.h"

class OnlineOrder{

public:
    OnlineOrder();
    OnlineOrder(Cart);
    Cart& getOnlineOrder();
    double getFullSum()const;
    void printOnlineOrder()const;
private:
    void setItemsToBuy(Cart );
    void setFullSum( );
    Cart itemsToBuy;
    double fullSum;
};

#endif // ONLINEORDER_H_INCLUDED
