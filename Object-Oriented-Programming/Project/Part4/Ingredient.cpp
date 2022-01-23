#include "Ingredient.h"
#include<iostream>
#include<string>

using namespace std;

///***Ingredient***///

Ingredient::Ingredient(){
   this->name = "";
   this->quantity = 0.0;
   this->measure = kg;
   this->price = 0.0;
   this->currency = lev;
}

Ingredient::Ingredient(string _name, double _quantity, Measure _measure, double _price, Currency _currency){
   this->setName(_name);
   this->setQuantity(_quantity);
   this->setMeasure(_measure);
   this->setPrice(_price);
   this->setCurrency(_currency);
}

void Ingredient::setName(string _name){
   this->name = _name;
}

void Ingredient::setQuantity(double _quantity){
   this->quantity = _quantity;
}

void Ingredient::setMeasure(Measure _measure){
   this->measure = _measure;
}

void Ingredient::setPrice(double _price){
   this->price = _price;
}

void Ingredient::setCurrency(Currency _currency){
   this->currency = _currency;
}

string Ingredient::getName()const{
   return this->name;
}

double Ingredient::getQuantity()const{
   return this->quantity;
}

Measure Ingredient::getMeasure()const{
   return this->measure;
}

double Ingredient::getPrice()const{
   return this->price;
}

Currency Ingredient::getCurrency()const{
   return this->currency;
}

void Ingredient::printIngredient()const{
cout<<"Ingredient: "<<endl;
cout<<"name: "<<name<<endl;
cout<<"quantity: "<<quantity<<" ";
if(this->measure == 0) cout<<"kg";
else if(this->measure == 1) cout<<"g";
else if(this->measure == 2) cout<<"l";
else if(this->measure == 3) cout<<"ml";
else if(this->measure == 4) cout<<"piece";
else if(this->measure == 5) cout<<"glass";
else if(this->measure == 6) cout<<"bottle";
cout<<endl;
cout<<"price: "<<price<<" ";
if(this->currency == 0) cout<<"leva";
else if(this->currency == 1) cout<<"euros";
else if(this->currency == 2) cout<<"dollars";
else if(this->currency == 3) cout<<"pounds";
cout<<endl;
}

void Ingredient::printStorage()const{
   cout<<name<<"                 "<<price<<" ";
   if(this->currency == 0) cout<<"leva";
   else if(this->currency == 1) cout<<"euros";
   else if(this->currency == 2) cout<<"dollars";
   else if(this->currency == 3) cout<<"pounds";
}

void Ingredient::printMeasure()const{
   if(this->measure == 0) cout<<"kg";
   else if(this->measure == 1) cout<<"g";
   else if(this->measure == 2) cout<<"l";
   else if(this->measure == 3) cout<<"ml";
   else if(this->measure == 4) cout<<"piece";
   else if(this->measure == 5) cout<<"glass";
   else if(this->measure == 6) cout<<"bottle";
   cout<<endl;
}
///***Vegetable***//
/*
Vegetable::Vegetable(){
   vitamin = "";
   taste = "";
   origin = "";
}

Vegetable::Vegetable(string _name, double quantity, Measure _measure, double _price, Currency _currency, string _vitamin, string _taste, string _origin):Ingredient(_name,quantity,_measure,_price,_currency){
    this->setVitamin(_vitamin);
    this->setTaste(_taste);
    this->setOrigin(_origin);
}

void Vegetable::setVitamin(string _vitamin){
   this->vitamin = _vitamin;
}

void Vegetable::setTaste(string _taste){
   this->taste = _taste;
}

void Vegetable::setOrigin(string _origin){
   this->origin = _origin;
}

string Vegetable::getVitamin()const{
   return this->vitamin;
}

string Vegetable::getTaste()const{
   return this->taste;
}

string Vegetable::getOrigin()const{
   return this->origin;
}

void Vegetable::printVegetable()const{
   printIngredient();
   cout<<"vitamins: "<<vitamin<<endl;
   cout<<"taste: "<<taste<<endl;
   cout<<"origin: "<<origin<<endl;
}
*/
///***Fruit***///





