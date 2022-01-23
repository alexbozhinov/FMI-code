#ifndef EMPLOYER_MENU_H_INCLUDED
#define EMPLOYER_MENU_H_INCLUDED

#include "Budget.h"
#include "Cart.h"
#include "Ingredient.h"
#include "Item.h"
#include "Menu.h"
#include "OnlineOrder.h"
#include "Order.h"
#include "Person.h"
#include "Storage.h"
#include "Table.h"
#include "User.h"
#include<iostream>
#include<string>
#include<vector>
#include "Restaurant.h"
#include<stdlib.h>
#include "Main_Menu.h"

using namespace std;

///***FUNCTION DECLARATIONS***///
void MainMenu(Restaurant r); ///Print first page of the program and you choose which module to sign in
void EmployerMain(Restaurant r); ///First page if you choose module Employer
void EmployerSign(Restaurant r); ///Function to validate input for that module
void EmployerFirst(Restaurant r); ///First page after you successfully have signed in

void EmployerMenu(Restaurant r);  ///section menu
     void EmployerTypedMenu(Restaurant r);  ///check on menu
          void EmployerFood(Restaurant r);   ///check food items
          void EmployerDrink(Restaurant r);   ///check drink items
     void EmployerFullMenu(Restaurant r);   ///check both food and drink

     void EmployerAddItem(Restaurant r);  /// add new item to the menu
          void AddFood(Restaurant r);  ///add new food item
          void AddDrink(Restaurant r);  /// add new drink item
     void EmployerRemoveItem(Restaurant r); ///delete existing item from the menu
          void RemoveFood(Restaurant r);    ///delete existing food item
          void RemoveDrink(Restaurant r);   ///delete existing drink item
     void EmployerChangeItem(Restaurant r); ///change the price of an existing item
          void ChangeFood(Restaurant r);   ///change the price of food item
          void ChangeDrink(Restaurant r); ///change the price of drink item

void EmployerOrders(Restaurant r);
     void CheckOnline(Restaurant r);//still not working
     void CheckPlace(Restaurant r);//still not working

void EmployerEmployee(Restaurant r);///Check my Employees
     void CheckEmployee(Restaurant r); ///Personal information
          void CheckWaiter(Restaurant r);  ///info about waiters
          void CheckChef(Restaurant r);  ///info about chefs
     void AddEmployee(Restaurant r);   ///add new employees
          void AddWaiter(Restaurant r);  ///add new waiter
          void AddChef(Restaurant r);   ///add new chef
     void SackEmployee(Restaurant r);  ///sack employees
          void SackWaiter(Restaurant r); ///sack waiter
          void SackChef(Restaurant r);   ///sack chef
     void ChangeSalary(Restaurant r);   ///change salary of an employee
          void ChangeWaiter(Restaurant r); ///change salary of a waiter
          void ChangeChef(Restaurant r);///change salary of a chef

void EmployerStorage(Restaurant r);  ///Storage section
     void CheckStorage(Restaurant r);  ///view store availability

void EmployerBudget(Restaurant r); ///Budget section
     void CheckBudget(Restaurant r); ///Check Budget balance and how it changes if you do different thinks

