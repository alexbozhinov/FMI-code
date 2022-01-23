#ifndef BUDGET_H_INCLUDED
#define BUDGET_H_INCLUDED

#include "Ingredient.h"
#include "Item.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Budget{

public:
    Budget();
    Budget(double, double, double, double, Currency);

    double& getIngredientOutcome();
    double& getSalaryOutcome();
    double& getOnlineIncome();
    double& getPlaceIncome();
    double& getBalance();
    void setBalance(double, double, double, double );

    void print()const;
    void printCurrency(Currency )const;

private:
    void setIngredientOutcome(double );
    void setSalaryOutcome(double );
    void setOnlineIncome(double );
    void setPlaceIncome(double );
    void setCurrency(Currency );

    double ingredientOutcome;
    double salaryOutcome;
    double onlineIncome;
    double placeIncome;
    double balance;
    Currency currency;
};

#endif // BUDGET_H_INCLUDED
