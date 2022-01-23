#include<iostream>
#include "MyString.h"
#include "MyArray.h"
//#include "MyArray.cpp"
#include "Ingredient.h"
#include "FoodItem.h"
#include "Salad.h"
#include "Soup.h"
#include "ChickenDish.h"
#include "Dessert.h"
#include "Menu.h"
#include "Restaurant.h"

using namespace std;

Restaurant::Restaurant(){}
Restaurant::Restaurant(MyString _name, MyString _address, MyString _e_mail, MyString _webpage, Menu _menu, MyArray<User> _users){
   this->setName(_name);
   this->setAddress(_address);
   this->setE_Mail(_e_mail);
   this->setWebpage(_webpage);
   this->setMenu(_menu);
   this->setUser(_users);
}

void Restaurant::setName(MyString _name){
   this->name = _name;
}

void Restaurant::setAddress(MyString _address){
   this->address = _address;
}

void Restaurant::setE_Mail(MyString _e_mail){
   this->e_mail = _e_mail;
}

void Restaurant::setWebpage(MyString _webpage){
   this->webpage = _webpage;
}

void Restaurant::setMenu(Menu _menu){
   this->menu = _menu;
}

void Restaurant::setUser(MyArray<User> _users){
   this->users = _users;
}

void Restaurant::printRestaurantData()const{
   cout<<"Name: "<<name<<endl;
   cout<<"Address: "<<address<<endl;
   cout<<"E_Mail: "<<e_mail<<endl;
   cout<<"WebPage: "<<webpage<<endl;
}

Menu& Restaurant::getMenu(){
   return menu;
}

MyArray<User>& Restaurant::getUsers(){
   return users;
}

