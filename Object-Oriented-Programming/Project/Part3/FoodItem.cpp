#include<iostream>
#include "MyString.h"
#include "MyArray.h"
#include "MyArray.cpp"
#include "Ingredient.h"
#include "FoodItem.h"

using namespace std;

FoodItem::FoodItem(){
   name = "";
   ingredients = NULL;
   price = 0.0;
   weight = 0.0;
   cookingTime = 0.0;
}

FoodItem::FoodItem(MyString _name, MyArray<Ingredient> _ingredients, double _price, double _weight, double _cookingTime){
   this->setName(_name);
   this->setIngredients(_ingredients);
   this->setPrice(_price);
   this->setWeight(_weight);
   this->setCookingTime(_cookingTime);
}

void FoodItem::setName(MyString _name){
   this->name = _name;
}

void FoodItem::setIngredients(MyArray<Ingredient> _ingredients){
   this->ingredients = _ingredients;
}

void FoodItem::setPrice(double _price){
   this->price = _price;
}

void FoodItem::setWeight(double _weight){
   this->weight = _weight;
}

void FoodItem::setCookingTime(double _cookingTime){
   this->cookingTime = _cookingTime;
}

void FoodItem::setNumberToBuy(int _number){
   this->numberToBuy = _number;
}

MyString FoodItem::getName()const{
   return this->name;
}

double FoodItem::getPrice()const{
   return this->price;
}

double FoodItem::getWeight()const{
   return this->weight;
}

double FoodItem::getCookingTime()const{
   return this->cookingTime;
}

int FoodItem::getNumberToBuy()const{
   return this->numberToBuy;
}

void FoodItem::printFoodItem()const{
  /* cout<<"Name: "<<name<<endl;
   cout<<"Ingredients: ";
      for(int i=0;i<ingredients.getSize();i++){
         ingredients[i].printIngredient();
      }
   cout<<"Price: "<<price<<endl;
   cout<<"Weight: "<<weight<<endl;
   cout<<"Cooking time: "<<cookingTime<<endl;
   */
   cout<<name;
   for(int i=0;i<50-name.getLength();i++){
       cout<<".";
   }
   cout<<"       "<<weight<<"        "<<price<<endl;
   ///ingredients
}




















