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
#include "OnlineOrder.h"

using namespace std;

OnlineOrder::OnlineOrder(){};

OnlineOrder::OnlineOrder(Cart _itemsToBuy){
   this->setItemsToBuy(_itemsToBuy);
   this->setFullSum();
}

Cart& OnlineOrder::getOnlineOrder(){
   return itemsToBuy;
}

double OnlineOrder::getFullSum()const{
   return fullSum;
}

void OnlineOrder::setItemsToBuy(Cart _itemsToBuy){
   this->itemsToBuy = _itemsToBuy;
}

void OnlineOrder::setFullSum(){
   double _sum = 0.0;
   for(int i=0;i<itemsToBuy.getCart().getSize();i++){
      _sum += itemsToBuy.getCart()[i].getPrice();
   }
   this->fullSum = _sum;
}

void OnlineOrder::printOnlineOrder()const{
   cout<<"ORDER"<<endl<<endl;
   itemsToBuy.printCart();
   cout<<endl;
   cout<<"Final sum: "<<fullSum<<endl;
}
