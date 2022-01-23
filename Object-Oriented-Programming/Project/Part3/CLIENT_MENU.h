#ifndef CLIENT_MENU_H_INCLUDED
#define CLIENT_MENU_H_INCLUDED

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
//#include "ADMIN_MENU.h"
#include "Cart.h"
#include "OnlineOrder.h"

using namespace std;

///**********************LIST OF PROTOTYPES*****************************///
void ClientMainScreen(Restaurant,Cart );//
       void clientMenu(Restaurant,Cart );//
                void clientTypedMenuPrinting(Restaurant,Cart );//
                         void saladsPrinting1(Restaurant,Cart );//
                               void sortSalads1(Restaurant,Cart );///ok
                               void sortSalads2(Restaurant,Cart );///ok
                               void addToCartSalads(Restaurant,Cart );
                         void soupsPrinting1(Restaurant,Cart );//
                               void sortSoups1(Restaurant,Cart );///ok
                               void sortSoups2(Restaurant,Cart);///ok
                               void addToCartSoups(Restaurant,Cart );
                         void chickenDishesPrinting1(Restaurant,Cart );//
                               void sortChickenDishes1(Restaurant,Cart );///ok
                               void sortChickenDishes2(Restaurant,Cart );///ok
                               void addToCartChickenDishes(Restaurant,Cart );
                         void dessertsPrinting1(Restaurant,Cart );//
                               void sortDesserts1(Restaurant,Cart );///ok
                               void sortDesserts2(Restaurant,Cart );///ok
                               void addToCartDesserts(Restaurant,Cart);
                void clientFullMenuPrinting(Restaurant,Cart );//
                               //void sortMenu(Restaurant,Cart );
                               //void addToCart(Restaurant,Cart );
                                 void addInFull(Restaurant, Cart);
                void finishOrder(Restaurant,Cart );
                        void checkCart(Restaurant, Cart);
                             void removeFromCart(Restaurant, Cart);
                        void confirmOrder(Restaurant, Cart);
                         ///check order
                         ///remove element from order;
                         ///accept order
      void clientOrder(Restaurant );

void signIn(Restaurant );
void registerMe(Restaurant );
void usersInput(Restaurant );

///*******************************************************CLIENT MAIN SCREEN****************************************/
void ClientMainScreen(Restaurant restaurant,Cart cart){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   cout<<"1. View Menu"<<endl;
   cout<<"2. View orders //still not working"<<endl;
   cout<<"3. Back"<<endl;
   cout<<"4. Exit"<<endl;
   int clientChoice;
   cout<<endl<<"Input choice: ";
   cin>>clientChoice;
    while(true)
	{
       if(clientChoice!=1&&clientChoice!=2&&clientChoice!=3&&clientChoice!=4){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>clientChoice; continue;}
		else
		{
			break;
		}
	}
	if(clientChoice == 1){
        clientMenu(restaurant,cart);
	}
	else if(clientChoice == 2){
        //clientOrder(restaurant,cart);///future plans
	}
	else if(clientChoice == 3){
        system("CLS");
        restaurant.printRestaurantData();
        usersInput(restaurant);
	}
	else if(clientChoice == 4){
        system("CLS");
        cout<<"You closed the program."<<endl;
	}
}

/*******************************************************CLIENT MENU***************************************************/
void clientMenu(Restaurant restaurant,Cart cart ){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   cout<<"1. Typed Menu"<<endl;
   cout<<"2. Full Menu"<<endl;
   cout<<"3. Finish order"<<endl;
   cout<<"4. Back"<<endl;
   cout<<"5. Exit"<<endl;
   int clientMenuChoice;
   cout<<endl<<"Input choice: ";
   cin>>clientMenuChoice;
    while(true)
	{
       if(clientMenuChoice!=1&&clientMenuChoice!=2&&clientMenuChoice!=3&&clientMenuChoice!=4&&clientMenuChoice!=5){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>clientMenuChoice; continue;}
		else
		{
			break;
		}
    }
    if(clientMenuChoice == 1){
        clientTypedMenuPrinting(restaurant,cart);
    }
    else if(clientMenuChoice == 2){
        clientFullMenuPrinting(restaurant,cart);
    }
    else if(clientMenuChoice == 3){
         finishOrder(restaurant,cart);
    }
    else if(clientMenuChoice == 4){
        ClientMainScreen(restaurant,cart);
    }
    else if(clientMenuChoice == 5){
        system("CLS");
        cout<<"You closed the program."<<endl;
    }
}

