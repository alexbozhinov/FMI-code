#ifndef SOUP_H_INCLUDED
#define SOUP_H_INCLUDED

#include<iostream>
#include "MyArray.h"
//#include "MyArray.cpp"
#include "MyString.h"
#include "Ingredient.h"
#include "FoodItem.h"

using namespace std;

class Soup{
public:
    Soup();
    Soup(MyArray<FoodItem> );
    void printSoups()const;
    MyArray<FoodItem>& getSoups();
    void sortSoupsUp(MyArray<FoodItem> );
    void sortSoupsDown(MyArray<FoodItem> );
private:
    MyArray<FoodItem> soups;
    void setSoup(MyArray<FoodItem> );
};

#endif // SOUP_H_INCLUDED
