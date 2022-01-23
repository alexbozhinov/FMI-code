#include<iostream>
#include "MyArray.h"
#include "MyArray.cpp"
#include "MyString.h"
#include "Ingredient.h"
#include "FoodItem.h"
#include "Soup.h"

using namespace std;

Soup::Soup(){
   soups = NULL;
}

Soup::Soup(MyArray<FoodItem> _soups){
   this->setSoup(_soups);
}

void Soup::setSoup(MyArray<FoodItem> _soups){
   this->soups = _soups;
}

void Soup::printSoups()const{
   cout<<"===SOUPS===                                              weight      price"<<endl<<endl;
   for(int i=0;i<soups.getSize();i++){
        cout<<i+1<<".";///
       soups[i].printFoodItem();
   }
   cout<<endl;
}

MyArray<FoodItem>& Soup::getSoups(){
   return soups;
}

void Soup::sortSoupsUp(MyArray<FoodItem> _soups){

    for (int i = 0; i < _soups.getSize()-1; i++){
       for (int j = 0; j < _soups.getSize()-i-1; j++){
           if (_soups[j].getPrice() > _soups[j+1].getPrice())
               swap(_soups[j], _soups[j+1]);
       }
    }
    printSoups();
}

void Soup::sortSoupsDown(MyArray<FoodItem> _soups){

    for (int i = 0; i < _soups.getSize()-1; i++){
       for (int j = 0; j < _soups.getSize()-i-1; j++){
           if (_soups[j].getPrice() < _soups[j+1].getPrice())
               swap(_soups[j], _soups[j+1]);
       }
    }
    printSoups();
}
