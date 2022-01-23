#include<iostream>
#include "MyString.h"
#include "Ingredient.h"

Ingredient::Ingredient(){
   name = "";
   quantity = 0.0;
   marketPrice = 0.0;
}

Ingredient::Ingredient(MyString _name, double _quantity, double _marketPrice){
   this->setName(_name);
   this->setQuantity(_quantity);
   this->setMarketPrice(_marketPrice);
}

void Ingredient::setName(MyString _name){
   this->name = _name;
}

void Ingredient::setQuantity(double _quantity){
   this->quantity = _quantity;
}

void Ingredient::setMarketPrice(double _marketPrice){
   this->marketPrice = _marketPrice;
}

MyString Ingredient::getName()const{
   return this->name;
}

double Ingredient::getQuantity()const{
   return this->quantity;
}

double Ingredient::getMarketPrice()const{
   return this->marketPrice;
}

void Ingredient::printIngredient()const{
   cout<<"Name: "<<name<<endl;
   cout<<"Quantity: "<<quantity<<endl;
   cout<<"Market price: "<<marketPrice<<endl;
}
