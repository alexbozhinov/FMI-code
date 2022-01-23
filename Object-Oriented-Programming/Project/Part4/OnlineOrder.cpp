#include "Ingredient.h"
#include "Item.h"
#include "Cart.h"
#include "OnlineOrder.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

OnlineOrder::OnlineOrder() = default;

OnlineOrder::OnlineOrder(Cart _cart, Currency _currency){
   this->setCart(_cart);
   this->setCurrency(_currency);
   this->setTotal();
}

void OnlineOrder::setCart(Cart _cart){
   this->cart = _cart;
}

void OnlineOrder::setCurrency(Currency _currency){
   this->currency = _currency;
}

void OnlineOrder::setTotal(){
   double _total = 0.0;
   for(int i=0;i<cart.getFood().size();i++){
       _total += cart.getFood()[i].getPrice();
   }
   for(int i=0;i<cart.getDrink().size();i++){
      _total += cart.getDrink()[i].getPrice();
   }
   this->total = _total;
}

Cart& OnlineOrder::getCart(){
   return this->cart;
}

Currency OnlineOrder::getCurrency()const{
   return this->currency;
}

double OnlineOrder::getTotal()const{
   return this->total;
}

void OnlineOrder::printCurrency()const{
   if(this->currency == 0) cout<<"leva";
   else if(this->currency == 1) cout<<"euros";
   else if(this->currency == 2) cout<<"dollars";
   else if(this->currency == 3) cout<<"pounds";
}

void OnlineOrder::print()const{
   cout<<"______ORDER_________________________________________________________________"<<endl<<endl;
   cart.print();
   cout<<"TOTAL:_________________________________________________________"<<total<<" ";
   printCurrency();
   cout<<endl;
}
