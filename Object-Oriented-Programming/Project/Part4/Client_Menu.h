#ifndef CLIENT_MENU_H_INCLUDED
#define CLIENT_MENU_H_INCLUDED

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

void MainMenu(Restaurant r);
void ClientMain(Restaurant r);///first page of module Client
     void SignIn(Restaurant r);///function to check if username and password are correct and sign in to the module
          void ClientFirst(Restaurant r, string u);///Client first page
               void ClientMenu(Restaurant r, string u); ///section menu
                    void TypedMenu(Restaurant r, string u);///check on the menu
                          void ClientFood(Restaurant r, string u);///check food items
                          void ClientDrink(Restaurant r, string u);///check drink items
                    void FullMenu(Restaurant r, string u);///check the full menu
                    void AddToCart(Restaurant r, string u);///add products to user's cart
                          void AddFood(Restaurant r, string u);///add food items to the cart
                          void AddDrink(Restaurant r, string u);///add drink items to the cart
                    void FinishOrder(Restaurant r, string u);///finish order section
                         void ConfirmOrder(Restaurant r, string u);///confirm order - cart becomes empty, budget's balance changes
                         void RemoveItem(Restaurant r, string u);///remove items from cart before confirming
                              void RemoveDrink(Restaurant r, string u);///remove drink items
                              void RemoveFood(Restaurant r, string u);///remove food items
               void OrdersHistory(Restaurant r, string u);///Orders history section
                    void CheckMyOrders(Restaurant r, string u);///the user can check on each order he have successfully confirmed and completed


     void Register(Restaurant r);///input username and password, make registration and become part of restaurant's user vector if username or password are not equal to already existing users

void ClientMain(Restaurant r){
   system("CLS");
   int choice;
   r.print();
   cout<<endl<<endl;
   cout<<"1. Sign in"<<endl;
   cout<<"2. Register"<<endl;
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
       SignIn(r);
   }
   else if(choice == 2){
       Register(r);
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

void SignIn(Restaurant r){
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
            for(int i = 0;i<r.getUsers().size();i++)
             if(r.getUsers()[i].checkUser(u, p) == 0 ){
                countMistakes++;
             }

         if(countMistakes == r.getUsers().size())
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

    ClientFirst(r,u);
    }
    else if(choice == 2){
        ClientMain(r);
    }
       else if(choice == 3){
       system("CLS");
       cout<<"You closed the program."<<endl;
   }
}

void Register(Restaurant r){
    system("CLS");
    r.print();
    string  u,p; int choice;
    cout<<endl;
    cout<<"_____REGISTRATION___________________________"<<endl<<endl;
    cout<<"Input username: "; cin>>u;
    cout<<"Input password: "; cin>>p;
    int countMistakes = 0;
            for(int i = 0;i<r.getUsers().size();i++)
             if(r.getUsers()[i].checkUser(u, p) == 0 ){
                countMistakes++;
             }

         if(countMistakes == r.getUsers().size()){
            User newUser(u, p);
            r.getUsers().push_back(newUser);
            cout<<endl<<"Your registration was successful!"<<endl<<endl;
            cout<<"1. Sign In"<<endl;
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
                SignIn(r);
	        }
	        else if(choice == 2){
                ClientMain(r);
	        }
            else if(choice == 3){
            system("CLS");
            cout<<"You closed the program."<<endl;
            }
         }
         else{
               cout<<"This username or password already exists. Try again!"<<endl<<endl;
               int secondChoice;
               cout<<"1. Try again"<<endl;
               cout<<"2. Back"<<endl;
               cout<<"3. Exit"<<endl<<endl;
               cout<<"Input your choice: ";  cin>>secondChoice;
               while(true)
	           {
                 if(secondChoice != 1 && secondChoice != 2 && secondChoice != 3){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>secondChoice; continue;}
		        else
		        {
			    break;
		        }
	            }
	           if(secondChoice == 1){
                  Register(r);
	            }
	            else if(secondChoice == 2){
                ClientMain(r);
	            }
                else if(secondChoice == 3){
                system("CLS");
                cout<<"You closed the program."<<endl;
            }
	      }
}

void ClientFirst(Restaurant r, string u){
   system("CLS");
   int choice;
   r.print();
   cout<<endl<<endl;
   cout<<"1. Menu"<<endl;
   cout<<"2. Orders History"<<endl;
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
       ClientMenu(r, u);
   }
   else if(choice == 2){
       OrdersHistory(r, u);
    }
   else if(choice == 3){
       SignIn(r);
   }
   else if(choice == 4){
       system("CLS");
       cout<<"You closed the program."<<endl;
   }
}

