#ifndef STORAGE_H_INCLUDED
#define STORAGE_H_INCLUDED

#include "Ingredient.h"
#include<iostream>
#include<string>
#include<vector>
#include<utility>

using namespace std;

class Storage{

public:
    Storage();
    Storage(vector< pair<Ingredient, double> >);
    vector< pair<Ingredient, double> > getAvailability()const;
    void print()const;

private:
    void setStorage(vector< pair<Ingredient, double> >);
    vector< pair<Ingredient, double> > availability;
};

#endif // STORAGE_H_INCLUDED
