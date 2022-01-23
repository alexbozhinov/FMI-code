#ifndef PRODUCTS_H_INCLUDED
#define PRODUCTS_H_INCLUDED
#include "User.h"
#include<iostream>

using namespace std;
enum Category{
   Drinks,
   Salads,
   Appetizers,
   Soups,
   ChickenDishes,
   BeefDishes,
   PorkDishes,
   FishDishes,
   Delicacies,
   Desserts
};

class Product{

public:
    /**constructors, destructor, copy constructor, operator=**/
    Product();
    Product(int, Category, const char*, const char*, double);
    Product(int, Category, const char*, const char* , double, const char*);
    ~Product();
    Product(const Product& other);
    Product& operator=(const Product& other);

    /**set functions**/
    void setNumber(int );
    void setCategory(Category );
    void setName(const char* );
    void setMeasure(const char* );
    void setPrice(double );
    void setDescription(const char* );

    /**get functions**/
    double getPrice() const;
    const char* getName()const;
    const char* getMeasure()const;
    const char* getDescription()const;
    int getNum()const;
    Category getCat()const;

    /**print and some other functions**/
    char* catInWords()const;

    void sortPrintUp(int, Product []);
    void sortPrintDown(int, Product []);


    void read();
    void printAll()const;

    int temp;
    void add();
    friend ostream& operator << (ostream& os, const Product& r)
{
    os<<"No "<< r.getNum() <<endl;
    os<<"Category: "<<r.getCat()<<endl;
    os<<"Name: "<<r.getName()<<endl;
    os<<"Measure: "<<r.getMeasure()<<endl;
    os<<"Price: "<<r.getPrice()<<endl;

    return os ;
}

private:
    unsigned int num;
    unsigned int id;
    Category cat;
    char name[MAX_LENGTH];
    char measure[MAX_LENGTH];
    double price;
    char description[MAX_LENGTH];
    //int temp;


    void setAllP(int, Category, const char*, const char*, double);
};

#endif // PRODUCTS_H_INCLUDED
