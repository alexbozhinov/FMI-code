#include<iostream>
#include<string>
#include<vector>
#include "Ingredient.h"
#include "Item.h"
#include "Order.h"
#include "Table.h"

using namespace std;

Table::Table() = default;

Table::Table(int _number, int _capacity, Form _form){
   this->setNumber(_number);
   this->setCapacity(_capacity);
   this->setForm(_form);
}

void Table::setNumber(int _number){
   this->number = _number;
}

void Table::setCapacity(int _capacity){
   this->capacity = _capacity;
}

void Table::setForm(Form _form){
   this->form = _form;
}

int Table::getNumber()const{
   return this->number;
}

int Table::getCapacity()const{
   return this->capacity;
}

Form Table::getForm()const{
   return this->form;
}

Order& Table::getOrder(){
   return this->order;
}
/*
void Table::addOrder(Order _order){
   this->orders.push_back(_order);
}
*/
void Table::printForm(Form form)const{
   if(form == 0) cout<<"Circle";
   else if(form == 1) cout<<"Square";
   else if(form == 2) cout<<"Rectangle";
}







