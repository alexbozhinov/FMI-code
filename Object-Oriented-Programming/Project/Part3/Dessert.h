#ifndef DESSERT_H_INCLUDED
#define DESSERT_H_INCLUDED

#include<iostream>
#include "MyArray.h"
//#include "MyArray.cpp"
#include "MyString.h"
#include "Ingredient.h"
#include "FoodItem.h"

using namespace std;

class Dessert{
public:
    Dessert();
    Dessert(MyArray<FoodItem> );
    void printDessert()const;
    MyArray<FoodItem>& getDesserts();
    void sortDessertssUp(MyArray<FoodItem> );
    void sortDessertsDown(MyArray<FoodItem> );
private:
    MyArray<FoodItem> desserts;
    void setDessert(MyArray<FoodItem> );
};


#endif // DESSERT_H_INCLUDED