///***************************************************************CLIENT TYPED MENU PRINTING********************************************************/
void clientTypedMenuPrinting(Restaurant restaurant,Cart cart){
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
         saladsPrinting1(restaurant, cart);
   }
   else if(typedChoice == 2){
       soupsPrinting1(restaurant,cart);
   }
      else if(typedChoice == 3){
        chickenDishesPrinting1(restaurant, cart);
   }
      else if(typedChoice == 4){
        dessertsPrinting1(restaurant, cart);
   }
   else if(typedChoice == 5){
      clientMenu(restaurant, cart);
   }
   else if(typedChoice == 6){
      system("CLS");
      cout<<"You closed the program."<<endl;
   }
}

///***************************************************************SALADS PRINTING*********************************/
void saladsPrinting1(Restaurant restaurant,Cart cart){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   restaurant.getMenu().printTypedMenu(1);
   cout<<endl;
   cout<<"1. Sort by price from highest to lowest"<<endl;
   cout<<"2. Sort by price from lowest to highest"<<endl;
   cout<<"3. Add to cart"<<endl;
   cout<<"4. Back"<<endl;
   cout<<"5. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        sortSalads1(restaurant, cart);
    }
    else if(choice == 2){
        sortSalads2(restaurant, cart);
    }
    else if(choice == 3){
        addToCartSalads(restaurant, cart);
    }
    else if(choice == 4){
        clientTypedMenuPrinting(restaurant, cart);
    }
    else if(choice == 5){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}
///***************************************************************************************ADD TO CART SALADS************************************/
void addToCartSalads(Restaurant restaurant,Cart cart){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   restaurant.getMenu().printTypedMenu(1);
   cout<<endl;
   cout<<"Order: ";
   int saladChoice;
   cin>>saladChoice;
   cout<<"How many salads?: ";
   int howMany;
   cin>>howMany;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl;
   int choice;
//   Cart cart;
   for(int i=0;i<howMany;i++){
       cart.getCart().addBack(restaurant.getMenu().getAllSalads().getSalads()[saladChoice-1]);
   }
   cart.printCart();
   cout<<"Input here: ";
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
        saladsPrinting1(restaurant, cart);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}




