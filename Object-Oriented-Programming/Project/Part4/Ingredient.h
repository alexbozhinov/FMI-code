#ifndef INGREDIENT_H_INCLUDED
#define INGREDIENT_H_INCLUDED

#include<iostream>
#include<string>

using namespace std;

enum Measure{
  kg,
  g,
  l,
  ml,
  piece,
  glass,
  bottle
};

enum Currency{
   lev,
   euro,
   dollar,
   pound
};

///***Ingredient***///

class Ingredient{

public:
    Ingredient();
    Ingredient(string, double, Measure, double, Currency );
    string getName()const;
    double getQuantity()const;
    Measure getMeasure()const;
    double getPrice()const;
    Currency getCurrency()const;
    void printIngredient()const;
    void printStorage()const;
    void printMeasure()const;

private:
    string name;
    double quantity;
    Measure measure;
    double price;
    Currency currency;

    void setName(string );
    void setQuantity(double );
    void setMeasure(Measure );
    void setPrice(double );
    void setCurrency(Currency );
};

///***Vegetable***///
/*
class Vegetable : public Ingredient{

public:
   Vegetable();
   Vegetable(string, double, Measure, double, Currency, string, string, string);
   string getVitamin()const;
   string getTaste()const;
   string getOrigin()const;
   void printVegetable()const;

private:
    string vitamin;
    string taste;
    string origin;

    void setVitamin(string );
    void setTaste(string );
    void setOrigin(string );
};*/

///***Fruit***///
/*
class Fruit : public Ingredient{

public:
   Fruit();
   Fruit(string, double, Measure, double, Currency, string, string, string,string);
   string getVitamin()const;
   string getTaste()const;
   string getOrigin()const;
   string getType()const;
   void printFruit()const;

private:
    string vitamin;
    string taste;
    string origin;
    string type;

    void setVitamin(string );
    void setTaste(string );
    void setOrigin(string );
    void setType(string );
};*/
#endif // INGREDIENT_H_INCLUDED
