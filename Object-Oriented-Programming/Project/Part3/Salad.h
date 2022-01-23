#ifndef SALAD_H_INCLUDED
#define SALAD_H_INCLUDED

#include<iostream>
#include "MyArray.h"
//#include "MyArray.cpp"
#include "MyString.h"
#include "Ingredient.h"
#include "FoodItem.h"

using namespace std;

class Salad{
public:
    Salad();
    Salad(MyArray<FoodItem> );
    void printSalads()const;
    MyArray<FoodItem>& getSalads();
    void sortSaladsUp(MyArray<FoodItem> );
    void sortSaladsDown(MyArray<FoodItem> );

private:
    void setSalad(MyArray<FoodItem> );
    MyArray<FoodItem> salads;

};

#endif // SALAD_H_INCLUDED
