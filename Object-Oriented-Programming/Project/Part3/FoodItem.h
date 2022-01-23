#ifndef FOODITEM_H_INCLUDED
#define FOODITEM_H_INCLUDED

#include<iostream>
#include "MyString.h"
#include "MyArray.h"
#include "Ingredient.h"

using namespace std;

class FoodItem{
public:
   FoodItem();
   FoodItem(MyString, MyArray<Ingredient>, double, double, double);
   MyString getName()const;
   double getPrice()const;
   double getWeight()const;
   double getCookingTime()const;
   void printFoodItem()const;
   void setPrice(double );
   void setNumberToBuy(int );///
   int getNumberToBuy()const;

private:
    void setName(MyString );
    void setIngredients(MyArray<Ingredient> );
    void setWeight(double );
    void setCookingTime(double );
    MyString name;
    MyArray<Ingredient> ingredients;
    double weight;
    double price;
    double cookingTime;
    int numberToBuy;
};


#endif // FOODITEM_H_INCLUDED
