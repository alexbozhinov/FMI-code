#ifndef ORDER_H_INCLUDED
#define ORDER_H_INCLUDED

#include "Item.h"
#include "Ingredient.h"
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Order{
public:
    Order();
    Order(vector<FoodItem>, vector<DrinkItem> );
    double getTotal()const;
    vector<FoodItem>& getFood();
    vector<DrinkItem>& getDrink();
    void print()const;
    void printCurrency(Currency )const;

private:
    void setFood(vector<FoodItem> );
    void setDrink(vector<DrinkItem> );
    void setTotal(vector<FoodItem>, vector<DrinkItem> );
    void setCurrency(vector<FoodItem> );

    vector<FoodItem> food;
    vector<DrinkItem> drink;
    double total;
    Currency currency;
};

#endif // ORDER_H_INCLUDED
