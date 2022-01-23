#ifndef RESTAURANT_H_INCLUDED
#define RESTAURANT_H_INCLUDED

#include<iostream>
#include "User.h"
#include "MyString.h"
#include "MyArray.h"
#include "MyArray.cpp"
#include "Ingredient.h"
#include "FoodItem.h"
#include "Salad.h"
#include "Soup.h"
#include "ChickenDish.h"
#include "Dessert.h"
#include "Menu.h"
#include "Cart.h"


using namespace std;

class Restaurant{
public:
    Restaurant();
    Restaurant(MyString, MyString, MyString, MyString, Menu, MyArray<User> );
    void printRestaurantData()const;
    Menu& getMenu();
    MyArray<User>& getUsers();
        MyArray<User> users;///


private:
    void setName(MyString );
    void setAddress(MyString );
    void setE_Mail(MyString );
    void setWebpage(MyString );
    void setMenu(Menu );
    void setUser(MyArray<User> );

    MyString name;
    MyString address;
    MyString e_mail;
    MyString webpage;
    Menu menu;///

};


#endif // RESTAURANT_H_INCLUDED
