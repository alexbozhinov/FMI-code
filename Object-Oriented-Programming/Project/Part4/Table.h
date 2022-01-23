#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED

#include<iostream>
#include<string>
#include<vector>
#include "Ingredient.h"
#include "Item.h"
#include "Order.h"

using namespace std;

enum Form{
   Circle,
   Square,
   Rectangle
};

class Table{

public:
   Table();
   Table(int, int, Form);
   void addOrder(Order );
   int getNumber()const;
   int getCapacity()const;
   Form getForm()const;
   Order& getOrder();
   void printForm(Form )const;

private:
    void setNumber(int );
    void setCapacity(int );
    void setForm(Form );

    int number;
    int capacity;
    Form form;
    Order order;
};

#endif // TABLE_H_INCLUDED
