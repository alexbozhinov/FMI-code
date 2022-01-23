#ifndef MAIN_MENU_H_INCLUDED
#define MAIN_MENU_H_INCLUDED

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
#include "Employer_Menu.h"
#include "Employee_Menu.h"
#include "Client_Menu.h"

using namespace std;

void MainMenu(Restaurant r){
   int choice;
   r.print();
   cout<<endl<<endl;
   cout<<"1. Employer"<<endl;
   cout<<"2. Employee"<<endl;
   cout<<"3. Client"<<endl;
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
       EmployerMain(r);
   }
   else if(choice == 2){
       EmployeeMain(r);
    }
   else if(choice == 3){
       ClientMain(r);
   }
   else if(choice == 4){
       system("CLS");
       cout<<"You closed the program."<<endl;
   }
}


#endif // MAIN_MENU_H_INCLUDED