void EmployerMain(Restaurant r){
   system("CLS");
   int choice;
   r.print();
   cout<<endl<<endl;
   cout<<"1. Sign in"<<endl;
   cout<<"2. Back"<<endl;
   cout<<"3. Exit"<<endl<<endl;
   cout<<"Input your choice: ";  cin>>choice;
   while(true)
	{
       if(choice != 1 && choice != 2 && choice != 3){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
	}
   if(choice == 1){
       EmployerSign(r);
   }
   else if(choice == 2){
       system("CLS");
       MainMenu(r);
    }
   else if(choice == 3){
       system("CLS");
       cout<<"You closed the program."<<endl;
   }
}

void EmployerSign(Restaurant r){
    system("CLS");
    r.print();
    string  u,p; int choice;
    cout<<endl;
    cout<<"1. Input username and password"<<endl;
    cout<<"2. Back"<<endl;
    cout<<"3. Exit"<<endl<<endl;
    cout<<"Input your choice: ";  cin>>choice;
    while(true)
	{
       if(choice != 1 && choice != 2 && choice != 3){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
	}
    if(choice == 1){
       cout<<endl<<"PLEASE SIGN IN"<<endl<<endl;
       cout<<"Username: "; cin>>u;
       cout<<"Password: "; cin>>p;
          while(true)
	      {
             if(u != "admin" || p != "ADMIN"){   cout<<endl<<"Incorrect input! Try again! Input username and password: "<<endl<<endl;
                                                 cout<<"Username: "; cin>>u;
                                                 cout<<"Password: "; cin>>p;
                                                 continue;
             }
		      else
		     {
			   break;
	 	     }
	     }
       if(u == "admin" && p == "ADMIN"){
          EmployerFirst(r);
       }
    }
    else if(choice == 2){
        EmployerMain(r);
    }
       else if(choice == 3){
       system("CLS");
       cout<<"You closed the program."<<endl;
   }
}

void EmployerFirst(Restaurant r){
   system("CLS");
   int choice;
   r.print();
   cout<<endl<<endl;
   cout<<"1. Menu"<<endl;
   cout<<"2. Orders"<<endl;
   cout<<"3. Employee"<<endl;
   cout<<"4. Storage"<<endl;
   cout<<"5. Budget"<<endl;
   cout<<"6. Back"<<endl;
   cout<<"7. Exit"<<endl<<endl;
   cout<<"Input your choice: ";  cin>>choice;
   while(true)
	{
       if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
	}
   if(choice == 1){
       EmployerMenu(r);
   }
   else if(choice == 2){
       EmployerOrders(r);
    }
   else if(choice == 3){
      EmployerEmployee(r);
   }
   else if(choice == 4){
      EmployerStorage(r);
   }
   else if(choice == 5){
      EmployerBudget(r);
   }
   else if(choice == 6){
     EmployerSign(r);
   }
   else if(choice == 7){
       system("CLS");
       cout<<"You closed the program."<<endl;
   }
}

void EmployerMenu(Restaurant r){
   system("CLS");
   r.print();
   cout<<endl;
   cout<<"1. Typed Menu"<<endl;
   cout<<"2. Full Menu"<<endl;
   cout<<"3. Add new item"<<endl;
   cout<<"4. Delete item"<<endl;
   cout<<"5. Change price of item"<<endl;
   cout<<"6. Back"<<endl;
   cout<<"7. Exit"<<endl;
   int choice;
   cout<<endl<<"Input choice: ";
   cin>>choice;
    while(true)
	{
       if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        EmployerTypedMenu(r);
    }
    else if(choice == 2){
        EmployerFullMenu(r);
    }
    else if(choice == 3){
        EmployerAddItem(r);
    }
    else if(choice == 4){
        EmployerRemoveItem(r);
    }
    else if(choice == 5){
        EmployerChangeItem(r);
    }
    else if(choice == 6){
        EmployerFirst(r);
    }
    else if(choice == 7){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void EmployerFullMenu(Restaurant r){
   system("CLS");
   int choice;
   r.print();
   cout<<endl;
   r.getMenu().printFull();
   cout<<endl<<endl;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl<<endl;
   cout<<"Input your choice: ";  cin>>choice;
   while(true)
	{
       if(choice != 1 && choice != 2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
	}
	if(choice == 1){
        EmployerMenu(r);
	}
    else if(choice == 2){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void EmployerTypedMenu(Restaurant r){
   system("CLS");
   r.print();
   cout<<endl;
   cout<<"1. Food"<<endl;
   cout<<"2. Drinks"<<endl;
   cout<<"3. Back"<<endl;
   cout<<"4. Exit"<<endl;
   int choice;
   cout<<endl<<"Input choice: ";
   cin>>choice;
    while(true)
	{
       if(choice != 1 && choice != 2 && choice != 3 && choice != 4){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        EmployerFood(r);
    }
    else if(choice == 2){
        EmployerDrink(r);
    }
    else if(choice == 3){
        EmployerMenu(r);
    }
    else if(choice == 4){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void EmployerFood(Restaurant r){
   system("CLS");
   int choice;
   r.print();
   cout<<endl;
   r.getMenu().printFood();
   cout<<endl<<endl;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl<<endl;
   cout<<"Input your choice: ";  cin>>choice;
   while(true)
	{
       if(choice != 1 && choice != 2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
	}
	if(choice == 1){
        EmployerTypedMenu(r);
	}
    else if(choice == 2){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void EmployerDrink(Restaurant r){
   system("CLS");
   int choice;
   r.print();
   cout<<endl;
   r.getMenu().printDrink();
   cout<<endl<<endl;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl<<endl;
   cout<<"Input your choice: ";  cin>>choice;
   while(true)
	{
       if(choice != 1 && choice != 2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
	}
	if(choice == 1){
        EmployerTypedMenu(r);
	}
    else if(choice == 2){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void EmployerAddItem(Restaurant r){
   system("CLS");
   int choice;
   r.print();
   cout<<endl;
   cout<<"1. Add food item"<<endl;
   cout<<"2. Add drink item"<<endl;
   cout<<"3. Back"<<endl;
   cout<<"4. Exit"<<endl<<endl;
   cout<<endl<<"Input choice: ";
   cin>>choice;
    while(true)
	{
       if(choice != 1 && choice != 2 && choice != 3 && choice != 4){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        AddFood(r);
    }
    else if(choice == 2){
        AddDrink(r);
    }
    else if(choice == 3){
        EmployerMenu(r);
    }
    else if(choice == 4){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void AddFood(Restaurant r){
   system("CLS");
   r.print();
   cout<<endl;
   string newName;
   cout<<"Input item's name: ";
   cin>>newName;
   double newQuantity;
   cout<<"Input item's quantity: ";
   cin>>newQuantity;
   string m; //measure
   cout<<"Input measure: ";
   cin>>m;
   Measure imm1;
   if(m == "kg") imm1 = kg;
   else if(m == "g") imm1 = g;
   else if(m == "l") imm1 = l;
   else if(m == "ml") imm1 = ml;
   else if(m == "piece") imm1 = piece;
   else if(m == "glass") imm1 = glass;
   else if(m == "bottle") imm1 = bottle;
   double newPrice;
   cout<<"Input item's price: ";
   cin>>newPrice;
   string cur; //currency;
   Currency cu1;
   if(cur == "leva") cu1 = lev;
   else if(cur == "euros") cu1 = euro;
   else if(cur == "dollars") cu1 = dollar;
   else if(cur == "pounds") cu1 = pound;
   cout<<"Input price's currency: ";
   cin>>cur;
   string newType;
   cout<<"Input item's type: ";
   cin>>newType;
   FoodType type;
   if(newType == "Salad") type = Salad;
   else if(newType == "Soup") type = Soup;
   else if(newType == "ChickenDish") type = ChickenDish;
   else if(newType == "BeefDish") type = BeefDish;
   else if(newType == "FishDish") type = FishDish;
   else if(newType == "Dessert") type = Dessert;
   Ingredient in("pasta", 240, g, 2.40, lev);
   vector<Ingredient> ing; ing.push_back(in);
   double newCookingTime;
   cout<<"Input item's cooking time: ";
   cin>>newCookingTime;
   string newRecipe;
   cout<<"Input item's recipe: ";
   cin>>newRecipe;

   FoodItem newFoodItem(newName, newQuantity, imm1, newPrice, cu1, type, ing, newCookingTime, newRecipe);
   if(type == Salad)
   r.getMenu().getFood().insert(r.getMenu().getFood().begin() + 0, newFoodItem);
   else if(type == Soup)
   r.getMenu().getFood().insert(r.getMenu().getFood().begin()+ 3, newFoodItem);
   else if(type == ChickenDish)
   r.getMenu().getFood().insert(r.getMenu().getFood().begin()+ 6, newFoodItem);
   else if(type == BeefDish)
   r.getMenu().getFood().insert(r.getMenu().getFood().begin()+ 9, newFoodItem);
   else if(type == FishDish)
   r.getMenu().getFood().insert(r.getMenu().getFood().begin()+ 12, newFoodItem);
   else if(type == Dessert)
   r.getMenu().getFood().insert(r.getMenu().getFood().begin()+ 15, newFoodItem);
   cout<<endl;
   cout<<"Everything added."<<endl<<endl;
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
        EmployerAddItem(r);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

void AddDrink(Restaurant r){
   system("CLS");
   r.print();
   cout<<endl;
   string newName;
   cout<<"Input item's name: ";
   cin>>newName;
   double newQuantity;
   cout<<"Input item's quantity: ";
   cin>>newQuantity;
   string m; //measure
   cout<<"Input measure: ";
   cin>>m;
   Measure imm1;
   if(m == "kg") imm1 = kg;
   else if(m == "g") imm1 = g;
   else if(m == "l") imm1 = l;
   else if(m == "ml") imm1 = ml;
   else if(m == "piece") imm1 = piece;
   else if(m == "glass") imm1 = glass;
   else if(m == "bottle") imm1 = bottle;
   double newPrice;
   cout<<"Input item's price: ";
   cin>>newPrice;
   string cur; //currency;
   Currency cu1;
   if(cur == "leva") cu1 = lev;
   else if(cur == "euros") cu1 = euro;
   else if(cur == "dollars") cu1 = dollar;
   else if(cur == "pounds") cu1 = pound;
   cout<<"Input price's currency: ";
   cin>>cur;
   string newType;
   cout<<"Input item's type: ";
   cin>>newType;
   DrinkType type;
   if(newType == "Juice") type = Juice;
   else if(newType == "Alcohol") type = Alcohol;
   else if(newType == "FizzyDrink") type = FizzyDrink;
   else if(newType == "SoftDrink") type = SoftDrink;
   else if(newType == "WarmDrink") type = WarmDrink;
   string newBrand;
   cout<<"Input item's brand: ";
   cin>>newBrand;
   double newDegree;
   cout<<"Input item's alcohol degree: ";
   cin>>newDegree;

   DrinkItem newDrinkItem(newName, newQuantity, imm1, newPrice, cu1, type, newBrand, newDegree);
   if(type == Juice)
   r.getMenu().getDrink().insert(r.getMenu().getDrink().begin() + 0, newDrinkItem);
   else if(type == Alcohol)
   r.getMenu().getDrink().insert(r.getMenu().getDrink().begin()+ 3, newDrinkItem);
   else if(type == FizzyDrink)
   r.getMenu().getDrink().insert(r.getMenu().getDrink().begin()+ 6, newDrinkItem);
   else if(type == SoftDrink)
   r.getMenu().getDrink().insert(r.getMenu().getDrink().begin()+ 9, newDrinkItem);
   else if(type == WarmDrink)
   r.getMenu().getDrink().insert(r.getMenu().getDrink().begin()+ 10, newDrinkItem);
   cout<<endl;
   cout<<"Everything added."<<endl<<endl;
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
        EmployerAddItem(r);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

void EmployerRemoveItem(Restaurant r){
   system("CLS");
   int choice;
   r.print();
   cout<<endl;
   cout<<"1. Remove food item"<<endl;
   cout<<"2. Remove drink item"<<endl;
   cout<<"3. Back"<<endl;
   cout<<"4. Exit"<<endl<<endl;
   cout<<endl<<"Input choice: ";
   cin>>choice;
    while(true)
	{
       if(choice != 1 && choice != 2 && choice != 3 && choice != 4){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        RemoveFood(r);
    }
    else if(choice == 2){
        RemoveDrink(r);
    }
    else if(choice == 3){
        EmployerMenu(r);
    }
    else if(choice == 4){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void RemoveFood(Restaurant r){
   system("CLS");
   r.print();
   r.getMenu().printFood();
   int toRemove;
   cout<<endl<<"Which food item would you like to remove?"<<endl;
   cout<<"Input here: "; cin>>toRemove;
   r.getMenu().getFood().erase(r.getMenu().getFood().begin() + toRemove - 1);
   system("CLS");
   r.print();
   cout<<endl<<"You successfully removed the item!"<<endl<<endl;
   r.getMenu().printFood();
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
        EmployerRemoveItem(r);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

void RemoveDrink(Restaurant r){
   system("CLS");
   r.print();
   r.getMenu().printDrink();
   int toRemove;
   cout<<endl<<"Which drink item would you like to remove?"<<endl;
   cout<<"Input here: "; cin>>toRemove;
   r.getMenu().getDrink().erase(r.getMenu().getDrink().begin() + toRemove - 1);
   system("CLS");
   r.print();
   cout<<endl<<"You successfully removed the item!"<<endl<<endl;
   r.getMenu().printDrink();
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
        EmployerRemoveItem(r);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

void EmployerChangeItem(Restaurant r){
   system("CLS");
   r.print();
   cout<<endl;
   cout<<"What item type would you like to change the price of?"<<endl<<endl;
   cout<<"1. Food"<<endl;
   cout<<"2. Drink"<<endl;
   cout<<"3. Back"<<endl;
   cout<<"4. Exit"<<endl;
   int choice;
   cout<<endl<<"Input choice: ";
   cin>>choice;
   while(true)
	{
       if(choice != 1 && choice != 2 && choice != 3 && choice != 4){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        ChangeFood(r);
    }
    else if(choice == 2){
        ChangeDrink(r);
    }
    else if(choice == 3){
        EmployerMenu(r);
    }
    else if(choice == 4){
        system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

void ChangeFood(Restaurant r){
   system("CLS");
   r.print();
   cout<<endl;
   r.getMenu().printFood();
   int toChange;
   cout<<endl<<"Of which food item would you like to change the price?"<<endl<<endl;
   cout<<"Input here: "; cin>>toChange;
   cout<<endl<<"Input new price: ";
   double newPrice;
   cin>>newPrice;
   r.getMenu().getFood()[toChange - 1].setPrice(newPrice);
   system("CLS");
   r.print();
   cout<<endl;
   cout<<"You successfully changed the price of the item!"<<endl;
   r.getMenu().printFood();
   cout<<endl;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice != 1 && choice != 2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        EmployerChangeItem(r);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

void ChangeDrink(Restaurant r){
   system("CLS");
   r.print();
   cout<<endl;
   r.getMenu().printDrink();
   int toChange;
   cout<<endl<<"Of which drink item would you like to change the price?"<<endl<<endl;
   cout<<"Input here: "; cin>>toChange;
   cout<<endl<<"Input new price: ";
   double newPrice;
   cin>>newPrice;
   r.getMenu().getDrink()[toChange - 1].setPrice(newPrice);
   system("CLS");
   r.print();
   cout<<endl;
   cout<<"You successfully changed the price of the item!"<<endl;
   r.getMenu().printDrink();
   cout<<endl;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice != 1 && choice != 2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        EmployerChangeItem(r);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

void EmployerEmployee(Restaurant r){
   system("CLS");
   r.print();
   cout<<endl;
   cout<<"1. Check Employee"<<endl;
   cout<<"2. Add Employee"<<endl;
   cout<<"3. Sack Employee"<<endl;
   cout<<"4. Change salary"<<endl;
   cout<<"5. Back"<<endl;
   cout<<"6. Exit"<<endl;
   int choice;
   cout<<endl<<"Input choice: ";
   cin>>choice;
    while(true)
	{
       if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        CheckEmployee(r);
    }
    else if(choice == 2){
        AddEmployee(r);
    }
    else if(choice == 3){
        SackEmployee(r);
    }
    else if(choice == 4){
        ChangeSalary(r);
    }
    else if(choice == 5){
        EmployerFirst(r);
    }
    else if(choice == 6){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void CheckEmployee(Restaurant r){
   system("CLS");
   r.print();
   cout<<endl;
   cout<<"Which employee would you like to check?"<<endl<<endl;
   cout<<"1. Waiters"<<endl;
   cout<<"2. Chefs"<<endl;
   cout<<"3. Back"<<endl;
   cout<<"4. Exit"<<endl;
   int choice;
   cout<<endl<<"Input choice: ";
   cin>>choice;
   while(true)
	{
       if(choice != 1 && choice != 2 && choice != 3 && choice != 4){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        CheckWaiter(r);
    }
    else if(choice == 2){
        CheckChef(r);
    }
    else if(choice == 3){
        EmployerEmployee(r);
    }
    else if(choice == 4){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

void CheckWaiter(Restaurant r){
   system("CLS");
   int choice;
   r.print();
   cout<<endl;
   r.printWaiters();
   cout<<endl<<endl;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl<<endl;
   cout<<"Input your choice: ";  cin>>choice;
   while(true)
	{
       if(choice != 1 && choice != 2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
	}
	if(choice == 1){
        CheckEmployee(r);
	}
    else if(choice == 2){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void CheckChef(Restaurant r){
   system("CLS");
   int choice;
   r.print();
   cout<<endl;
   r.printChefs();
   cout<<endl<<endl;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl<<endl;
   cout<<"Input your choice: ";  cin>>choice;
   while(true)
	{
       if(choice != 1 && choice != 2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
	}
	if(choice == 1){
        CheckEmployee(r);
	}
    else if(choice == 2){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void AddEmployee(Restaurant r){
   system("CLS");
   r.print();
   cout<<endl;
   cout<<"What type of employee would you like to add?"<<endl<<endl;
   cout<<"1. Waiters"<<endl;
   cout<<"2. Chefs"<<endl;
   cout<<"3. Back"<<endl;
   cout<<"4. Exit"<<endl;
   int choice;
   cout<<endl<<"Input choice: ";
   cin>>choice;
   while(true)
	{
       if(choice != 1 && choice != 2 && choice != 3 && choice != 4){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        AddWaiter(r);
    }
    else if(choice == 2){
        AddChef(r);
    }
    else if(choice == 3){
        EmployerEmployee(r);
    }
    else if(choice == 4){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

void AddWaiter(Restaurant r){
   system("CLS");
   r.print();
   cout<<endl;
   string newName;
   cout<<"Input waiter's name: ";
   cin>>newName;
   string newEgn;
   cout<<"Input waiter's egn: ";
   cin>>newEgn;
   string newUsername;
   cout<<"Input waiter's username: ";
   cin>>newUsername;
   string newPassword;
   cout<<"Input waiter's password: ";
   cin>>newPassword;
   double newSalary;
   cout<<"Input waiter's salary: ";
   cin>>newSalary;
   string cur; //currency;
   Currency cu1;
   cout<<"Input currency: ";
   cin>>cur;
   if(cur == "leva") cu1 = lev;
   else if(cur == "euros") cu1 = euro;
   else if(cur == "dollars") cu1 = dollar;
   else if(cur == "pounds") cu1 = pound;
   double newWorkHours;
   cout<<"Input waiter's working hours: ";
   cin>>newWorkHours;
   Table T(8,6,Rectangle);
   vector<Table> newTable; newTable.push_back(T);
   double newCapital;
   cout<<"Input waiter's working capital: ";
   cin>>newCapital;

   Waiter newWaiter(newName, newEgn, newUsername, newPassword, newSalary, cu1, newWorkHours, newTable, newCapital);

   r.getWaiters().push_back(newWaiter);

   r.getBudget().getSalaryOutcome() += newWaiter.getSalary();
   r.getBudget().setBalance(r.getBudget().getIngredientOutcome(), r.getBudget().getSalaryOutcome(), r.getBudget().getOnlineIncome(), r.getBudget().getPlaceIncome());

   cout<<endl;
   cout<<"Waiter added."<<endl<<endl;
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
        AddEmployee(r);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

void AddChef(Restaurant r){
   system("CLS");
   r.print();
   cout<<endl;
   string newName;
   cout<<"Input chef's name: ";
   cin>>newName;
   string newEgn;
   cout<<"Input chef's egn: ";
   cin>>newEgn;
   string newUsername;
   cout<<"Input chef's username: ";
   cin>>newUsername;
   string newPassword;
   cout<<"Input chef's password: ";
   cin>>newPassword;
   double newSalary;
   cout<<"Input chef's salary: ";
   cin>>newSalary;
   string cur; //currency;
   Currency cu1;
   cout<<"Input currency: ";
   cin>>cur;
   if(cur == "leva") cu1 = lev;
   else if(cur == "euros") cu1 = euro;
   else if(cur == "dollars") cu1 = dollar;
   else if(cur == "pounds") cu1 = pound;
   double newWorkHours;
   cout<<"Input chef's working hours: ";
   cin>>newWorkHours;
   string chefType;
   cout<<"Input chef's type: ";
   cin>>chefType;
   ChefType type;
   if(chefType == "Executive") type = Executive;
   else if(chefType == "Sous") type = Sous;
   else if(chefType == "Senior") type = Senior;
   else if(chefType == "Sauce") type = Sauce;
   else if(chefType == "Fish") type = Fish;
   else if(chefType == "Confectioner") type = Confectioner;

   Chef newChef(newName, newEgn, newUsername, newPassword, newSalary, cu1, newWorkHours, type);

   r.getChefs().push_back(newChef);
   r.getBudget().getSalaryOutcome() += newChef.getSalary();
   r.getBudget().setBalance(r.getBudget().getIngredientOutcome(), r.getBudget().getSalaryOutcome(), r.getBudget().getOnlineIncome(), r.getBudget().getPlaceIncome());

   cout<<endl;
   cout<<"Chef added."<<endl<<endl;
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
        AddEmployee(r);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

void SackEmployee(Restaurant r){
   system("CLS");
   int choice;
   r.print();
   cout<<endl;
   cout<<"1. Sack Waiter"<<endl;
   cout<<"2. Sack Chef"<<endl;
   cout<<"3. Back"<<endl;
   cout<<"4. Exit"<<endl<<endl;
   cout<<endl<<"Input choice: ";
   cin>>choice;
    while(true)
	{
       if(choice != 1 && choice != 2 && choice != 3 && choice != 4){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        SackWaiter(r);
    }
    else if(choice == 2){
        SackChef(r);
    }
    else if(choice == 3){
        EmployerEmployee(r);
    }
    else if(choice == 4){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void SackWaiter(Restaurant r){
   system("CLS");
   r.print();
   r.printWaiters();
   int toRemove;
   cout<<endl<<"Which waiter would you like to sack?"<<endl;
   cout<<"Input here: "; cin>>toRemove;
   r.getWaiters().erase(r.getWaiters().begin() + toRemove - 1);
   r.getBudget().getSalaryOutcome() -= r.getWaiters()[toRemove - 1].getSalary();
   r.getBudget().setBalance(r.getBudget().getIngredientOutcome(), r.getBudget().getSalaryOutcome(), r.getBudget().getOnlineIncome(), r.getBudget().getPlaceIncome());

   system("CLS");
   r.print();
   cout<<endl<<"You successfully sacked a waiter!"<<endl<<endl;
   r.printWaiters();
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
        SackEmployee(r);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

void SackChef(Restaurant r){
   system("CLS");
   r.print();
   r.printChefs();
   int toRemove;
   cout<<endl<<"Which chef would you like to sack?"<<endl;
   cout<<"Input here: "; cin>>toRemove;
   r.getChefs().erase(r.getChefs().begin() + toRemove - 1);
   r.getBudget().getSalaryOutcome() -= r.getChefs()[toRemove - 1].getSalary();
   r.getBudget().setBalance(r.getBudget().getIngredientOutcome(), r.getBudget().getSalaryOutcome(), r.getBudget().getOnlineIncome(), r.getBudget().getPlaceIncome());

   system("CLS");
   r.print();
   cout<<endl<<"You successfully sacked a chef!"<<endl<<endl;
   r.printChefs();
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
        SackEmployee(r);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

void ChangeSalary(Restaurant r){
   system("CLS");
   r.print();
   cout<<endl;
   cout<<"What employee type would you like to change the salary of?"<<endl<<endl;
   cout<<"1. Waiter"<<endl;
   cout<<"2. Chef"<<endl;
   cout<<"3. Back"<<endl;
   cout<<"4. Exit"<<endl;
   int choice;
   cout<<endl<<"Input choice: ";
   cin>>choice;
   while(true)
	{
       if(choice != 1 && choice != 2 && choice != 3 && choice != 4){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        ChangeWaiter(r);
    }
    else if(choice == 2){
        ChangeChef(r);
    }
    else if(choice == 3){
        EmployerEmployee(r);
    }
    else if(choice == 4){
        system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

void ChangeWaiter(Restaurant r){
   system("CLS");
   r.print();
   cout<<endl;
   r.printWaiters();
   int toChange;
   cout<<endl<<"Of which waiter would you like to change the salary?"<<endl<<endl;
   cout<<"Input here: "; cin>>toChange;
   cout<<endl<<"Input new salary: ";
   r.getBudget().getSalaryOutcome() -= r.getWaiters()[toChange - 1].getSalary();
   r.getBudget().setBalance(r.getBudget().getIngredientOutcome(), r.getBudget().getSalaryOutcome(), r.getBudget().getOnlineIncome(), r.getBudget().getPlaceIncome());

   double newSalary;
   cin>>newSalary;
   r.getWaiters()[toChange - 1].setSalary(newSalary);
   r.getBudget().getSalaryOutcome() += newSalary;
   r.getBudget().setBalance(r.getBudget().getIngredientOutcome(), r.getBudget().getSalaryOutcome(), r.getBudget().getOnlineIncome(), r.getBudget().getPlaceIncome());
   system("CLS");
   r.print();
   cout<<endl;
   cout<<"You successfully changed the salary of the waiter!"<<endl;
   r.printWaiters();
   cout<<endl;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice != 1 && choice != 2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        ChangeSalary(r);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

void ChangeChef(Restaurant r){
   system("CLS");
   r.print();
   cout<<endl;
   r.printChefs();
   int toChange;
   cout<<endl<<"Of which chef would you like to change the salary?"<<endl<<endl;
   cout<<"Input here: "; cin>>toChange;
   cout<<endl<<"Input new salary: ";
   r.getBudget().getSalaryOutcome() -= r.getChefs()[toChange - 1].getSalary();
   r.getBudget().setBalance(r.getBudget().getIngredientOutcome(), r.getBudget().getSalaryOutcome(), r.getBudget().getOnlineIncome(), r.getBudget().getPlaceIncome());

   double newSalary;
   cin>>newSalary;
   r.getChefs()[toChange - 1].setSalary(newSalary);
   r.getBudget().getSalaryOutcome() += newSalary;
   r.getBudget().setBalance(r.getBudget().getIngredientOutcome(), r.getBudget().getSalaryOutcome(), r.getBudget().getOnlineIncome(), r.getBudget().getPlaceIncome());
   system("CLS");
   r.print();
   cout<<endl;
   cout<<"You successfully changed the salary of the waiter!"<<endl;
   r.printChefs();
   cout<<endl;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice != 1 && choice != 2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        ChangeSalary(r);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

void EmployerStorage(Restaurant r){
   system("CLS");
   r.print();
   cout<<endl;
   cout<<"1. Check Storage"<<endl;
   cout<<"2. Buy Ingredients - still not working!!!"<<endl;
   cout<<"3. Back"<<endl;
   cout<<"4. Exit"<<endl;
   int choice;
   cout<<endl<<"Input choice: ";
   cin>>choice;
    while(true)
	{
       if(choice != 1 && choice != 2 && choice != 3 && choice != 4 ){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        CheckStorage(r);
    }
    else if(choice == 2){
        //BuyIngredients(r);
    }
    else if(choice == 3){
        EmployerFirst(r);
    }
    else if(choice == 4){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void CheckStorage(Restaurant r){
   system("CLS");
   int choice;
   r.print();
   cout<<endl;
   r.getStorage().print();
   cout<<endl<<endl;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl<<endl;
   cout<<"Input your choice: ";  cin>>choice;
   while(true)
	{
       if(choice != 1 && choice != 2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
	}
	if(choice == 1){
        EmployerStorage(r);
	}
    else if(choice == 2){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void EmployerBudget(Restaurant r){
   system("CLS");
   r.print();
   cout<<endl;
   cout<<"1. Check Restaurant's Budget"<<endl;
   cout<<"2. Back"<<endl;
   cout<<"3. Exit"<<endl;
   int choice;
   cout<<endl<<"Input choice: ";
   cin>>choice;
    while(true)
	{
       if(choice != 1 && choice != 2 && choice != 3){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        CheckBudget(r);
    }
    else if(choice == 2){
        EmployerFirst(r);
    }
    else if(choice == 3){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void CheckBudget(Restaurant r){
   system("CLS");
   int choice;
   r.print();
   cout<<endl;
   r.getBudget().print();
   cout<<endl<<endl;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl<<endl;
   cout<<"Input your choice: ";  cin>>choice;
   while(true)
	{
       if(choice != 1 && choice != 2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
	}
	if(choice == 1){
        EmployerBudget(r);
	}
    else if(choice == 2){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void EmployerOrders(Restaurant r){
   system("CLS");
   r.print();
   cout<<endl;
   cout<<"1. Online Orders"<<endl;
   cout<<"2. Restaurant Orders"<<endl;
   cout<<"3. Back"<<endl;
   cout<<"4. Exit"<<endl;
   int choice;
   cout<<endl<<"Input choice: ";
   cin>>choice;
    while(true)
	{
       if(choice != 1 && choice != 2 && choice != 3 && choice != 4){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        //CheckOnline(r);
    }
    else if(choice == 2){
        //CheckPlace(r);
    }

    else if(choice == 3){
        EmployerFirst(r);
    }
    else if(choice == 4){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}


#endif // EMPLOYER_MENU_H_INCLUDED
