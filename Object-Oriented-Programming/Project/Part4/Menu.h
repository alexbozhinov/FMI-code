#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Ingredient.h"
#include "Item.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Menu{

public:
    Menu();
    Menu(vector<FoodItem>, vector<DrinkItem> );

    vector<FoodItem>& getFood();
    vector<DrinkItem>& getDrink();

    void printFull()const;
    void printFood()const;
    void printDrink()const;
    void printType(FoodType )const;
    void printType(DrinkType )const;

    void sortUp(vector<FoodItem> );
    void sortDown(vector<FoodItem> );
    void sortUp(vector<DrinkItem> );
    void sortDown(vector<DrinkItem> );

private:
    void setFood(vector<FoodItem> );
    void setDrink(vector<DrinkItem> );

    vector<FoodItem> food;
    vector<DrinkItem> drink;
};

#endif // MENU_H_INCLUDED
