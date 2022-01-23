#include "Ingredient.h"
#include "Item.h"
#include "Cart.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

Cart::Cart() = default;

Cart::Cart(vector<FoodItem> _food, vector<DrinkItem> _drink){
   this->setFood(_food);
   this->setDrink(_drink);
}

void Cart::setFood(vector<FoodItem> _food){
   this->food = _food;
}

void Cart::setDrink(vector<DrinkItem> _drink){
   this->drink = _drink;
}

vector<FoodItem>& Cart::getFood(){
   return this->food;
}

vector<DrinkItem>& Cart::getDrink(){
   return this->drink;
}

void Cart::print()const{
   cout<<endl<<"Food========================================================================"<<endl<<endl;
   for(int i=0;i<food.size();i++){
    cout<<i+1<<". ";
    food[i].printForMenu();
   }
   cout<<endl<<"Drink========================================================================"<<endl<<endl;
   for(int i=0;i<drink.size();i++){
     cout<<i+1<<". ";
     drink[i].printForMenu();
   }
}
