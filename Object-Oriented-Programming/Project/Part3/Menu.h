#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include<iostream>
#include "MyString.h"
#include "MyArray.h"
#include "Ingredient.h"
#include "FoodItem.h"
#include "Salad.h"
#include "Soup.h"
#include "ChickenDish.h"
#include "Dessert.h"

using namespace std;

class Menu{
public:
    Menu();
    Menu(Salad, Soup, ChickenDish, Dessert);
    void printTypedMenu(int )const;
    void printFullMenu()const;
    Salad& getAllSalads();
    Soup& getAllSoups();
    ChickenDish& getAllChickenDishes();
    Dessert& getAllDesserts();
    void chooseItems(int );///


private:
    void setSalads(Salad );
    void setSoups(Soup );
    void setChickenDishes(ChickenDish );
    void setDesserts(Dessert );
    Salad allSalads;///
    Soup allSoups;
    ChickenDish allChickenDishes;
    Dessert allDesserts;
};

#endif // MENU_H_INCLUDED