void ClientMenu(Restaurant r, string u){
   system("CLS");
   r.print();
   cout<<endl;
   cout<<"1. Typed Menu"<<endl;
   cout<<"2. Full Menu"<<endl;
   cout<<"3. Add to Cart"<<endl;
   cout<<"4. Finish Order"<<endl;
   cout<<"5. Back"<<endl;
   cout<<"6. Exit"<<endl;
   int choice;
   cout<<endl<<"Input choice: ";
   cin>>choice;
    while(true)
	{
       if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 ){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        TypedMenu(r, u);
    }
    else if(choice == 2){
        FullMenu(r, u);
    }
    else if(choice == 3){
        AddToCart(r, u);
    }
    else if(choice == 4){
        FinishOrder(r, u);
    }
    else if(choice == 5){
        ClientFirst(r, u);
    }
    else if(choice == 7){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void FullMenu(Restaurant r, string u){
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
        ClientMenu(r, u);
	}
    else if(choice == 2){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void TypedMenu(Restaurant r, string u){
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
        ClientFood(r, u);
    }
    else if(choice == 2){
        ClientDrink(r, u);
    }
    else if(choice == 3){
        ClientMenu(r, u);
    }
    else if(choice == 4){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void ClientFood(Restaurant r, string u){
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
        TypedMenu(r, u);
	}
    else if(choice == 2){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void ClientDrink(Restaurant r, string u){
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
        TypedMenu(r, u);
	}
    else if(choice == 2){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void AddToCart(Restaurant r, string u){
   system("CLS");
   r.print();
   cout<<endl;
   cout<<"What type of products would you like to buy? "<<endl<<endl;
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
        AddFood(r, u);
    }
    else if(choice == 2){
        AddDrink(r, u);
    }
    else if(choice == 3){
        ClientMenu(r, u);
    }
    else if(choice == 4){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void AddFood(Restaurant r, string u){
   system("CLS");
   r.print();
   cout<<endl;
   r.getMenu().printFood();
   int toAdd, howMany;
   cout<<endl<<"Which food item would you like to add to the cart?"<<endl;
   cout<<"Input here: "; cin>>toAdd;
   cout<<"Input count: ";cin>>howMany;
   for(int i = 0;i< r.getUsers().size();i++){
       if(r.getUsers()[i].getUsername() == u){
           for(int j=0;j<howMany;j++){
              r.getUsers()[i].getCart().getFood().push_back(r.getMenu().getFood()[toAdd-1]);
              //   r.getBudget().getOnlineIncome() += r.getMenu().getFood()[toAdd - 1].getPrice();
              //   r.getBudget().setBalance(r.getBudget().getIngredientOutcome(), r.getBudget().getSalaryOutcome(), r.getBudget().getOnlineIncome(), r.getBudget().getPlaceIncome());
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
        AddFood(r,u);
    }
    else if(choice == 2){
        AddToCart(r, u);
    }
    else if(choice == 3){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

void AddDrink(Restaurant r, string u){
   system("CLS");
   r.print();
   cout<<endl;
   r.getMenu().printDrink();
   int toAdd, howMany;
   cout<<endl<<"Which drink item would you like to add to the cart?"<<endl;
   cout<<"Input here: "; cin>>toAdd;
   cout<<"Input count: ";cin>>howMany;
   for(int i = 0;i< r.getUsers().size();i++){
       if(r.getUsers()[i].getUsername() == u){
           for(int j=0;j<howMany;j++){
              r.getUsers()[i].getCart().getDrink().push_back(r.getMenu().getDrink()[toAdd-1]);
              //   r.getBudget().getOnlineIncome() += r.getMenu().getFood()[toAdd - 1].getPrice();
              //   r.getBudget().setBalance(r.getBudget().getIngredientOutcome(), r.getBudget().getSalaryOutcome(), r.getBudget().getOnlineIncome(), r.getBudget().getPlaceIncome());
           }
       }
   }
   cout<<endl<<"Drink item/s added!"<<endl<<endl;
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
        AddDrink(r,u);
    }
    else if(choice == 2){
        AddToCart(r, u);
    }
    else if(choice == 3){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

void FinishOrder(Restaurant r, string u){
   system("CLS");
   r.print();
   cout<<endl;
   for(int i = 0;i< r.getUsers().size();i++){
       if(r.getUsers()[i].getUsername() == u){
              cout<<endl<<"_____CART___________________________________________________________________"<<endl;
              r.getUsers()[i].getCart().print();
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
        ConfirmOrder(r, u);
    }
    else if(choice == 2){
        RemoveItem(r, u);
    }
    else if(choice == 3){
        ClientMenu(r, u);
    }
    else if(choice == 4){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void ConfirmOrder(Restaurant r, string u){
   system("CLS");
   r.print();
   cout<<endl;
   for(int i = 0;i< r.getUsers().size();i++){
       if(r.getUsers()[i].getUsername() == u){
            OnlineOrder newOrder(r.getUsers()[i].getCart(), lev);
              r.getUsers()[i].getOrders().push_back(newOrder);


                 cout<<endl<<"Your order confirmed!"<<endl<<endl;
                for(int k=0;k<r.getUsers().size();k++){
                     if(r.getUsers()[k].getUsername() == u){
                     r.getUsers()[k].getOrders().back().print();
                   }
                }



            for(int j = 0; j < r.getUsers()[i].getCart().getFood().size();j++){
                r.getBudget().getOnlineIncome() += r.getUsers()[i].getCart().getFood()[j].getPrice();
                r.getBudget().setBalance(r.getBudget().getIngredientOutcome(), r.getBudget().getSalaryOutcome(), r.getBudget().getOnlineIncome(), r.getBudget().getPlaceIncome());
            }
            for(int j = 0; j < r.getUsers()[i].getCart().getDrink().size();j++){
                r.getBudget().getOnlineIncome() += r.getUsers()[i].getCart().getDrink()[j].getPrice();
                r.getBudget().setBalance(r.getBudget().getIngredientOutcome(), r.getBudget().getSalaryOutcome(), r.getBudget().getOnlineIncome(), r.getBudget().getPlaceIncome());
            }
              vector<FoodItem> newFood;
              vector<DrinkItem> newDrink;
              r.getUsers()[i].getCart() = Cart(newFood, newDrink);
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
        ClientMenu(r,u);
    }

    else if(choice == 3){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

void RemoveItem(Restaurant r, string u){
   system("CLS");
   r.print();
   cout<<endl;
   for(int i = 0;i< r.getUsers().size();i++){
       if(r.getUsers()[i].getUsername() == u){
              cout<<endl<<"_____CART___________________________________________________________________"<<endl;
              r.getUsers()[i].getCart().print();
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
        RemoveFood(r, u);
    }
    else if(choice == 2){
        RemoveDrink(r, u);
    }
    else if(choice == 3){
        FinishOrder(r, u);
    }
    else if(choice == 4){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void RemoveFood(Restaurant r, string u){
   system("CLS");
   r.print();
   for(int i = 0;i< r.getUsers().size();i++){
       if(r.getUsers()[i].getUsername() == u){
              cout<<endl<<"_____CART___________________________________________________________________"<<endl;
              r.getUsers()[i].getCart().print();
       }
   }
   int toRemove;
   cout<<endl<<"Which food item would you like to remove?"<<endl;
   cout<<"Input here: "; cin>>toRemove;
   for(int i = 0;i< r.getUsers().size();i++){
       if(r.getUsers()[i].getUsername() == u){
              r.getUsers()[i].getCart().getFood().erase(r.getUsers()[i].getCart().getFood().begin() + toRemove - 1);
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
       RemoveItem(r, u);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

void RemoveDrink(Restaurant r, string u){
   system("CLS");
   r.print();
   for(int i = 0;i< r.getUsers().size();i++){
       if(r.getUsers()[i].getUsername() == u){
              cout<<endl<<"_____CART___________________________________________________________________"<<endl;
              r.getUsers()[i].getCart().print();
       }
   }
   int toRemove;
   cout<<endl<<"Which drink item would you like to remove?"<<endl;
   cout<<"Input here: "; cin>>toRemove;
   for(int i = 0;i< r.getUsers().size();i++){
       if(r.getUsers()[i].getUsername() == u){
              r.getUsers()[i].getCart().getDrink().erase(r.getUsers()[i].getCart().getDrink().begin() + toRemove - 1);
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
       RemoveItem(r, u);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

void OrdersHistory(Restaurant r, string u){
   system("CLS");
   r.print();
   cout<<endl;
   cout<<"1. Check my orders"<<endl;
   cout<<"2. Back"<<endl;
   cout<<"3. Exit"<<endl;
   int choice;
   cout<<endl<<"Input choice: ";
   cin>>choice;
    while(true)
	{
       if(choice != 1 && choice != 2 && choice != 3 ){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        CheckMyOrders(r, u);
    }
    else if(choice == 2){
        ClientFirst(r, u);
    }
    else if(choice == 3){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

void CheckMyOrders(Restaurant r, string u){
   system("CLS");
   r.print();
   cout<<endl;
   cout<<"_____MY_ORDERS______________________________________________________________"<<endl<<endl;
   for(int i = 0;i< r.getUsers().size();i++){
       if(r.getUsers()[i].getUsername() == u){
              for(int j=0; j < r.getUsers()[i].getOrders().size();j++){
                  r.getUsers()[i].getOrders()[j].print();
                  cout<<endl<<endl;
              }
       }
   }
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
       OrdersHistory(r, u);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}



#endif // CLIENT_MENU_H_INCLUDED
