#include "Ingredient.h"
#include "Item.h"
#include "Menu.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

Menu::Menu() = default;

Menu::Menu(vector<FoodItem> _food, vector<DrinkItem> _drink){
   this->setFood(_food);
   this->setDrink(_drink);
}

void Menu::setFood(vector<FoodItem> _food){
   this->food = _food;
}

void Menu::setDrink(vector<DrinkItem> _drink){
   this->drink = _drink;
}

vector<FoodItem>& Menu::getFood(){
   return this->food;
}

vector<DrinkItem>& Menu::getDrink(){
   return this->drink;
}

void Menu::printType(FoodType t)const{
   for(int i = 0; i < food.size(); i++){
    if(food[i].getType() == t){
        cout<<i+1<<". ";
        food[i].printForMenu();
    }
   }
}

void Menu::printFood()const{
   cout<<"____________________________-=FOOD=-___________________________________"<<endl<<endl;
   cout<<"Salads-----------------------------------------------------------------"<<endl;
   printType(Salad);
   cout<<endl<<"Soups-------------------------------------------------------------------"<<endl;
   printType(Soup);
   cout<<endl<<"Chicken-Dishes----------------------------------------------------------"<<endl;
   printType(ChickenDish);
   cout<<endl<<"Beef-Dishes-------------------------------------------------------------"<<endl;
   printType(BeefDish);
   cout<<endl<<"Fish-Dishes-------------------------------------------------------------"<<endl;
   printType(FishDish);
   cout<<endl<<"Desserts----------------------------------------------------------------"<<endl;
   printType(Dessert);
}

void Menu::printType(DrinkType t)const{
   for(int i = 0; i < drink.size(); i++){
    if(drink[i].getType() == t){
        cout<<i+1<<". ";
        drink[i].printForMenu();
    }
   }
}

void Menu::printDrink()const{
   cout<<"____________________________-=DRINKS=-___________________________________"<<endl<<endl;
   cout<<"Juice--------------------------------------------------------------------"<<endl;
   printType(Juice);
   cout<<endl<<"Alcohol-------------------------------------------------------------------"<<endl;
   printType(Alcohol);
   cout<<endl<<"Fizzy-Drinks--------------------------------------------------------------"<<endl;
   printType(FizzyDrink);
   cout<<endl<<"Soft-Drinks---------------------------------------------------------------"<<endl;
   printType(SoftDrink);
   cout<<endl<<"Warm-Drinks---------------------------------------------------------------"<<endl;
   printType(WarmDrink);
}

void Menu::printFull()const{
   cout<<"_____-==MENU==-____________________________________________________________"<<endl<<endl;
   printFood();
   cout<<endl<<endl;
   printDrink();
}

void Menu::sortUp(vector<FoodItem> _food){
   for (int i = 0; i < _food.size(); i++){
       for (int j = 0; j < _food.size()-i-1; j++){
           if (_food[j].getPrice() > _food[j+1].getPrice())
               swap(_food[j], _food[j+1]);
       }
    }
}

void Menu::sortDown(vector<FoodItem> _food){
   for (int i = 0; i < _food.size(); i++){
       for (int j = 0; j < _food.size()-i-1; j++){
           if (_food[j].getPrice() < _food[j+1].getPrice())
               swap(_food[j], _food[j+1]);
       }
    }
}

void Menu::sortUp(vector<DrinkItem> _drink){
   for (int i = 0; i < _drink.size(); i++){
       for (int j = 0; j < _drink.size()-i-1; j++){
           if (_drink[j].getPrice() > _drink[j+1].getPrice())
               swap(_drink[j], _drink[j+1]);
       }
    }
}

void Menu::sortDown(vector<DrinkItem> _drink){
   for (int i = 0; i < _drink.size(); i++){
       for (int j = 0; j < _drink.size()-i-1; j++){
           if (_drink[j].getPrice() < _drink[j+1].getPrice())
               swap(_drink[j], _drink[j+1]);
       }
    }
}
