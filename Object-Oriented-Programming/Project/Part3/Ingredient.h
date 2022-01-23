#ifndef INGREDIENT_H_INCLUDED
#define INGREDIENT_H_INCLUDED

#include<iostream>
#include "MyString.h"

using namespace std;

class Ingredient{
   public:
       Ingredient();
       Ingredient(MyString, double, double);
       MyString getName()const;
       double getQuantity()const;
       double getMarketPrice()const;
       void printIngredient()const;

   private:
       void setName(MyString );
       void setQuantity(double );
       void setMarketPrice(double );
       MyString name;
       double quantity;
       double marketPrice;
};


#endif // INGREDIENT_H_INCLUDED
