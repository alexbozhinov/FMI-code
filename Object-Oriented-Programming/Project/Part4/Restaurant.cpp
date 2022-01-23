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

using namespace std;

Restaurant::Restaurant() = default;

Restaurant::Restaurant(string _name, string _address, string _e_mail, string _phone, string _webpage, Storage _storage, Menu _menu,
                        vector<Table> _tables, vector<User> _users, vector<Waiter> _waiters, vector<Chef> _chefs, Budget _budget){
    this->setName(_name);
    this->setAddress(_address);
    this->setEmail(_e_mail);
    this->setPhone(_phone);
    this->setWebpage(_webpage);
    this->setStorage(_storage);
    this->setMenu(_menu);
    this->setTables(_tables);
    this->setUsers(_users);
    this->setWaiters(_waiters);
    this->setChefs(_chefs);
    this->setBudget(_budget);
}

void Restaurant::setName(string _name){
   this->name = _name;
}

void Restaurant::setAddress(string _address){
   this->address = _address;
}

void Restaurant::setEmail(string _e_mail){
   this->e_mail = _e_mail;
}

void Restaurant::setPhone(string _phone){
   this->phoneNumber = _phone;
}

void Restaurant::setWebpage(string _webpage){
   this->webpage = _webpage;
}

void Restaurant::setStorage(Storage _storage){
   this->storage = _storage;
}

void Restaurant::setMenu(Menu _menu){
   this->menu = _menu;
}

void Restaurant::setTables(vector<Table> _tables){
   this->tables = _tables;
}

void Restaurant::setUsers(vector<User> _users){
   this->users = _users;
}

void Restaurant::setWaiters(vector<Waiter> _waiters){
   this->waiters = _waiters;
}

void Restaurant::setChefs(vector<Chef> _chefs){
   this->chefs = _chefs;
}

void Restaurant::setBudget(Budget _budget){
   this->budget = _budget;
}

Storage Restaurant::getStorage()const{
   return this->storage;
}

Menu& Restaurant::getMenu(){
   return this->menu;
}

vector<Table> Restaurant::getTables()const{
   return this->tables;
}

vector<User>& Restaurant::getUsers(){
   return this->users;
}

vector<Waiter>& Restaurant::getWaiters(){
   return this->waiters;
}

vector<Chef>& Restaurant::getChefs(){
   return this->chefs;
}

Budget& Restaurant::getBudget(){
   return this->budget;
}

void Restaurant::print()const{
   cout<<name<<endl;
   cout<<address<<endl;
   cout<<e_mail<<endl;
   cout<<phoneNumber<<endl;
   cout<<webpage<<endl;
}

void Restaurant::printWaiters()const{
   cout<<endl<<"____WAITERS_______________________________________"<<endl<<endl;
   for(int i=0;i<waiters.size();i++){
      cout<<i+1<<". ";
      waiters[i].printPersonalInformation();
   }
}

void Restaurant::printChefs()const{
   cout<<endl<<"____CHEFS_______________________________________"<<endl<<endl;
   for(int i=0;i<chefs.size();i++){
      cout<<i+1<<". ";
      chefs[i].printPersonalInformation();
   }
}
