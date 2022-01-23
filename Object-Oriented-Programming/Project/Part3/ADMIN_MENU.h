#ifndef ADMIN_MENU_H_INCLUDED
#define ADMIN_MENU_H_INCLUDED

#include<iostream>
#include<fstream>
#include<cstdio>
#include "MyString.h"
#include "MyArray.h"
#include<stdlib.h>
//#include "MyArray.cpp"
#include "Ingredient.h"
#include "User.h"
#include "Ingredient.h"
#include "FoodItem.h"
#include "Salad.h"
#include "Menu.h"
#include "Restaurant.h"
#include "USER_MENU.h"

using namespace std;

///**********************LIST OF PROTOTYPES*****************************///
void AdminMainScreen(Restaurant );
       void adminMenu(Restaurant );
                void typedMenuPrinting(Restaurant );
                         void saladsPrinting(Restaurant );
                         void soupsPrinting(Restaurant );
                         void chickenDishesPrinting(Restaurant );
                         void dessertsPrinting(Restaurant );
                void fullMenuPrinting(Restaurant );
                void addNewItem(Restaurant );
                         void addNewSalad(Restaurant );
                         void addNewSoup(Restaurant );
                         void addNewChickenDish(Restaurant );
                         void addNewDessert(Restaurant );
                void deleteFoodItem(Restaurant );
                         void removeSalad(Restaurant );
                         void removeSoup(Restaurant );
                         void removeChickenDish(Restaurant );
                         void removeDessert(Restaurant );
                void changePrice(Restaurant );
                         void changeInSalads(Restaurant );
                         void changeInSoups(Restaurant );
                         void changeInChickenDishes(Restaurant );
                         //void changeInDesserts(Restaurant );
void usersInput(Restaurant );
void signIn(Restaurant );
void registerMe(Restaurant );
///***********************************CHANGE IN SALADS****************************///
void changeInDesserts(Restaurant restaurant){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   restaurant.getMenu().printTypedMenu(4);
   unsigned int toChange;
   cout<<"Of which dessert would you like to change the price?"<<endl;
   cout<<"Input here: "; cin>>toChange;
   cout<<"Input new price: ";
   double newPrice;
   cin>>newPrice;
   restaurant.getMenu().getAllDesserts().getDesserts()[toChange - 1].setPrice(newPrice);
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   cout<<"You successfully changed the price of the dessert!"<<endl;
   restaurant.getMenu().printTypedMenu(4);
   cout<<endl;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice!=1&&choice!=2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        changePrice(restaurant);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

///***********************************CHANGE IN SALADS****************************///
void changeInChickenDishes(Restaurant restaurant){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   restaurant.getMenu().printTypedMenu(1);
   unsigned int toChange;
   cout<<"Of which chicken dish would you like to change the price?"<<endl;
   cout<<"Input here: "; cin>>toChange;
   cout<<"Input new price: ";
   double newPrice;
   cin>>newPrice;
   restaurant.getMenu().getAllChickenDishes().getChickenDishes()[toChange - 1].setPrice(newPrice);
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   cout<<"You successfully changed the price of the chicken dish!"<<endl;
   restaurant.getMenu().printTypedMenu(3);
   cout<<endl;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice!=1&&choice!=2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        changePrice(restaurant);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }

}

///***********************************CHANGE IN SOUPS****************************///
void changeInSoups(Restaurant restaurant){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   restaurant.getMenu().printTypedMenu(2);
   unsigned int toChange;
   cout<<"Of which soup would you like to change the price?"<<endl;
   cout<<"Input here: "; cin>>toChange;
   cout<<"Input new price: ";
   double newPrice;
   cin>>newPrice;
   restaurant.getMenu().getAllSoups().getSoups()[toChange - 1].setPrice(newPrice);
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   cout<<"You successfully changed the price of the soup!"<<endl;
   restaurant.getMenu().printTypedMenu(2);
   cout<<endl;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice!=1&&choice!=2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        changePrice(restaurant);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

///***********************************CHANGE IN SALADS****************************///
void changeInSalads(Restaurant restaurant){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   restaurant.getMenu().printTypedMenu(1);
   unsigned int toChange;
   cout<<"Of which salad would you like to change the price?"<<endl;
   cout<<"Input here: "; cin>>toChange;
   cout<<"Input new price: ";
   double newPrice;
   cin>>newPrice;
   restaurant.getMenu().getAllSalads().getSalads()[toChange - 1].setPrice(newPrice);
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   cout<<"You successfully changed the price of the salad!"<<endl;
   restaurant.getMenu().printTypedMenu(1);
   cout<<endl;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice!=1&&choice!=2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        changePrice(restaurant);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }

}

