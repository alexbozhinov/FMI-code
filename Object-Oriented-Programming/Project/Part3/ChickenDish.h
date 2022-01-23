#ifndef CHICKENDISH_H_INCLUDED
#define CHICKENDISH_H_INCLUDED

#include<iostream>
#include "MyArray.h"
//#include "MyArray.cpp"
#include "MyString.h"
#include "Ingredient.h"
#include "FoodItem.h"

using namespace std;

class ChickenDish{
public:
    ChickenDish();
    ChickenDish(MyArray<FoodItem> );
    void printChickenDish()const;
    MyArray<FoodItem>& getChickenDishes();
    void sortChickenDishesUp(MyArray<FoodItem> );
    void sortChickenDishesDown(MyArray<FoodItem> );
private:
    MyArray<FoodItem> chickenDishes;
    void setChickenDish(MyArray<FoodItem> );
};

#endif // CHICKENDISH_H_INCLUDED
