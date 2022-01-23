#ifndef RESTAURANT_H_INCLUDED
#define RESTAURANT_H_INCLUDED

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

using namespace std;

class Restaurant{

public:
    Restaurant();
    Restaurant(string, string, string, string, string, Storage, Menu, vector<Table>, vector<User>, vector<Waiter>, vector<Chef>, Budget );
    Storage getStorage()const;
    Menu& getMenu();
    vector<Table> getTables()const;
    vector<User>& getUsers();
    vector<Waiter>& getWaiters();
    vector<Chef>& getChefs();
    Budget& getBudget();
    void print()const;
    void printWaiters()const;
    void printChefs()const;

private:
    void setName(string );
    void setAddress(string );
    void setEmail(string );
    void setPhone(string );
    void setWebpage(string );
    void setStorage(Storage );
    void setMenu(Menu );
    void setTables(vector<Table> );
    void setUsers(vector<User> );
    void setWaiters(vector<Waiter> );
    void setChefs(vector<Chef> );
    void setBudget(Budget );

    string name;
    string address;
    string e_mail;
    string phoneNumber;
    string webpage;
    Storage storage;
    Menu menu;
    vector<Table> tables;
    vector<User> users;
    vector<Waiter> waiters;
    vector<Chef> chefs;
    Budget budget;
};

#endif // RESTAURANT_H_INCLUDED
