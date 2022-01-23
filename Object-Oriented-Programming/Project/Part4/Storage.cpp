#include "Ingredient.h"
#include "Storage.h"
#include<iostream>
#include<string>
#include<vector>
#include<utility>

using namespace std;

Storage::Storage() = default;

Storage::Storage(vector< pair<Ingredient, double> > _availability){
   this->setStorage(_availability);
}

void Storage::setStorage(vector< pair<Ingredient, double> > _availability){
   this->availability = _availability;
}

vector< pair<Ingredient, double> > Storage::getAvailability()const{
   return this->availability;
}

void Storage::print()const{
cout<<"__________________________STORAGE_____________________________"<<endl<<endl;
cout<<"Ingrdient:             Price/Measure             Availability:"<<endl<<endl;
for(int i=0;i<availability.size();i++){
    availability[i].first.printStorage();
    cout<<"                  ";
    cout<<availability[i].second<<" ";
    availability[i].first.printMeasure();
    cout<<endl;
}
}
