#ifndef EMPLOYEE_MENU_H_INCLUDED
#define EMPLOYEE_MENU_H_INCLUDED

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

void MainMenu(Restaurant r); ///first program page
void EmployeeMain(Restaurant r);///first page of module Employee
void WaiterSign(Restaurant r); ///Sign in function for waiters
     void WaiterFirst(Restaurant r, string u);///first page of module waiters after successful sign in
          void WaiterInformation(Restaurant r, string u); ///waiter check personal information
          void StartOrder(Restaurant r, string u);///waiter making order in the restaurant
               void ChooseTable(Restaurant r, string u);/// waiter choose table from his table list
                    void TableOrder(Restaurant r, string u, int number);///making order for the number previously chosen
                         void AddFood(Restaurant r, string u, int number);///add food item to the order of the table
                         void AddDrink(Restaurant r, string u, int number);///add drink item to the order of the table
                    void WaiterFinal(Restaurant r, string u);///page to finish the order
                        void TableFinal(Restaurant r, string u, int number);///choose of which table to finish the order
                             void ConfirmOrder(Restaurant r, string u, int number);///confirm order !!! In readme.txt I have described what problems I have when confirming order in module waiter
                             void RemoveItem(Restaurant r, string u, int number);///Waiter can change the order, removing items
                                  void RemoveFood(Restaurant r, string u,int number);///remove food item from order
                                  void RemoveDrink(Restaurant r, string u, int number);///remove frink item from order
void ChefSign(Restaurant r);///Sign in function for chefs
     void ChefFirst(Restaurant r, string u);///first page of module chef
          void ChefInformation(Restaurant r, string u);///check personal information
          void ChefRecipes(Restaurant r, string u);///check on recipes of item that you choose
          void ChefStorage(Restaurant r, string u);///Option to see the storage
              void CheckStorage(Restaurant r, string u);///Check storage availability

void EmployeeMain(Restaurant r){
   system("CLS");
   int choice;
   r.print();
   cout<<endl<<endl;
   cout<<"1. Waiter"<<endl;
   cout<<"2. Chef"<<endl;
   cout<<"3. Back"<<endl;
   cout<<"4. Exit"<<endl<<endl;
   cout<<"Input your choice: ";  cin>>choice;
   while(true)
	{
       if(choice != 1 && choice != 2 && choice != 3 && choice != 4){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
	}
   if(choice == 1){
       WaiterSign(r);
   }
   else if(choice == 2){
       ChefSign(r);
   }
   else if(choice == 3){
       system("CLS");
       MainMenu(r);
    }
   else if(choice == 4){
       system("CLS");
       cout<<"You closed the program."<<endl;
   }
}

void WaiterSign(Restaurant r){
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
       int countMistakes = 0;
          while(true)
	      {
            for(int i = 0;i<r.getWaiters().size();i++)
             if(u != r.getWaiters()[i].getUsername() || p != r.getWaiters()[i].getPassword() ){
                countMistakes++;
             }

         if(countMistakes == r.getWaiters().size())
                {   cout<<endl<<"Incorrect input! Try again! Input username and password: "<<endl<<endl;
                                                 cout<<"Username: "; cin>>u;
                                                 cout<<"Password: "; cin>>p;
                                                 continue;
                }
		      else
		         {
			       break;
	 	          }
	      }

    WaiterFirst(r,u);
    }
    else if(choice == 2){
        EmployeeMain(r);
    }
       else if(choice == 3){
       system("CLS");
       cout<<"You closed the program."<<endl;
   }
}

void ChefSign(Restaurant r){
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
       int countMistakes = 0;
          while(true)
	      {
            for(int i = 0;i<r.getChefs().size();i++)
             if(u != r.getChefs()[i].getUsername() || p != r.getChefs()[i].getPassword() ){
                countMistakes++;
             }

         if(countMistakes == r.getChefs().size())
                {   cout<<endl<<"Incorrect input! Try again! Input username and password: "<<endl<<endl;
                                                 cout<<"Username: "; cin>>u;
                                                 cout<<"Password: "; cin>>p;
                                                 continue;
                }
		      else
		         {
			       break;
	 	          }
	      }
    ChefFirst(r, u);
    }
    else if(choice == 2){
        EmployeeMain(r);
    }
       else if(choice == 3){
       system("CLS");
       cout<<"You closed the program."<<endl;
   }
}

