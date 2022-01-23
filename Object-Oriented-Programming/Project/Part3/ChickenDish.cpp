#include<iostream>
#include "MyArray.h"
#include "MyArray.cpp"
#include "MyString.h"
#include "Ingredient.h"
#include "FoodItem.h"
#include "ChickenDish.h"

using namespace std;

ChickenDish::ChickenDish(){
   chickenDishes = NULL;
}

ChickenDish::ChickenDish(MyArray<FoodItem> _chickenDishes){
   this->setChickenDish(_chickenDishes);
}

void ChickenDish::setChickenDish(MyArray<FoodItem> _chickenDishes){
   this->chickenDishes = _chickenDishes;
}

void ChickenDish::printChickenDish()const{
   cout<<"===CHICKEN DISHES===                                     weight      price"<<endl<<endl;
   for(int i=0;i<chickenDishes.getSize();i++){
        cout<<i+1<<".";///
       chickenDishes[i].printFoodItem();
   }
   cout<<endl;
}

MyArray<FoodItem>& ChickenDish::getChickenDishes(){
   return chickenDishes;
}

void ChickenDish::sortChickenDishesUp(MyArray<FoodItem> _chickenDishes){

    for (int i = 0; i < _chickenDishes.getSize()-1; i++){
       for (int j = 0; j < _chickenDishes.getSize()-i-1; j++){
           if (_chickenDishes[j].getPrice() > _chickenDishes[j+1].getPrice())
               swap(_chickenDishes[j], _chickenDishes[j+1]);
       }
}
    printChickenDish();
}

void ChickenDish::sortChickenDishesDown(MyArray<FoodItem> _chickenDishes){

    for (int i = 0; i < _chickenDishes.getSize()-1; i++){
       for (int j = 0; j < _chickenDishes.getSize()-i-1; j++){
           if (_chickenDishes[j].getPrice() < _chickenDishes[j+1].getPrice())
               swap(_chickenDishes[j], _chickenDishes[j+1]);
       }
    }
    printChickenDish();
}
