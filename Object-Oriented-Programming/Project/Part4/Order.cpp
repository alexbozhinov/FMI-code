#include "Item.h"
#include "Ingredient.h"
#include "Order.h"
#include<iostream>
#include<vector>
#include<string>

using namespace std;

Order::Order() = default;

Order::Order(vector<FoodItem> _food, vector<DrinkItem> _drink){
   this->setFood(_food);
   this->setDrink(_drink);
   this->setTotal(_food, _drink);
   this->setCurrency(_food);
}

void Order::setFood(vector<FoodItem> _food){
   this->food = _food;
}

void Order::setDrink(vector<DrinkItem> _drink){
   this->drink = _drink;
}

void Order::setTotal(vector<FoodItem> _food, vector<DrinkItem> _drink){
   double _total = 0.0;
   for(int i=0;i<getFood().size();i++){
       _total += getFood()[i].getPrice();
   }
   for(int i=0;i<getDrink().size();i++){
      _total += getDrink()[i].getPrice();
   }
   this->total = _total;
}

void Order::setCurrency(vector<FoodItem> _food){
   this->currency = _food[0].getCurrency();
}

double Order::getTotal()const{
   return this->total;
}

vector<FoodItem>& Order::getFood(){
   return this->food;
}

vector<DrinkItem>& Order::getDrink(){
   return this->drink;
}

void Order::printCurrency(Currency currency)const{
  if(currency == 0) cout<<"leva";
   else if(currency == 1) cout<<"euros";
   else if(currency == 2) cout<<"dollars";
   else if(currency == 3) cout<<"pounds";
}

void Order::print()const{
cout<<"_____________________________ORDER____________________________________"<<endl<<endl;
cout<<"Food: ----------------------------------------------------------------"<<endl<<endl;
for(int i=0;i<food.size();i++){
    cout<<i+1<<". ";
    food[i].printForMenu();
}
cout<<endl;
cout<<"Drink: ---------------------------------------------------------------"<<endl<<endl;
for(int i=0;i<drink.size();i++){
    cout<<i+1<<". ";
    drink[i].printForMenu();
}
cout<<endl<<"TOTAL:______________________________________________________________";
double t = 0.0;
for(int i=0;i<food.size();i++){
    t+=food[i].getPrice();
}
for(int i=0;i<drink.size();i++){
    t+=drink[i].getPrice();
}
cout<<t;
cout<<" ";
printCurrency(currency);
cout<<endl;

}
