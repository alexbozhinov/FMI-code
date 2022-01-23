#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include<iostream>
#include<string>
#include<vector>
#include "Ingredient.h"

using namespace std;

enum FoodType{
   Salad,
   Soup,
   ChickenDish,
   BeefDish,
   FishDish,
   Dessert
};

enum DrinkType{
   Juice,
   Alcohol,
   FizzyDrink,
   SoftDrink,
   WarmDrink
};

///***Item***///

class Item{

public:
    Item();
    Item(string, double, Measure, double, Currency );
    string getName()const;
    double getQuantity()const;
    Measure getMeasure()const;
    double getPrice()const;
    Currency getCurrency()const;
    void printItem()const;
    void printForMenu()const;
    void printCurrency(Currency )const;
    void printMeasure(Measure )const;
    void setPrice(double );

private:
    void setName(string);
    void setQuantity(double );
    void setMeasure(Measure );
    void setCurrency(Currency );

    string name;
    double quantity;
    Measure measure;
    double price;
    Currency currency;
};

///***FoodItem***///

class FoodItem : public Item{

public:
    FoodItem();
    FoodItem(string, double, Measure, double, Currency, FoodType, vector<Ingredient>, double, string);
    FoodType getType()const;
    vector<Ingredient> getIngredients()const;
    double getTime()const;
    string getRecipe()const;
    void print()const;
   // void printForMenu()const;

private:
    void setType(FoodType );
    void setIngredients(vector<Ingredient> );
    void setTime(double );
    void setRecipe(string );

    FoodType type;
    vector<Ingredient> ingredients;
    double cookingTime;
    string recipe;
};

///***DrinkItem***///

class DrinkItem : public Item{

public:
   DrinkItem();
   DrinkItem(string, double, Measure, double, Currency, DrinkType, string, double);
   DrinkType getType()const;
   string getBrand()const;
   double getDegree()const;
   void print()const;

private:
   void setType(DrinkType );
   void setBrand(string );
   void setDegree(double );

   DrinkType type;
   string brand;
   double alcoholDegree;
};
#endif // ITEM_H_INCLUDED
