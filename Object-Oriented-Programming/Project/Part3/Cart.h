#ifndef CART_H_INCLUDED
#define CART_H_INCLUDED

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

class Cart{

public:
    Cart();
    Cart(MyArray<FoodItem> );
    MyArray<FoodItem>& getCart();
    void printCart()const;

private:
    void setCart(MyArray<FoodItem> );
    MyArray<FoodItem> cart;
};

#endif // CART_H_INCLUDED
