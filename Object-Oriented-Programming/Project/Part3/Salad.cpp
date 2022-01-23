#include<iostream>
#include "MyArray.h"
#include "MyArray.cpp"
#include "MyString.h"
#include "Ingredient.h"
#include "FoodItem.h"
#include "Salad.h"

using namespace std;

Salad::Salad(){
   salads = NULL;
}

Salad::Salad(MyArray<FoodItem> _salads){
   this->setSalad(_salads);
}

void Salad::setSalad(MyArray<FoodItem> _salads){
   this->salads = _salads;
}

void Salad::printSalads()const{
   cout<<"===SALADS===                                             weight      price"<<endl<<endl;
   for(int i=0;i<salads.getSize();i++){
       cout<<i+1<<".";///
       salads[i].printFoodItem();
   }
   cout<<endl;
}

MyArray<FoodItem>& Salad::getSalads(){
   return salads;
}

void Salad::sortSaladsUp(MyArray<FoodItem> _salads){

    for (int i = 0; i < _salads.getSize()-1; i++){
       for (int j = 0; j < _salads.getSize()-i-1; j++){
           if (_salads[j].getPrice() > _salads[j+1].getPrice())
               swap(_salads[j], _salads[j+1]);
       }
    }
    printSalads();
}

void Salad::sortSaladsDown(MyArray<FoodItem> _salads){

    for (int i = 0; i < _salads.getSize()-1; i++){
       for (int j = 0; j < _salads.getSize()-i-1; j++){
           if (_salads[j].getPrice() < _salads[j+1].getPrice())
               swap(_salads[j], _salads[j+1]);
       }
    }
    printSalads();
}