void ChefFirst(Restaurant r, string u){
   system("CLS");
   int choice;
   r.print();
   cout<<endl<<endl;
   cout<<"1. Personal Information"<<endl;
   cout<<"2. Check recipes"<<endl;
   cout<<"3. Storage"<<endl;
   cout<<"4. Back"<<endl;
   cout<<"5. Exit"<<endl<<endl;
   cout<<"Input your choice: ";  cin>>choice;
   while(true)
	{
       if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
	}
   if(choice == 1){
       ChefInformation(r, u);
   }
   else if(choice == 2){
       ChefRecipes(r,u);
    }
   else if(choice == 3){
      ChefStorage(r,u);
   }
   else if(choice == 4){
      ChefSign(r);
   }
   else if(choice == 5){
       system("CLS");
       cout<<"You closed the program."<<endl;
   }
}

void ChefInformation(Restaurant r, string u){
   system("CLS");
   int choice;
   r.print();
   cout<<endl<<endl;
   for(int i=0;i<r.getChefs().size();i++){
      if(r.getChefs()[i].getUsername() == u){
        cout<<"_____PERSONL INFORMATION_____________________________"<<endl;
        r.getChefs()[i].printPersonalInformation();
      }
   }
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
        ChefFirst(r,u);
	}
    else if(choice == 2){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void ChefRecipes(Restaurant r, string u){
   system("CLS");
   r.print();
   r.getMenu().printFood();
   int toCheck;
   cout<<endl<<"Which food item would you like to check the recipe?"<<endl;
   cout<<"Input here: "; cin>>toCheck;
   system("CLS");
   r.print();
   cout<<endl<<"_____CHECK RECIPE_______________________"<<endl<<endl;
   cout<<r.getMenu().getFood()[toCheck-1].getRecipe()<<endl;
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
        ChefFirst(r,u);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

void ChefStorage(Restaurant r, string u){
   system("CLS");
   r.print();
   cout<<endl;
   cout<<"1. Check Storage"<<endl;
   cout<<"2. Make a Request for Ingredients - still not working!!!"<<endl;
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
        CheckStorage(r,u);
    }
    else if(choice == 2){
        //MakeRequest(r);
    }
    else if(choice == 3){
        ChefFirst(r,u);
    }
    else if(choice == 4){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void CheckStorage(Restaurant r, string u){
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
        ChefStorage(r, u);
	}
    else if(choice == 2){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void WaiterFirst(Restaurant r, string u){
   system("CLS");
   int choice;
   r.print();
   cout<<endl<<endl;
   cout<<"1. Personal Information"<<endl;
   cout<<"2. Start Order"<<endl;
   cout<<"3. Back"<<endl;
   cout<<"4. Exit"<<endl<<endl;
   cout<<"Input your choice: ";  cin>>choice;
   while(true)
	{
       if(choice != 1 && choice != 2 && choice != 3 && choice != 4){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
	}
   if(choice == 1){
       WaiterInformation(r, u);
   }
   else if(choice == 2){
       StartOrder(r,u);
    }
   else if(choice == 3){
      WaiterSign(r);
   }
   else if(choice == 4){
       system("CLS");
       cout<<"You closed the program."<<endl;
   }
}

void WaiterInformation(Restaurant r, string u){
   system("CLS");
   int choice;
   r.print();
   cout<<endl<<endl;
   for(int i=0;i<r.getWaiters().size();i++){
      if(r.getWaiters()[i].getUsername() == u){
        cout<<"_____PERSONL INFORMATION_____________________________"<<endl;
        r.getWaiters()[i].printPersonalInformation();
      }
   }
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
        WaiterFirst(r,u);
	}
    else if(choice == 2){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void StartOrder(Restaurant r, string u){
   system("CLS");
   int choice;
   r.print();
   cout<<endl<<endl;
   cout<<"1. Table"<<endl;
   cout<<"2. Finish Order"<<endl;
   cout<<"3. Back"<<endl;
   cout<<"4. Exit"<<endl<<endl;
   cout<<"Input your choice: ";  cin>>choice;
   while(true)
	{
       if(choice != 1 && choice != 2 && choice != 3 && choice != 4){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
	}
	if(choice == 1){
        ChooseTable(r, u);
	}
	else if(choice == 2){
        WaiterFinal(r, u);
	}
	else if(choice == 3){
        WaiterFirst(r,u);
	}
    else if(choice == 4){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void ChooseTable(Restaurant r, string u){
   system("CLS");
   r.print();
   cout<<endl;
   for(int i = 0;i< r.getWaiters().size();i++){
       if(r.getWaiters()[i].getUsername() == u){
             for(int j=0; j<r.getWaiters()[i].getTables().size(); j++){
              cout<<"Table No: ";
              cout<<r.getWaiters()[i].getTables()[j].getNumber();
              cout<<endl<<endl;
             }
       }
   }
   int toStart;
   cout<<endl<<"Of which table would you like to start an order?"<<endl;
   cout<<"Input here: "; cin>>toStart;

   TableOrder(r, u, toStart);
}

void TableOrder(Restaurant r, string u, int number){
   system("CLS");
   r.print();
   cout<<endl;
   cout<<"What type of products would you like to add? "<<endl<<endl;
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
        AddFood(r, u, number);
    }
    else if(choice == 2){
        AddDrink(r, u, number);
    }
    else if(choice == 3){
        StartOrder(r, u);
    }
    else if(choice == 4){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void AddFood(Restaurant r, string u, int number){
   system("CLS");
   r.print();
   cout<<endl;
   r.getMenu().printFood();
   int toAdd, howMany;
   cout<<endl<<"Which food item would you like to add to the cart?"<<endl;
   cout<<"Input here: "; cin>>toAdd;
   cout<<"Input count: ";cin>>howMany;
   for(int i = 0;i< r.getWaiters().size();i++){
       if(r.getWaiters()[i].getUsername() == u){
           for(int j=0;j<howMany;j++){
               r.getWaiters()[i].getTables()[number-1].getOrder().getFood().push_back(r.getMenu().getFood()[toAdd-1]);
          }
       }
   }
   cout<<endl<<"Food item/s added!"<<endl<<endl;
   cout<<"1. Continue adding food"<<endl;
   cout<<"2. Back"<<endl;
   cout<<"3. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
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
        AddFood(r,u,number);
    }
    else if(choice == 2){
        TableOrder(r, u, number);
    }
    else if(choice == 3){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

void AddDrink(Restaurant r, string u, int number){
   system("CLS");
   r.print();
   cout<<endl;
   r.getMenu().printDrink();
   int toAdd, howMany;
   cout<<endl<<"Which drink item would you like to add to the cart?"<<endl;
   cout<<"Input here: "; cin>>toAdd;
   cout<<"Input count: ";cin>>howMany;
   for(int i = 0;i< r.getWaiters().size();i++){
       if(r.getWaiters()[i].getUsername() == u){
           for(int j=0;j<howMany;j++){
               r.getWaiters()[i].getTables()[number-1].getOrder().getDrink().push_back(r.getMenu().getDrink()[toAdd-1]);
          }
       }
   }
   cout<<endl<<"Drink item/s added!"<<endl<<endl;
   cout<<"1. Continue adding drinks"<<endl;
   cout<<"2. Back"<<endl;
   cout<<"3. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
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
        AddDrink(r,u,number);
    }
    else if(choice == 2){
        TableOrder(r, u, number);
    }
    else if(choice == 3){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

void WaiterFinal(Restaurant r, string u){
   system("CLS");
   r.print();
   cout<<endl;
   for(int i = 0;i< r.getWaiters().size();i++){
       if(r.getWaiters()[i].getUsername() == u){
             for(int j=0; j<r.getWaiters()[i].getTables().size(); j++){
              cout<<"Table No: ";
              cout<<r.getWaiters()[i].getTables()[j].getNumber();
              cout<<endl<<endl;
             }
       }
   }
   int toStart;
   cout<<endl<<"Of which table would you like to finish the order?"<<endl;
   cout<<"Input here: "; cin>>toStart;

   TableFinal(r, u, toStart);
}

void TableFinal(Restaurant r, string u, int number){
   system("CLS");
   r.print();
   cout<<endl;
   for(int i = 0;i< r.getWaiters().size();i++){
       if(r.getWaiters()[i].getUsername() == u){
              r.getWaiters()[i].getTables()[number-1].getOrder().print();
       }
   }
   cout<<endl;
   cout<<"1. Confirm Order"<<endl;
   cout<<"2. Remove Item"<<endl;
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
        ConfirmOrder(r, u, number);
    }
    else if(choice == 2){
        RemoveItem(r, u, number);
    }
    else if(choice == 3){
        StartOrder(r, u);
    }
    else if(choice == 4){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void ConfirmOrder(Restaurant r, string u, int number){
   system("CLS");
   r.print();
   cout<<endl;
   for(int i = 0;i< r.getWaiters().size();i++){
       if(r.getWaiters()[i].getUsername() == u){
                 cout<<endl<<"Order confirmed!"<<endl<<endl;
                 for(int k=0;k<r.getWaiters()[i].getTables()[number - 1].getOrder().getFood().size();k++){
                        r.getBudget().getPlaceIncome() += r.getWaiters()[i].getTables()[number -1].getOrder().getFood()[k].getPrice();
                        //cout<<k<<endl;
                 }
                 for(int k=0;k<r.getWaiters()[i].getTables()[number - 1].getOrder().getDrink().size();k++){
                        r.getBudget().getPlaceIncome() += r.getWaiters()[i].getTables()[number -1].getOrder().getDrink()[k].getPrice();
                 }
                 r.getBudget().setBalance(r.getBudget().getIngredientOutcome(), r.getBudget().getSalaryOutcome(), r.getBudget().getOnlineIncome(), r.getBudget().getPlaceIncome());
/*
              vector<FoodItem> newFood;
              vector<DrinkItem> newDrink;
              r.getWaiters()[i].getTables()[number -1].getOrder() = Order(newFood, newDrink);
*/
       }
   }
   cout<<endl<<"1. Back"<<endl;
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
        TableFinal(r,u,number);
    }

    else if(choice == 3){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

void RemoveItem(Restaurant r, string u, int number){
   system("CLS");
   r.print();
   cout<<endl;
   for(int i = 0;i< r.getWaiters().size();i++){
       if(r.getWaiters()[i].getUsername() == u){
              r.getWaiters()[i].getTables()[number-1].getOrder().print();
       }
   }
   cout<<endl;
   cout<<"1. Remove food item"<<endl;
   cout<<"2. Remove drink item"<<endl;
   cout<<"3. Back"<<endl;
   cout<<"4. Exit"<<endl<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
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
        RemoveFood(r, u, number);
    }
    else if(choice == 2){
        RemoveDrink(r, u, number);
    }
    else if(choice == 3){
        TableFinal(r, u, number);
    }
    else if(choice == 4){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void RemoveFood(Restaurant r, string u, int number){
   system("CLS");
   r.print();
   for(int i = 0;i< r.getWaiters().size();i++){
       if(r.getWaiters()[i].getUsername() == u){
              r.getWaiters()[i].getTables()[number-1].getOrder().print();
       }
   }
   int toRemove;
   cout<<endl<<"Which food item would you like to remove?"<<endl;
   cout<<"Input here: "; cin>>toRemove;
   for(int i = 0;i< r.getWaiters().size();i++){
       if(r.getWaiters()[i].getUsername() == u){
              r.getWaiters()[i].getTables()[number-1].getOrder().getFood().erase(r.getWaiters()[i].getTables()[number-1].getOrder().getFood().begin() + toRemove - 1);
       }
   }
   system("CLS");
   r.print();
   cout<<endl<<"You successfully removed the item!"<<endl<<endl;
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
       RemoveItem(r, u, number);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

void RemoveDrink(Restaurant r, string u, int number){
   system("CLS");
   r.print();
   for(int i = 0;i< r.getWaiters().size();i++){
       if(r.getWaiters()[i].getUsername() == u){
              r.getWaiters()[i].getTables()[number-1].getOrder().print();
       }
   }
   int toRemove;
   cout<<endl<<"Which drink item would you like to remove?"<<endl;
   cout<<"Input here: "; cin>>toRemove;
   for(int i = 0;i< r.getWaiters().size();i++){
       if(r.getWaiters()[i].getUsername() == u){
              r.getWaiters()[i].getTables()[number-1].getOrder().getDrink().erase(r.getWaiters()[i].getTables()[number-1].getOrder().getDrink().begin() + toRemove - 1);
       }
   }
   system("CLS");
   r.print();
   cout<<endl<<"You successfully removed the item!"<<endl<<endl;
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
       RemoveItem(r, u, number);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

#endif // EMPLOYEE_MENU_H_INCLUDED
