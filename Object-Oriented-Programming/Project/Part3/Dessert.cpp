#include<iostream>
#include "MyArray.h"
#include "MyArray.cpp"
#include "MyString.h"
#include "Ingredient.h"
#include "FoodItem.h"
#include "Dessert.h"

using namespace std;

Dessert::Dessert(){
   desserts = NULL;
}

Dessert::Dessert(MyArray<FoodItem> _desserts){
   this->setDessert(_desserts);
}

void Dessert::setDessert(MyArray<FoodItem> _desserts){
   this->desserts = _desserts;
}

void Dessert::printDessert()const{
   cout<<"===DESSERTS===                                           weight      price"<<endl<<endl;
   for(int i=0;i<desserts.getSize();i++){
    cout<<i+1<<".";///
       desserts[i].printFoodItem();
   }
   cout<<endl;
}

MyArray<FoodItem>& Dessert::getDesserts(){
   return desserts;
}

void Dessert::sortDessertssUp(MyArray<FoodItem> _desserts){

    for (int i = 0; i < _desserts.getSize()-1; i++){
       for (int j = 0; j < _desserts.getSize()-i-1; j++){
           if (_desserts[j].getPrice() > _desserts[j+1].getPrice())
               swap(_desserts[j], _desserts[j+1]);
       }
    }
    printDessert();
}

void Dessert::sortDessertsDown(MyArray<FoodItem> _desserts){

    for (int i = 0; i < _desserts.getSize()-1; i++){
       for (int j = 0; j < _desserts.getSize()-i-1; j++){
           if (_desserts[j].getPrice() < _desserts[j+1].getPrice())
               swap(_desserts[j], _desserts[j+1]);
       }
    }
    printDessert();
}
