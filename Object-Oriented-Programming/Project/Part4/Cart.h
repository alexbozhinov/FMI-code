#ifndef CART_H_INCLUDED
#define CART_H_INCLUDED

#include "Ingredient.h"
#include "Item.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Cart{

public:
    Cart();
    Cart(vector<FoodItem>, vector<DrinkItem> );

    vector<FoodItem>& getFood();
    vector<DrinkItem>& getDrink();
    void print()const;

private:
    void setFood(vector<FoodItem> );
    void setDrink(vector<DrinkItem> );

    vector<FoodItem> food;
    vector<DrinkItem> drink;
};

#endif // CART_H_INCLUDED
