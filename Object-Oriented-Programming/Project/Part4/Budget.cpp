#include "Ingredient.h"
#include "Item.h"
#include<iostream>
#include<string>
#include<vector>
#include "Budget.h"

using namespace std;

Budget::Budget(){
    ingredientOutcome = 0.0;
    salaryOutcome = 0.0;
    onlineIncome = 0.0;
    placeIncome = 0.0;
    balance = 0.0;
    currency = lev;
}

Budget::Budget(double _ingredientOutcome, double _salaryOutcome, double _onlineIncome, double _placeIncome, Currency _currency){
   this->setIngredientOutcome(_ingredientOutcome);
   this->setSalaryOutcome(_salaryOutcome);
   this->setOnlineIncome(_onlineIncome);
   this->setPlaceIncome(_placeIncome);
   this->setBalance(_ingredientOutcome, _salaryOutcome, _onlineIncome, _placeIncome);
   this->setCurrency(_currency);
}

void Budget::setIngredientOutcome(double _ingredientOutcome){
   this->ingredientOutcome = _ingredientOutcome;
}

void Budget::setSalaryOutcome(double _salaryOutcome){
   this->salaryOutcome = _salaryOutcome;
}

void Budget::setOnlineIncome(double _onlineIncome){
   this->onlineIncome = _onlineIncome;
}

void Budget::setPlaceIncome(double _placeIncome){
   this->placeIncome = _placeIncome;
}

void Budget::setBalance(double _ingredientOutcome, double _salaryOutcome, double _onlineIncome, double _placeIncome){
   this->balance = - _ingredientOutcome - _salaryOutcome + _onlineIncome + _placeIncome;
}

void Budget::setCurrency(Currency _currency){
   this->currency = _currency;
}

double& Budget::getIngredientOutcome(){
   return this->ingredientOutcome;
}

double& Budget::getSalaryOutcome(){
   return this->salaryOutcome;
}

double& Budget::getOnlineIncome(){
   return this->onlineIncome;
}

double& Budget::getPlaceIncome(){
   return this->placeIncome;
}

double& Budget::getBalance(){
   return this->balance;
}

void Budget::printCurrency(Currency currency)const{
  if(currency == 0) cout<<"leva";
   else if(currency == 1) cout<<"euros";
   else if(currency == 2) cout<<"dollars";
   else if(currency == 3) cout<<"pounds";
}

void Budget::print()const{
   cout<<"---------------------------------BUDGET--------------------------------"<<endl<<endl;
   cout<<"OUTCOMES:_____________________________INCOMES:_________________________"<<endl<<endl;
   cout<<"Paid for ingredients: "<<ingredientOutcome*(-1)<<" ";
   printCurrency(currency);
   cout<<"       "<<"Online orders: "<<onlineIncome<<" ";
   printCurrency(currency);
   cout<<endl<<endl;
   cout<<"Employee salaries: "<<salaryOutcome*(-1)<<" ";
   printCurrency(currency);
   cout<<"         "<<"Orders in restaurant: "<<placeIncome<<" ";
   printCurrency(currency);
   cout<<endl<<endl;
   cout<<"======================================================================"<<endl<<endl;
   cout<<"                       BALANCE: "<<balance<<" ";
   printCurrency(currency);
   cout<<endl;
}
