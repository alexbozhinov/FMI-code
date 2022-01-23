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

using namespace std;

Cart::Cart(){
   cart = NULL;
}

Cart::Cart(MyArray<FoodItem> _cart){
   this->setCart(_cart);
}

void Cart::setCart(MyArray<FoodItem> _cart){
   this->cart = _cart;
}

MyArray<FoodItem>& Cart::getCart(){
   return cart;
}

void Cart::printCart()const{
   cout<<"Cart"<<endl;
   cout<<"==========================================================================="<<endl;
   for(int i=0;i<cart.getSize();i++){
    cout<<i+1<<". "<<cart[i].getName()<<"    "<<cart[i].getWeight()<<"     "<<cart[i].getPrice()<<endl;
   }
    cout<<"==========================================================================="<<endl;

}