///******************************************************************************************SORT SALADS 1***********************************************///
void sortSalads1(Restaurant restaurant,Cart cart){
          system("CLS");
          restaurant.printRestaurantData();
          cout<<endl;
    for (int i = 0; i < restaurant.getMenu().getAllSalads().getSalads().getSize()-1; i++){
       for (int j = 0; j < restaurant.getMenu().getAllSalads().getSalads().getSize()-i-1; j++){
           if (restaurant.getMenu().getAllSalads().getSalads()[j].getPrice() < restaurant.getMenu().getAllSalads().getSalads()[j+1].getPrice())
               swap(restaurant.getMenu().getAllSalads().getSalads()[j], restaurant.getMenu().getAllSalads().getSalads()[j+1]);
       }
    }
          cout<<endl;
          restaurant.getMenu().printTypedMenu(1);

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
        saladsPrinting1(restaurant, cart);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

///***********************************************************************************SORT SALADS 2**********************************************/
void sortSalads2(Restaurant restaurant,Cart cart){
          system("CLS");
          restaurant.printRestaurantData();
          cout<<endl;
    for (int i = 0; i < restaurant.getMenu().getAllSalads().getSalads().getSize()-1; i++){
       for (int j = 0; j < restaurant.getMenu().getAllSalads().getSalads().getSize()-i-1; j++){
           if (restaurant.getMenu().getAllSalads().getSalads()[j].getPrice() > restaurant.getMenu().getAllSalads().getSalads()[j+1].getPrice())
               swap(restaurant.getMenu().getAllSalads().getSalads()[j], restaurant.getMenu().getAllSalads().getSalads()[j+1]);
       }
    }
          cout<<endl;
          restaurant.getMenu().printTypedMenu(1);

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
        saladsPrinting1(restaurant, cart);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

///**********************************************************SOUPS PRINTING****************************/
void soupsPrinting1(Restaurant restaurant,Cart cart){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   restaurant.getMenu().printTypedMenu(2);
   cout<<endl;
   cout<<"1. Sort by price from highest to lowest"<<endl;
   cout<<"2. Sort by price from lowest to highest"<<endl;
   cout<<"3. Add to cart"<<endl;
   cout<<"4. Back"<<endl;
   cout<<"5. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        sortSoups1(restaurant, cart);
    }
    else if(choice == 2){
        sortSoups2(restaurant, cart);
    }
    else if(choice == 3){
        addToCartSoups(restaurant, cart);
    }
    else if(choice == 4){
        clientTypedMenuPrinting(restaurant, cart);
    }
    else if(choice == 5){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

///***************************************************************************************ADD TO CART SOUPS************************************/
void addToCartSoups(Restaurant restaurant,Cart cart){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   restaurant.getMenu().printTypedMenu(2);
   cout<<endl;
   cout<<"Order: ";
   int soupChoice;
   cin>>soupChoice;
   cout<<"How many salads?: ";
   int howMany;
   cin>>howMany;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl;
   int choice;
//   Cart cart;
   for(int i=0;i<howMany;i++){
       cart.getCart().addBack(restaurant.getMenu().getAllSoups().getSoups()[soupChoice-1]);
   }
   cart.printCart();
   cout<<"Input here: ";
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
        soupsPrinting1(restaurant, cart);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}





///******************************************************************************************SORT SOUPS 1***********************************************///
void sortSoups1(Restaurant restaurant,Cart cart){
          system("CLS");
          restaurant.printRestaurantData();
          cout<<endl;
    for (int i = 0; i < restaurant.getMenu().getAllSoups().getSoups().getSize()-1; i++){
       for (int j = 0; j < restaurant.getMenu().getAllSoups().getSoups().getSize()-i-1; j++){
           if (restaurant.getMenu().getAllSoups().getSoups()[j].getPrice() < restaurant.getMenu().getAllSoups().getSoups()[j+1].getPrice())
               swap(restaurant.getMenu().getAllSoups().getSoups()[j], restaurant.getMenu().getAllSoups().getSoups()[j+1]);
       }
    }
          cout<<endl;
          restaurant.getMenu().printTypedMenu(2);

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
        soupsPrinting1(restaurant, cart);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

///******************************************************************************************SORT SOUPS 2***********************************************///
void sortSoups2(Restaurant restaurant,Cart cart){
          system("CLS");
          restaurant.printRestaurantData();
          cout<<endl;
    for (int i = 0; i < restaurant.getMenu().getAllSoups().getSoups().getSize()-1; i++){
       for (int j = 0; j < restaurant.getMenu().getAllSoups().getSoups().getSize()-i-1; j++){
           if (restaurant.getMenu().getAllSoups().getSoups()[j].getPrice() > restaurant.getMenu().getAllSoups().getSoups()[j+1].getPrice())
               swap(restaurant.getMenu().getAllSoups().getSoups()[j], restaurant.getMenu().getAllSoups().getSoups()[j+1]);
       }
    }
          cout<<endl;
          restaurant.getMenu().printTypedMenu(2);

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
        soupsPrinting1(restaurant, cart);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

///***************************************************************CHICKEN DISHES PRINTING******************************///
void chickenDishesPrinting1(Restaurant restaurant,Cart cart){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   restaurant.getMenu().printTypedMenu(3);
   cout<<endl;
   cout<<"1. Sort by price from highest to lowest"<<endl;
   cout<<"2. Sort by price from lowest to highest"<<endl;
   cout<<"3. Add to cart"<<endl;
   cout<<"4. Back"<<endl;
   cout<<"5. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        sortChickenDishes1(restaurant, cart);
    }
    else if(choice == 2){
        sortChickenDishes2(restaurant, cart);
    }
    else if(choice == 3){
        addToCartChickenDishes(restaurant, cart);
    }
    else if(choice == 4){
        clientTypedMenuPrinting(restaurant, cart);
    }
    else if(choice == 5){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

///***************************************************************************************ADD TO CART CHICKEN DISHES************************************/
void addToCartChickenDishes(Restaurant restaurant,Cart cart){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   restaurant.getMenu().printTypedMenu(3);
   cout<<endl;
   cout<<"Order: ";
   int chickenDishChoice;
   cin>>chickenDishChoice;
   cout<<"How many chicken dishes?: ";
   int howMany;
   cin>>howMany;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl;
   int choice;
//   Cart cart;
   for(int i=0;i<howMany;i++){
       cart.getCart().addBack(restaurant.getMenu().getAllChickenDishes().getChickenDishes()[chickenDishChoice-1]);
   }
   cart.printCart();
   cout<<"Input here: ";
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
        chickenDishesPrinting1(restaurant, cart);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

///******************************************************************************************SORT CHICKEN DISHES 1***********************************************///
void sortChickenDishes1(Restaurant restaurant,Cart cart){
          system("CLS");
          restaurant.printRestaurantData();
          cout<<endl;
    for (int i = 0; i < restaurant.getMenu().getAllChickenDishes().getChickenDishes().getSize()-1; i++){
       for (int j = 0; j < restaurant.getMenu().getAllChickenDishes().getChickenDishes().getSize()-i-1; j++){
           if (restaurant.getMenu().getAllChickenDishes().getChickenDishes()[j].getPrice() < restaurant.getMenu().getAllChickenDishes().getChickenDishes()[j+1].getPrice())
               swap(restaurant.getMenu().getAllChickenDishes().getChickenDishes()[j], restaurant.getMenu().getAllChickenDishes().getChickenDishes()[j+1]);
       }
    }
          cout<<endl;
          restaurant.getMenu().printTypedMenu(3);

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
        chickenDishesPrinting1(restaurant, cart);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

///******************************************************************************************SORT CHICKEN DISHES 2***********************************************///
void sortChickenDishes2(Restaurant restaurant,Cart cart){
          system("CLS");
          restaurant.printRestaurantData();
          cout<<endl;
    for (int i = 0; i < restaurant.getMenu().getAllChickenDishes().getChickenDishes().getSize()-1; i++){
       for (int j = 0; j < restaurant.getMenu().getAllChickenDishes().getChickenDishes().getSize()-i-1; j++){
           if (restaurant.getMenu().getAllChickenDishes().getChickenDishes()[j].getPrice() > restaurant.getMenu().getAllChickenDishes().getChickenDishes()[j+1].getPrice())
               swap(restaurant.getMenu().getAllChickenDishes().getChickenDishes()[j], restaurant.getMenu().getAllChickenDishes().getChickenDishes()[j+1]);
       }
    }
          cout<<endl;
          restaurant.getMenu().printTypedMenu(3);

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
        chickenDishesPrinting1(restaurant, cart);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

///********************************************************************DESSERT PRINTING*************************/
void dessertsPrinting1(Restaurant restaurant,Cart cart){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   restaurant.getMenu().printTypedMenu(4);
   cout<<endl;
   cout<<"1. Sort by price from highest to lowest"<<endl;
   cout<<"2. Sort by price from lowest to highest"<<endl;
   cout<<"3. Add to cart"<<endl;
   cout<<"4. Back"<<endl;
   cout<<"5. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        sortDesserts1(restaurant, cart);
    }
    else if(choice == 2){
        sortDesserts2(restaurant,cart);
    }
    else if(choice == 3){
        addToCartDesserts(restaurant, cart);
    }
    else if(choice == 4){
        clientTypedMenuPrinting(restaurant, cart);
    }
    else if(choice == 5){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

///***************************************************************************************ADD TO CART DESSERTS************************************/
void addToCartDesserts(Restaurant restaurant,Cart cart){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   restaurant.getMenu().printTypedMenu(4);
   cout<<endl;
   cout<<"Order: ";
   int dessertChoice;
   cin>>dessertChoice;
   cout<<"How many salads?: ";
   int howMany;
   cin>>howMany;
   cout<<"1. Back"<<endl;
   cout<<"2. Exit"<<endl;
   int choice;
//   Cart cart;
   for(int i=0;i<howMany;i++){
       cart.getCart().addBack(restaurant.getMenu().getAllDesserts().getDesserts()[dessertChoice-1]);
   }
   cart.printCart();
   cout<<"Input here: ";
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
        saladsPrinting1(restaurant, cart);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

///******************************************************************************************SORT DESSERTS 1***********************************************///
void sortDesserts1(Restaurant restaurant,Cart cart){
          system("CLS");
          restaurant.printRestaurantData();
          cout<<endl;
    for (int i = 0; i < restaurant.getMenu().getAllDesserts().getDesserts().getSize()-1; i++){
       for (int j = 0; j < restaurant.getMenu().getAllDesserts().getDesserts().getSize()-i-1; j++){
           if (restaurant.getMenu().getAllDesserts().getDesserts()[j].getPrice() < restaurant.getMenu().getAllDesserts().getDesserts()[j+1].getPrice())
               swap(restaurant.getMenu().getAllDesserts().getDesserts()[j], restaurant.getMenu().getAllDesserts().getDesserts()[j+1]);
       }
    }
          cout<<endl;
          restaurant.getMenu().printTypedMenu(4);

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
        dessertsPrinting1(restaurant, cart);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

///******************************************************************************************SORT DESSERTS 2***********************************************///
void sortDesserts2(Restaurant restaurant,Cart cart){
          system("CLS");
          restaurant.printRestaurantData();
          cout<<endl;
    for (int i = 0; i < restaurant.getMenu().getAllDesserts().getDesserts().getSize()-1; i++){
       for (int j = 0; j < restaurant.getMenu().getAllDesserts().getDesserts().getSize()-i-1; j++){
           if (restaurant.getMenu().getAllDesserts().getDesserts()[j].getPrice() > restaurant.getMenu().getAllDesserts().getDesserts()[j+1].getPrice())
               swap(restaurant.getMenu().getAllDesserts().getDesserts()[j], restaurant.getMenu().getAllDesserts().getDesserts()[j+1]);
       }
    }
          cout<<endl;
          restaurant.getMenu().printTypedMenu(4);

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
        dessertsPrinting1(restaurant, cart);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

///******************************************************************************************CLIENT FULL MENU PRINTING*************************************/
void clientFullMenuPrinting(Restaurant restaurant,Cart cart){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   cout<<endl;
   cout<<"---------------------------=MENU=------------------------------------------"<<endl<<endl;
   restaurant.getMenu().printFullMenu();
   cout<<"1. Add to cart"<<endl;
   cout<<"2. Back"<<endl;
   cout<<"3. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice!=1&&choice!=2&&choice!=3){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
    addInFull(restaurant, cart );
    }
    else if(choice == 2){
        clientMenu(restaurant,cart);//need change + function that makes order from cart and then order -> finished;
    }
    else if(choice == 3){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

///*************************************************************************************ADD TO CART FULL************************************************/

void addInFull(Restaurant restaurant, Cart cart){
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
   cout<<endl<<"What type of food would you like to add to your cart? "<<endl;
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
         addToCartSalads(restaurant, cart);
   }
   else if(typedChoice == 2){
         addToCartSoups(restaurant,cart);
   }
      else if(typedChoice == 3){
        addToCartChickenDishes(restaurant, cart);
   }
      else if(typedChoice == 4){
        addToCartDesserts(restaurant, cart);
   }
   else if(typedChoice == 5){
        clientFullMenuPrinting(restaurant, cart);
   }
   else if(typedChoice == 6){
      system("CLS");
      cout<<"You closed the program."<<endl;
   }
}

///***************************************************************FINISH ORDER*******************************************///
void finishOrder(Restaurant restaurant, Cart cart){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   cout<<"1. Check cart"<<endl;
   cout<<"2. Confirm order"<<endl;
   cout<<"3. Back"<<endl;
   cout<<"4. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice!=1&&choice!=2&&choice!=3&&choice!=4){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
         checkCart(restaurant, cart);
    }
    else if(choice == 2){
         confirmOrder(restaurant, cart);
    }
    else if(choice == 3){
        clientMenu(restaurant, cart);
    }
    else if(choice == 4){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}

///**********************************************************************CHECK CART*********************************************************/
void checkCart(Restaurant restaurant, Cart cart){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   cart.printCart();
   cout<<endl;
   cout<<endl;
   cout<<"1. Confirm order"<<endl;
   cout<<"2. Remove from cart"<<endl;
   cout<<"3. Back"<<endl;
   cout<<"4. Exit"<<endl;
   cout<<endl<<"Input choice: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice!=1&&choice!=2&&choice!=3&&choice!=4){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
         confirmOrder(restaurant, cart);  //second tyme ^
    }
    else if(choice == 2){
         removeFromCart(restaurant, cart);
    }
    else if(choice == 3){
        finishOrder(restaurant, cart);
    }
    else if(choice == 4){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}
///******************************************************************************remove from cart********************************************///
void removeFromCart(Restaurant restaurant, Cart cart){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   cart.printCart();
   cout<<endl;
   cout<<"1. Remove"<<endl;
   cout<<"2. Back"<<endl;
   cout<<"3. Exit"<<endl;
   cout<<endl<<"Input here: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice!=1&&choice!=2&&choice!=3){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
   if(choice == 1){
     cout<<endl<<endl;
     cout<<"Which product would you like to remove?"<<endl;
     int removeThis;
     cout<<"Input here: ";
     cin>>removeThis;
     cart.getCart().removeElementAt(removeThis);
     cart.printCart();
     cout<<"1. Back"<<endl;
     cout<<"2. Exit"<<endl;
     cout<<endl<<"Input here: ";
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
        checkCart(restaurant, cart);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
   }
   else if(choice == 2){
      checkCart(restaurant, cart);
   }
   else if(choice == 3){
       system("CLS");
       cout<<"You closed the program."<<endl;
   }
}

///*****************************************************************CONFIRM ORDER*******************************************///
void confirmOrder(Restaurant restaurant, Cart cart){
   system("CLS");
   restaurant.printRestaurantData();
   cout<<endl;
   cart.printCart();
   cout<<endl;
   cout<<"1. Confirm"<<endl;
   cout<<"2. Back"<<endl;
   cout<<"3. Exit"<<endl;
   cout<<endl<<"Input here: ";
   int choice;
   cin>>choice;
   while(true)
	{
       if(choice!=1&&choice!=2&&choice!=3){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice; continue;}
		else
		{
			break;
		}
    }
    if(choice == 1){
        OnlineOrder order(cart);
        system("CLS");
        cout<<"Your order was accepted!"<<endl<<endl;
        order.printOnlineOrder();
        cout<<endl<<endl;
     cout<<"1. Back"<<endl;
     cout<<"2. Exit"<<endl;
     cout<<endl<<"Input here: ";
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
        finishOrder(restaurant, cart);
    }
    else if(choice == 2){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
    }
    else if(choice == 2){
        finishOrder(restaurant, cart);
    }
    else if(choice == 3){
       system("CLS");
       cout<<"You closed the program."<<endl;
    }
}
#endif // CLIENT_MENU_H_INCLUDED
