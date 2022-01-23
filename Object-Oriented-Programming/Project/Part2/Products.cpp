#include "Products.h"
#include<iostream>
#include<cstring>

using namespace std;

/**Constructors**/
Product::Product(){};
Product::Product(int _num, Category _cat, const char* _name, const char* _measure, double _price){
        static int currentID = 0;
        id = ++currentID;

        this->setNumber(_num);
        this->setCategory(_cat);
        this->setName(_name);
        this->setMeasure(_measure);
        this->setPrice(_price);
}

Product::Product(int _num, Category _cat, const char* _name, const char* _measure, double _price, const char* _description){
        static int currentID = 0;
        id = ++currentID;

        this->setNumber(_num);
        this->setCategory(_cat);
        this->setName(_name);
        this->setMeasure(_measure);
        this->setPrice(_price);
        this->setDescription(_description);
}


/**Destructor**/
Product::~Product(){  ///Not sure if it is correct.
 delete[] this->name;
 delete[] this->measure;
 //delete this->price;
 //delete this->cat;
 //delete this->num;
}

/**copy constructor**/
Product::Product(const Product& other){
  this->setNumber(other.getNum());
  this->setCategory(other.getCat());
  this->setName(other.getName());
  this->setMeasure(other.getMeasure());
  this->setPrice(other.getPrice());

}

/**operator=**/
Product& Product::operator=(const Product& other){
   if(this==&other){
    return *this;
   }
  this->setNumber(other.getNum());
  this->setCategory(other.getCat());
  this->setName(other.getName());
  this->setMeasure(other.getMeasure());
  this->setPrice(other.getPrice());
  return *this;
}

/**set functions**/
void Product::setAllP(int _num, Category _cat, const char* _name, const char* _measure, double _price){
     this->num = _num;
     this->cat = _cat;
     strcpy(this->name, _name);
     strcpy(this->measure, _measure);
     this->price = _price;
}

void Product::setNumber(int _num){
     this->num = _num;
}

void Product::setCategory(Category _cat){
     this->cat = _cat;
}

void Product::setName(const char* _name){
     strcpy(this->name, _name);
}

void Product::setMeasure(const char* _measure){
     strcpy(this->measure, _measure);
}

void Product::setPrice(double _price){
     this->price = _price;
}

void Product::setDescription(const char* _description){
     strcpy(this->description, _description);
}

/**get functions**/
double Product::getPrice() const{

    return this->price;
}

const char* Product::getName() const{

    return this->name;
}

Category Product::getCat() const{
   return this->cat;
}

int Product::getNum() const{

   return this->num;
}

const char* Product::getMeasure() const{

   return this->measure;
}

const char* Product::getDescription()const{

   return this->description;
}

/**other methods**/
char* Product::catInWords()const{

char* catWords;
int catNum = getCat();
switch(catNum){
   case 0:
       catWords = "Drinks";
       break;
   case 1:
       catWords = "Salads";
       break;
   case 2:
       catWords = "Appetizers";
       break;
   case 3:
       catWords = "Soups";
       break;
   case 4:
       catWords = "Chicken Dishes";
       break;
   case 5:
       catWords = "Beef Dishes";
       break;
   case 6:
       catWords = "Pork Dishes";
       break;
   case 7:
       catWords = "Fish Dishes";
       break;
   case 8:
       catWords = "Delicacies";
       break;
   case 9:
       catWords = "Desserts";
       break;
}
return catWords;
}

/**sort functions**/
void Product::sortPrintUp(int arrSize, Product arr[]){

    for (int i = 0; i < arrSize-1; i++){
       for (int j = 0; j < arrSize-i-1; j++){
           if (arr[j].getPrice() > arr[j+1].getPrice())
               swap(arr[j], arr[j+1]);
       }
}
     for(int i = 0;i < arrSize-1;i++){
        arr[i].printAll();
     }
}

void Product::sortPrintDown(int arrSize, Product arr[]){

    for (int i = 0; i < arrSize-1; i++){
       for (int j = 0; j < arrSize-i-1; j++){
           if (arr[j].getPrice() < arr[j+1].getPrice())
               swap(arr[j], arr[j+1]);
       }
}
     for(int i = 0;i < arrSize-1;i++){
        arr[i].printAll();
     }
}

/**print function**/
void Product::printAll()const{
    char* catW = catInWords();
    cout<<"No: "<<num<<endl;
    cout<<"Category: "<<catW<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Quantity: "<<measure<<endl;
    cout<<"Price: "<<price<<endl;
    cout<<"Description: "<<description<<endl;
      for(int i=0;i<50;i++) cout<<"-";
            cout<<endl;
}
