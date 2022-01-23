#include "Ingredient.h"
#include "Table.h"
#include "Person.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

///***PERSON***///

Person::Person(){
   name = "";
   egn = "";
   username = "";
   password = "";
}

Person::Person(string _name, string _egn, string _username, string _password){
   this->setName(_name);
   this->setEgn(_egn);
   this->setUsername(_username);
   this->setPassword(_password);
}

void Person::setName(string _name){
   this->name = _name;
}

void Person::setEgn(string _egn){
   this->egn = _egn;
}

void Person::setUsername(string _username){
   this->username = _username;
}

void Person::setPassword(string _password){
   this->password = _password;
}

string Person::getName()const{
   return this->name;
}

string Person::getEgn()const{
   return this->egn;
}

string Person::getUsername()const{
   return this->username;
}

string Person::getPassword()const{
   return this->password;
}

///***EMPLOYEE***///

Employee::Employee(){
   salary = 0.0;
   currency = lev;
   workHours = 0.0;
}

Employee::Employee(string _name, string _egn, string _username, string _password, double _salary, Currency _currency, double _workHours)
   : Person(_name, _egn, _username, _password)
   {
       this->setSalary(_salary);
       this->setCurrency(_currency);
       this->setHours(_workHours);
   }

void Employee::setSalary(double _salary){
   this->salary = _salary;
}

void Employee::setCurrency(Currency _currency){
   this->currency = _currency;
}

void Employee::setHours(double _workHours){
   this->workHours = _workHours;
}

double Employee::getSalary()const{
   return this->salary;
}

double Employee::getHours()const{
   return this->workHours;
}

Currency Employee::getCurrency()const{
   return this->currency;
}

void Employee::printCurrency(Currency currency)const{
  if(currency == 0) cout<<"leva";
   else if(currency == 1) cout<<"euros";
   else if(currency == 2) cout<<"dollars";
   else if(currency == 3) cout<<"pounds";
}

void Employee::printPersonalInformation()const{
   cout<<"name: "<<getName()<<"  egn: "<<getEgn()<<"  salary: "<<salary<<" ";
   printCurrency(this->currency);
   cout<<" work hours: "<<workHours<<" h"<<endl;
}

///***WAITER***///

Waiter::Waiter() = default;

Waiter::Waiter(string _name, string _egn, string _username, string _password, double _salary, Currency _currency, double _workHours, vector<Table> _tables, double _workCapital)
   : Employee(_name, _egn, _username, _password, _salary, _currency, _workHours)
   {
       this->setTables(_tables);
       this->setCapital(_workCapital);
   }

void Waiter::setTables(vector<Table> _tables){
   this->tables = _tables;
}

void Waiter::setCapital(double _workCapital){
   this->workCapital = _workCapital;
}

vector<Table>& Waiter::getTables(){
   return this->tables;
}

double Waiter::getCapital()const{
   return this->workCapital;
}

///***CHEF***///

Chef::Chef() = default;

Chef::Chef(string _name, string _egn, string _username, string _password, double _salary, Currency _currency, double _workHours, ChefType _type)
   : Employee(_name, _egn, _username, _password, _salary, _currency, _workHours)
   {
       this->setType(_type);
   }

void Chef::setType(ChefType _type){
  this->type = _type;
}

ChefType Chef::getChefType()const{
   return this->type;
}

void Chef::printChefType()const{
   if(this->type == 0) cout<<"Executive";
   else if(this->type == 1) cout<<"Sous";
   else if(this->type == 2) cout<<"Senior";
   else if(this->type == 3) cout<<"Sauce";
   else if(this->type == 4) cout<<"Fish";
   else if(this->type == 5) cout<<"Confectioner";
}
