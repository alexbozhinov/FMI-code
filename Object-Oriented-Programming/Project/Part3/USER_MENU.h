#ifndef USER_MENU_H_INCLUDED
#define USER_MENU_H_INCLUDED

#ifndef OTHERFUNCTIONS_H_INCLUDED
#define OTHERFUNCTIONS_H_INCLUDED

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
#include "ADMIN_MENU.h"
#include "CLIENT_MENU.h"
#include "Cart.h"

using namespace std;

///*******************************************SIGN IN************************************************************/
   void signIn(Restaurant restaurant, int reg){
       int fakeData = 0;
       system("CLS");
       restaurant.printRestaurantData();
       MyString password;
       if(reg!=1)
       cin>>password;
       cout<<endl;
       MyString u;
       MyString p;
       cout<<"SIGN IN"<<endl<<endl;
       cout<<"Username: "; cin>>u;
       cout<<"Password: "; cin>>p;

       for(int i=0;i<restaurant.getUsers().getSize();i++){
           if(restaurant.getUsers()[i].checkUser(u, p) == false){

              fakeData++;
           }
       }
       while(fakeData == restaurant.getUsers().getSize()){
           fakeData = 0;
       cout<<"Incorrect username or password! Please, try again!"<<endl;
       MyString u;
       MyString p;
       cout<<"Username: "; cin>>u;
       cout<<"Password: "; cin>>p;

       for(int i=0;i<restaurant.getUsers().getSize();i++){
           if(restaurant.getUsers()[i].checkUser(u, p) == false){
              fakeData++;
           }
         }

        if(u=="admin"){
          AdminMainScreen(restaurant);
        }
        else {
            Cart cart;
            ClientMainScreen(restaurant,cart);
        }
        ///////////////////////////////////////////////////////////////
       }


       if(u=="admin"){
          AdminMainScreen(restaurant);
       }
       else {
            Cart cart;
           ClientMainScreen(restaurant,cart);
       }

       ////////////////////////////////////////////////////////////////
   }

 ///*****************************************************REGISTER ME*********************************************///
   void registerMe(Restaurant restaurant){
      system("CLS");
       restaurant.printRestaurantData();
       MyString password;
       cin>>password;
       cout<<"Input username and password: "<<endl;
       cout<<endl;
       MyString u;
       MyString p;
       cout<<"Username: "; cin>>u;
       cout<<"Password: "; cin>>p;
       User newUser(u,p);
       restaurant.getUsers().addBack(newUser);
              //int fakeData = 0;
       system("CLS");
       restaurant.printRestaurantData();
       cout<<endl;
       u = "";
       p = "";
       cout<<"Your registration was successful. Please Sign in: "<<endl<<endl;
     /*  cout<<"Username: "; cin>>u;
       cout<<"Password: "; cin>>p;

       for(int i=0;i<restaurant.getUsers().getSize();i++){
           if(restaurant.getUsers()[i].checkUser(u, p) == false){

              fakeData++;
           }
       }
       while(fakeData == restaurant.getUsers().getSize()){
           fakeData = 0;
       cout<<"Incorrect username or password! Please, try again!"<<endl;
       MyString u;
       MyString p;
       cout<<"Username: "; cin>>u;
       cout<<"Password: "; cin>>p;

       for(int i=0;i<restaurant.getUsers().getSize();i++){
           if(restaurant.getUsers()[i].checkUser(u, p) == false){
              fakeData++;
           }
         }

   }*/
      signIn(restaurant,1);

}

   ///********************VALIDATE USERS ********************************///
   void usersInput(Restaurant restaurant){
   int regSign;
   cout<<endl<<endl;
   cout<<"Sign in/Register"<<endl;
   cout<<"1. Sign in"<<endl;
   cout<<"2. Register"<<endl;
   cout<<"3. Exit"<<endl;
   cout<<"Input your choice: ";  cin>>regSign;
   while(true)
	{
       if(regSign!=1&&regSign!=2&&regSign!=3){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>regSign; continue;}
		else
		{
			break;
		}
	}
   if(regSign == 1){
       signIn(restaurant,0);
   }
   else if(regSign == 2){
        registerMe(restaurant);
    }
   else if(regSign == 3){
       system("CLS");
       cout<<"You closed the program."<<endl;
   }
}




#endif // OTHERFUNCTIONS_H_INCLUDED


#endif // USER_MENU_H_INCLUDED
