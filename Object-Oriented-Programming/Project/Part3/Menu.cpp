#include<iostream>
#include "MyString.h"
#include "MyArray.h"
#include "Ingredient.h"
#include "FoodItem.h"
#include "Salad.h"
#include "Soup.h"
#include "ChickenDish.h"
#include "Dessert.h"
#include "Menu.h"

using namespace std;

Menu::Menu(){}

Menu::Menu(Salad _allSalads, Soup _allSoups, ChickenDish _allChickenDishes, Dessert _allDesserts){
   this->setSalads(_allSalads);
   this->setSoups(_allSoups);
   this->setChickenDishes(_allChickenDishes);
   this->setDesserts(_allDesserts);
}

void Menu::setSalads(Salad _allSalads){
   this->allSalads = _allSalads;
}

void Menu::setSoups(Soup _allSoups){
   this->allSoups = _allSoups;
}

void Menu::setChickenDishes(ChickenDish _allChickenDishes){
   this->allChickenDishes = _allChickenDishes;
}

void Menu::setDesserts(Dessert _allDesserts){
   this->allDesserts = _allDesserts;
}

Salad& Menu::getAllSalads(){
   return allSalads;
}

Soup& Menu::getAllSoups(){
   return allSoups;
}

ChickenDish& Menu::getAllChickenDishes(){
   return allChickenDishes;
}

Dessert& Menu::getAllDesserts(){
   return allDesserts;
}

void Menu::printTypedMenu(int choice)const{
   while(true)
	{
       if(choice!=1&&choice!=2&&choice!=3&&choice!=4){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
	}
   if(choice == 1){
       allSalads.printSalads();
   }
   else if(choice == 2){
       allSoups.printSoups();
   }
   else if(choice == 3){
       allChickenDishes.printChickenDish();
   }
   else if(choice == 4){
       allDesserts.printDessert();
   }
}

void Menu::printFullMenu()const{
    allSalads.printSalads();
    allSoups.printSoups();
    allChickenDishes.printChickenDish();
    allDesserts.printDessert();
}
