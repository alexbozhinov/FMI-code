#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include "Ingredient.h"
#include "Table.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

///***Person***///
class Person{
public:
    Person();
    Person(string, string, string, string);

    string getName()const;
    string getEgn()const;
    string getUsername()const;
    string getPassword()const;

private:
    void setName(string );
    void setEgn(string );
    void setUsername(string );
    void setPassword(string );

    string name;
    string egn;
    string username;
    string password;
};

///***Employee***///
class Employee : public Person{

public:
    Employee();
    Employee(string, string, string, string, double, Currency, double);
    double getSalary()const;
    double getHours()const;
    Currency getCurrency()const;
    void printPersonalInformation()const;
    void printCurrency(Currency )const;
    void setSalary(double );

private:
    void setCurrency(Currency );
    void setHours(double );

    double salary;
    Currency currency;
    double workHours;
};



///***Waiter***///
class Waiter : public Employee{

public:
   Waiter();
   Waiter(string, string, string, string, double, Currency, double, vector<Table>, double );

   vector<Table>& getTables();
   double getCapital()const;

private:
   void setTables(vector<Table> );
   void setCapital(double );

   vector<Table> tables;
   double workCapital;
};


///***Chef***///

enum ChefType{
   Executive,
   Sous,
   Senior,
   Sauce,
   Fish,
   Confectioner
};

class Chef : public Employee{

public:
    Chef();
    Chef(string, string, string, string, double, Currency, double, ChefType );
    void printChefType()const;
    ChefType getChefType()const;

private:
   void setType(ChefType );

   ChefType type;
};


#endif // PERSON_H_INCLUDED
