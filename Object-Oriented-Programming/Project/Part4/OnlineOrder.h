#ifndef ONLINEORDER_H_INCLUDED
#define ONLINEORDER_H_INCLUDED

#include "Ingredient.h"
#include "Item.h"
#include "Cart.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class OnlineOrder{

public:
   OnlineOrder();
   OnlineOrder(Cart, Currency);

   Cart& getCart();
   Currency getCurrency()const;
   double getTotal()const;
   void print()const;
   void printCurrency()const;

private:
    void setCart(Cart );
    void setCurrency(Currency );
    void setTotal();

    Cart cart;
    double total;
    Currency currency;
};

#endif // ONLINEORDER_H_INCLUDED