///************************************CHANGE PRICE*****************************///
void changePrice(Restaurant restaurant){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   cout<<"What item type would you like to change the price of?"<<endl<<endl;
   cout<<"1. Salads"<<endl;
   cout<<"2. Soups"<<endl;
   cout<<"3. Chicken dishes"<<endl;
   cout<<"4. Desserts"<<endl;
   cout<<"5. Back"<<endl;
   cout<<"6. Exit"<<endl;
   int changeChoice;
   cout<<endl<<"Input choice: ";
   cin>>changeChoice;
   while(true)
	{
       if(changeChoice!=1&&changeChoice!=2&&changeChoice!=3&&changeChoice!=4&&changeChoice!=5&&changeChoice!=6){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>changeChoice; continue;}
		else
		{
			break;
		}
    }
    if(changeChoice == 1){
        changeInSalads(restaurant);
    }
    else if(changeChoice == 2){
        changeInSoups(restaurant);
    }
    else if(changeChoice == 3){
        changeInChickenDishes(restaurant);
    }
    else if(changeChoice == 4){
        changeInDesserts(restaurant);
    }
    else if(changeChoice == 5){
        adminMenu(restaurant);
    }
    else if(changeChoice == 6){
        system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

///*************************************DELETE DESSERT****************************///
void removeDessert(Restaurant restaurant){
   system("CLS");
   restaurant.printRestaurantData();
   restaurant.getMenu().printTypedMenu(4);
   unsigned int toRemove;
   cout<<"Which dessert would you like to remove?"<<endl;
   cout<<"Input here: "; cin>>toRemove;
   restaurant.getMenu().getAllDesserts().getDesserts().removeElementAt(toRemove);
   system("CLS");
   restaurant.printRestaurantData();
   cout<<"You successfully removed the dessert!"<<endl;
   restaurant.getMenu().printTypedMenu(4);
   cout<<endl;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice!=1&&choice!=2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        deleteFoodItem(restaurant);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

///*************************************DELETE CHICKEN DISH****************************///
void removeChickenDish(Restaurant restaurant){
   system("CLS");
   restaurant.printRestaurantData();
   restaurant.getMenu().printTypedMenu(3);
   unsigned int toRemove;
   cout<<"Which chicken dish would you like to remove?"<<endl;
   cout<<"Input here: "; cin>>toRemove;
   restaurant.getMenu().getAllChickenDishes().getChickenDishes().removeElementAt(toRemove);
   system("CLS");
   restaurant.printRestaurantData();
   cout<<"You successfully removed the chicken dish!"<<endl;
   restaurant.getMenu().printTypedMenu(3);
   cout<<endl;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice!=1&&choice!=2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        deleteFoodItem(restaurant);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

///*************************************DELETE SOUP****************************///
void removeSoup(Restaurant restaurant){
   system("CLS");
   restaurant.printRestaurantData();
   restaurant.getMenu().printTypedMenu(2);
   unsigned int toRemove;
   cout<<"Which soup would you like to remove?"<<endl;
   cout<<"Input here: "; cin>>toRemove;
   restaurant.getMenu().getAllSoups().getSoups().removeElementAt(toRemove);
   system("CLS");
   restaurant.printRestaurantData();
   cout<<"You successfully removed the soup!"<<endl;
   restaurant.getMenu().printTypedMenu(2);
   cout<<endl;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice!=1&&choice!=2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        deleteFoodItem(restaurant);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

///*************************************DELETE SALAD****************************///
void removeSalad(Restaurant restaurant){
   system("CLS");
   restaurant.printRestaurantData();
   restaurant.getMenu().printTypedMenu(1);
   unsigned int toRemove;
   cout<<"Which salad would you like to remove?"<<endl;
   cout<<"Input here: "; cin>>toRemove;
   restaurant.getMenu().getAllSalads().getSalads().removeElementAt(toRemove);
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl<<"You successfully removed the salad!"<<endl;
   restaurant.getMenu().printTypedMenu(1);
   cout<<endl;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice!=1&&choice!=2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        deleteFoodItem(restaurant);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

///*********************************DELETE FOOD ITEM*******************************///
void deleteFoodItem(Restaurant restaurant){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   cout<<"What item type would you like to remove?"<<endl<<endl;
   cout<<"1. Salads"<<endl;
   cout<<"2. Soups"<<endl;
   cout<<"3. Chicken dishes"<<endl;
   cout<<"4. Desserts"<<endl;
   cout<<"5. Back"<<endl;
   cout<<"6. Exit"<<endl;
   int removeChoice;
   cout<<endl<<"Input choice: ";
   cin>>removeChoice;
   while(true)
	{
       if(removeChoice!=1&&removeChoice!=2&&removeChoice!=3&&removeChoice!=4&&removeChoice!=5&&removeChoice!=6){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>removeChoice; continue;}
		else
		{
			break;
		}
    }
    if(removeChoice == 1){
        removeSalad(restaurant );
    }
    else if(removeChoice == 2){
        removeSoup(restaurant);
    }
    else if(removeChoice == 3){
        removeChickenDish(restaurant);
    }
    else if(removeChoice == 4){
        removeDessert(restaurant);
    }
    else if(removeChoice == 5){
        adminMenu(restaurant);
    }
    else if(removeChoice == 6){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

///*********************************ADD NEW DESSERT************************///
void addNewDessert(Restaurant restaurant){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<"How many new desserts would you like to add?"<<endl;
   cout<<"Input here: ";
   int newCount;
   cin>>newCount;
   for(int i=0;i<newCount;i++){
      MyString pass;
      //cout<<"Input name: ";
      cin>>pass;
      MyString newName;
      cout<<"Input dessert's name: ";
      cin>>newName;
      MyArray<Ingredient> newIngredients;
      cout<<"How many ingredients would you like to add for the soup? :";
      int ingredientsNum;
      cin>>ingredientsNum;

   MyArray<Ingredient> newItemIngredients;
   for(int i=0;i<ingredientsNum;i++){
       MyString gass;
       cin>>gass;
       cout<<"Input ingredient name: ";
       MyString newName;
       cin>>newName;
       cout<<"Input ingredient quantity: ";
       double newQuantity;
       cin>>newQuantity;
       cout<<"Input ingredient market price: ";
       double newMarketPrice;
       cin>>newMarketPrice;
       Ingredient newIng(newName, newQuantity, newMarketPrice);
       newItemIngredients.addBack(newIng);
   }
      double newPrice;
      cout<<"Input dessert's price: ";
      cin>>newPrice;
      double newWeight;
      cout<<"Input dessert's weight: ";
      cin>>newWeight;
      double newCookinTime;
      cout<<"Input dessert's cooking time: ";
      cin>>newCookinTime;
      FoodItem newFoodItem(newName, newItemIngredients, newPrice, newWeight, newCookinTime);
      restaurant.getMenu().getAllDesserts().getDesserts().addBack(newFoodItem);
   }
   cout<<"Everything added."<<endl;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice!=1&&choice!=2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        addNewItem(restaurant);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}


///*********************************ADD NEW CHICKEN DISH************************///
void addNewChickenDish(Restaurant restaurant){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<"How many new chicken dishes would you like to add?"<<endl;
   cout<<"Input here: ";
   int newCount;
   cin>>newCount;
   for(int i=0;i<newCount;i++){
      MyString pass;
      //cout<<"Input name: ";
      cin>>pass;
      MyString newName;
      cout<<"Input chicken dish's name: ";
      cin>>newName;
      MyArray<Ingredient> newIngredients;
      cout<<"How many ingredients would you like to add for the soup? :";
      int ingredientsNum;
      cin>>ingredientsNum;

   MyArray<Ingredient> newItemIngredients;
   for(int i=0;i<ingredientsNum;i++){
       MyString gass;
       cin>>gass;
       cout<<"Input ingredient name: ";
       MyString newName;
       cin>>newName;
       cout<<"Input ingredient quantity: ";
       double newQuantity;
       cin>>newQuantity;
       cout<<"Input ingredient market price: ";
       double newMarketPrice;
       cin>>newMarketPrice;
       Ingredient newIng(newName, newQuantity, newMarketPrice);
       newItemIngredients.addBack(newIng);
   }
      double newPrice;
      cout<<"Input chicken dish's price: ";
      cin>>newPrice;
      double newWeight;
      cout<<"Input chicken dish's weight: ";
      cin>>newWeight;
      double newCookinTime;
      cout<<"Input chicken dish's cooking time: ";
      cin>>newCookinTime;
      FoodItem newFoodItem(newName, newItemIngredients, newPrice, newWeight, newCookinTime);
      restaurant.getMenu().getAllChickenDishes().getChickenDishes().addBack(newFoodItem);
   }
   cout<<"Everything added."<<endl;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice!=1&&choice!=2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        addNewItem(restaurant);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }

}

///*********************************ADD NEW SOUP************************///
void addNewSoup(Restaurant restaurant){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<"How many new soups would you like to add?"<<endl;
   cout<<"Input here: ";
   int newCount;
   cin>>newCount;
   for(int i=0;i<newCount;i++){
      MyString pass;
      //cout<<"Input name: ";
      cin>>pass;
      MyString newName;
      cout<<"Input soup's name: ";
      cin>>newName;
      MyArray<Ingredient> newIngredients;
      cout<<"How many ingredients would you like to add for the soup? :";
      int ingredientsNum;
      cin>>ingredientsNum;

   MyArray<Ingredient> newItemIngredients;
   for(int i=0;i<ingredientsNum;i++){
       MyString gass;
       cin>>gass;
       cout<<"Input ingredient name: ";
       MyString newName;
       cin>>newName;
       cout<<"Input ingredient quantity: ";
       double newQuantity;
       cin>>newQuantity;
       cout<<"Input ingredient market price: ";
       double newMarketPrice;
       cin>>newMarketPrice;
       Ingredient newIng(newName, newQuantity, newMarketPrice);
       newItemIngredients.addBack(newIng);
   }
      double newPrice;
      cout<<"Input soup's price: ";
      cin>>newPrice;
      double newWeight;
      cout<<"Input soup's weight: ";
      cin>>newWeight;
      double newCookinTime;
      cout<<"Input soup's cooking time: ";
      cin>>newCookinTime;
      FoodItem newFoodItem(newName, newItemIngredients, newPrice, newWeight, newCookinTime);
      restaurant.getMenu().getAllSoups().getSoups().addBack(newFoodItem);
   }
   cout<<"Everything added."<<endl;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice!=1&&choice!=2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        addNewItem(restaurant);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}


///*********************************ADD NEW SALAD************************///
void addNewSalad(Restaurant restaurant){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<"How many new salads would you like to add?"<<endl;
   cout<<"Input here: ";
   int newCount;
   cin>>newCount;
   for(int i=0;i<newCount;i++){
      MyString pass;
      //cout<<"Input name: ";
      cin>>pass;
      MyString newName;
      cout<<"Input salad's name: ";
      cin>>newName;
      MyArray<Ingredient> newIngredients;
      cout<<"How many ingredients would you like to add for the salad? :";
      int ingredientsNum;
      cin>>ingredientsNum;

   MyArray<Ingredient> newItemIngredients;
   for(int i=0;i<ingredientsNum;i++){
       MyString gass;
       cin>>gass;
       cout<<"Input ingredient name: ";
       MyString newName;
       cin>>newName;
       cout<<"Input ingredient quantity: ";
       double newQuantity;
       cin>>newQuantity;
       cout<<"Input ingredient market price: ";
       double newMarketPrice;
       cin>>newMarketPrice;
       Ingredient newIng(newName, newQuantity, newMarketPrice);
       newItemIngredients.addBack(newIng);
   }
      double newPrice;
      cout<<"Input salad's price: ";
      cin>>newPrice;
      double newWeight;
      cout<<"Input salad's weight: ";
      cin>>newWeight;
      double newCookinTime;
      cout<<"Input salad's cooking time: ";
      cin>>newCookinTime;
      FoodItem newFoodItem(newName, newItemIngredients, newPrice, newWeight, newCookinTime);
      restaurant.getMenu().getAllSalads().getSalads().addBack(newFoodItem);
   }
   cout<<"Everything added."<<endl;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice!=1&&choice!=2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        addNewItem(restaurant);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

///******************************* ADD NEW ITEM ********************///
void addNewItem(Restaurant restaurant){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   cout<<"What item type would you like to add?"<<endl<<endl;
   cout<<"1. Salads"<<endl;
   cout<<"2. Soups"<<endl;
   cout<<"3. Chicken dishes"<<endl;
   cout<<"4. Desserts"<<endl;
   cout<<"5. Back"<<endl;
   cout<<"6. Exit"<<endl;

   int typedChoice;
   cout<<endl<<"Input choice: ";
   cin>>typedChoice;
   while(true)
	{
       if(typedChoice!=1&&typedChoice!=2&&typedChoice!=3&&typedChoice!=4&&typedChoice!=5&&typedChoice!=6){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>typedChoice; continue;}
		else
		{
			break;
		}
    }
   if(typedChoice == 1){
       addNewSalad(restaurant);
   }
   else if(typedChoice == 2){
       addNewSoup(restaurant);
   }
   else if(typedChoice == 3){
       addNewChickenDish(restaurant);
   }
   else if(typedChoice == 4){
       addNewDessert(restaurant);
   }
   else if(typedChoice == 5){
       adminMenu(restaurant);
   }
   else if(typedChoice == 6){
       system("CLS");
       cout<<"You closed the program."<<endl;
   }
}

///*********************************FULL MENU PRINTING****************///
void fullMenuPrinting(Restaurant restaurant){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   cout<<endl;
   cout<<"---------------------------=MENU=------------------------------------------"<<endl<<endl;
   restaurant.getMenu().printFullMenu();
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl;
   int choice;
   cout<<"Input: ";
   cin>>choice;
   while(true)
	{
       if(choice!=1&&choice!=2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
   if(choice == 1){
      adminMenu(restaurant);
   }
   else if(choice == 2){
      system("CLS");
      cout<<"You closed the program."<<endl;
   }
}

///*********************************DESSERTS PRINTING******************///
void dessertsPrinting(Restaurant restaurant){
      system("CLS");
      restaurant.printRestaurantData();
      cout<<endl;
      restaurant.getMenu().printTypedMenu(4);
      cout<<endl;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice!=1&&choice!=2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        typedMenuPrinting(restaurant);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}


///*********************************CHICKEN DISHES PRINTING******************///
void chickenDishesPrinting(Restaurant restaurant){
      system("CLS");
      restaurant.printRestaurantData();
      cout<<endl;
      restaurant.getMenu().printTypedMenu(3);
      cout<<endl;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice!=1&&choice!=2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        typedMenuPrinting(restaurant);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}


///*********************************SOUPS PRINTING******************///
void soupsPrinting(Restaurant restaurant){
      system("CLS");
      restaurant.printRestaurantData();
      cout<<endl;
      restaurant.getMenu().printTypedMenu(2);
      cout<<endl;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice!=1&&choice!=2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        typedMenuPrinting(restaurant);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

///*********************************SALADS PRINTING******************///
void saladsPrinting(Restaurant restaurant){
      system("CLS");
      restaurant.printRestaurantData();
      cout<<endl;
      restaurant.getMenu().printTypedMenu(1);
      cout<<endl;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice!=1&&choice!=2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        typedMenuPrinting(restaurant);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

///*********************************TYPED MENU PRINTING***************///

void typedMenuPrinting(Restaurant restaurant){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   cout<<"1. Salads"<<endl;
   cout<<"2. Soups"<<endl;
   cout<<"3. Chicken dishes"<<endl;
   cout<<"4. Desserts"<<endl;
   cout<<"5. Back"<<endl;
   cout<<"6. Exit"<<endl;
   int typedChoice;
   cout<<endl<<"Input choice: ";
   cin>>typedChoice;
   while(true)
	{
       if(typedChoice!=1&&typedChoice!=2&&typedChoice!=3&&typedChoice!=4&&typedChoice!=5&&typedChoice!=6){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>typedChoice; continue;}
		else
		{
			break;
		}
    }
   if(typedChoice == 1){
         saladsPrinting(restaurant);
   }
   else if(typedChoice == 2){
       soupsPrinting(restaurant);
   }
      else if(typedChoice == 3){
        chickenDishesPrinting(restaurant);
   }
      else if(typedChoice == 4){
        dessertsPrinting(restaurant);
   }
   else if(typedChoice == 5){
      adminMenu(restaurant);
   }
   else if(typedChoice == 6){
      system("CLS");
      cout<<"You closed the program."<<endl;
   }
}


///********************************ADMIN MENU *********************///

void adminMenu(Restaurant restaurant){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   cout<<"1. Typed Menu"<<endl;
   cout<<"2. Full Menu"<<endl;
   cout<<"3. Add new item"<<endl;
   cout<<"4. Delete food item"<<endl;
   cout<<"5. Change price of item"<<endl;
   cout<<"6. Back"<<endl;
   cout<<"7. Exit"<<endl;
   int adminMenuChoice;
   cout<<endl<<"Input choice: ";
   cin>>adminMenuChoice;
    while(true)
	{
       if(adminMenuChoice!=1&&adminMenuChoice!=2&&adminMenuChoice!=3&&adminMenuChoice!=4&&adminMenuChoice!=5&&adminMenuChoice!=6&&adminMenuChoice!=7){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>adminMenuChoice; continue;}
		else
		{
			break;
		}
    }
    if(adminMenuChoice == 1){
        typedMenuPrinting(restaurant);
    }
    else if(adminMenuChoice == 2){
        fullMenuPrinting(restaurant);
    }
    else if(adminMenuChoice == 3){
         addNewItem(restaurant);
    }
    else if(adminMenuChoice == 4){
        deleteFoodItem(restaurant);
    }
    else if(adminMenuChoice == 5){
        changePrice(restaurant);
    }
    else if(adminMenuChoice == 6){
        AdminMainScreen(restaurant);
    }
    else if(adminMenuChoice == 7){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}


///********************************ADMIN MAIN SCREEN**********************///
void AdminMainScreen(Restaurant restaurant){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   cout<<"1. Check Menu"<<endl;
   cout<<"2. Check orders// still not working"<<endl;
   cout<<"3. Back"<<endl;
   cout<<"4. Exit"<<endl;
   int adminChoice;
   cout<<endl<<"Input choice: ";
   cin>>adminChoice;
    while(true)
	{
       if(adminChoice!=1&&adminChoice!=2&&adminChoice!=3&&adminChoice!=4){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>adminChoice; continue;}
		else
		{
			break;
		}
	}
	if(adminChoice == 1){
        adminMenu(restaurant);
	}
	else if(adminChoice == 2){
        //adminOrder(restaurant);//future plans
	}
	else if(adminChoice == 3){
        system("CLS");
        restaurant.printRestaurantData();
        usersInput(restaurant);
	}
	else if(adminChoice == 4){
        system("CLS");
        cout<<"You closed the program."<<endl;
	}
}


#endif // ADMIN_MENU_H_INCLUDED
