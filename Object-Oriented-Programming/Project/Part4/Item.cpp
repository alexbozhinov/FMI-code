#include "Ingredient.h"
#include "Item.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

///***Item***///
Item::Item(){
   name = "";
   quantity = 0.0;
   measure = kg;
   price = 0.0;
   currency = lev;
}

Item::Item(string _name, double _quantity, Measure _measure, double _price, Currency _currency){
   this->setName(_name);
   this->setQuantity(_quantity);
   this->setMeasure(_measure);
   this->setPrice(_price);
   this->setCurrency(_currency);
}

void Item::setName(string _name){
   this->name = _name;
}

void Item::setQuantity(double _quantity){
   this->quantity = _quantity;
}

void Item::setMeasure(Measure _measure){
   this->measure = _measure;
}

void Item::setPrice(double _price){
   this->price = _price;
}

void Item::setCurrency(Currency _currency){
   this->currency = _currency;
}

string Item::getName()const{
   return this->name;
}

double Item::getQuantity()const{
   return this->quantity;
}

Measure Item::getMeasure()const{
   return this->measure;
}

double Item::getPrice()const{
   return this->price;
}

Currency Item::getCurrency()const{
   return this->currency;
}

void Item::printItem()const{
   cout<<"Item: "<<endl;
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

void Item::printCurrency(Currency currency)const{
  if(currency == 0) cout<<"leva";
   else if(currency == 1) cout<<"euros";
   else if(currency == 2) cout<<"dollars";
   else if(currency == 3) cout<<"pounds";
}

void Item::printMeasure(Measure measure)const{
   if(measure == 0) cout<<"kg";
   else if(measure == 1) cout<<"g";
   else if(measure == 2) cout<<"l";
   else if(measure == 3) cout<<"ml";
   else if(measure == 4) cout<<"piece";
   else if(measure == 5) cout<<"glass";
   else if(measure == 6) cout<<"bottle";
}

void Item::printForMenu()const{
   cout<<getName();
   for(int i=0; i < 50 - getName().size();i++){ cout<<".";}
   cout<<getQuantity()<<" ";
   printMeasure(measure);
   cout<<"...."<<getPrice()<<" ";
   printCurrency(currency);
   cout<<endl;
}

///***FoodItem***///

FoodItem::FoodItem(){
   type = Salad;
   cookingTime = 0.0;
   recipe = "";
}

FoodItem::FoodItem(string _name, double _quantity, Measure _measure, double _price, Currency _currency, FoodType _type, vector<Ingredient> _ingredients, double _time, string _recipe)
   :Item(_name, _quantity, _measure, _price, _currency)
   {
       this->setType(_type);
       this->setIngredients(_ingredients);
       this->setTime(_time);
       this->setRecipe(_recipe);
   }

void FoodItem::setType(FoodType _type){
   this->type = _type;
}

void FoodItem::setIngredients(vector<Ingredient> _ingredients){
   this->ingredients = _ingredients;
}

void FoodItem::setTime(double _time){
   this->cookingTime = _time;
}

void FoodItem::setRecipe(string _recipe){
   this->recipe = _recipe;
}

FoodType FoodItem::getType()const{
   return this->type;
}

vector<Ingredient> FoodItem::getIngredients()const{
   return this->ingredients;
}

double FoodItem::getTime()const{
   return this->cookingTime;
}

string FoodItem::getRecipe()const{
   return this->recipe;
}

void FoodItem::print()const{
   printItem();
   cout<<"Type: ";
   if(this->type == 0) cout<<"Salad";
   else if(this->type == 1) cout<<"Soup";
   else if(this->type == 2) cout<<"Chicken Dish";
   else if(this->type == 3) cout<<"Beef Dish";
   else if(this->type == 4) cout<<"Fish Dish";
   else if(this->type == 5) cout<<"Dessert";
   cout<<endl;
   cout<<"Ingredients: ";

   for(int i=0;i<ingredients.size();i++){
       ingredients[i].printIngredient();
   }
   cout<<endl;
   cout<<"Cooking time: "<<cookingTime<<endl;
   cout<<"Recipe: "<<recipe<<endl;
}
/*
void FoodItem::printForMenu()const{
   cout<<getName()<<"....................."<<getQuantity()<<" "<<getMeasure()<<"....."<<getPrice()<<" "<<getCurrency()<<endl;
}
*/
///***Drink Item***///

DrinkItem::DrinkItem(){
   type = Juice;
   brand = "";
   alcoholDegree = 0.0;
}

DrinkItem::DrinkItem(string _name, double _quantity, Measure _measure, double _price, Currency _currency, DrinkType _type, string _brand, double _degree)
   : Item(_name, _quantity, _measure, _price, _currency)
   {
       this->setType(_type);
       this->setBrand(_brand);
       this->setDegree(_degree);
   }

void DrinkItem::setType(DrinkType _type){
   this->type = _type;
}

void DrinkItem::setBrand(string _brand){
   this->brand = _brand;
}

void DrinkItem::setDegree(double _degree){
   this->alcoholDegree = _degree;
}

DrinkType DrinkItem::getType()const{
   return this->type;
}

string DrinkItem::getBrand()const{
   return this->brand;
}

double DrinkItem::getDegree()const{
   return this->alcoholDegree;
}

void DrinkItem::print()const{
   printItem();
   cout<<"Type: ";
   if(this->type == 0) cout<<"Juice";
   else if(this->type == 1) cout<<"Alcohol";
   else if(this->type == 2) cout<<"Fizzy Drink";
   else if(this->type == 3) cout<<"Soft Drink";
   else if(this->type == 4) cout<<"Warm Drink";
   cout<<endl;
   cout<<"brand: "<<brand<<endl;
   cout<<"degree: "<<alcoholDegree<<endl;
}




