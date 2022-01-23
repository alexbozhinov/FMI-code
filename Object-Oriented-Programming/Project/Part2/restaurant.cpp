#include "restaurant.h"
#include "Products.h"

#include<iostream>
#include<cstring>

using namespace std;

/**Constructors**/
Restaurant::Restaurant() = default;
Restaurant::Restaurant(const char* _name, const char* _address, const char* _phone){

   this->setRestaurantName(_name);
   this->setRestaurantAddress(_address);
   this->setRestaurantPhone(_phone);

}
Restaurant::Restaurant(const char* _name, const char* _address, const char* _phone, Product* _menu, int _menuSize){

   this->setRestaurantName(_name);
   this->setRestaurantAddress(_address);
   this->setRestaurantPhone(_phone);
   this->setRestaurantMenu(_menu);
   this->setMenuSize(_menuSize);

}

/**Destructor**/
Restaurant::~Restaurant(){  ///Not sure if it is correct
    delete[] this->menu;
}

/**copy constructor**/
Restaurant::Restaurant(const Restaurant& other){
  this->setRestaurantName(other.getRestaurantName());
  this->setRestaurantAddress(other.getRestaurantAddress());
  this->setRestaurantPhone(other.getRestaurantPhone());
  this->setRestaurantMenu(other.getRestaurantMenu());
  this->setMenuSize(other.getMenuSize());
}

/**operator=**/
Restaurant& Restaurant::operator=(const Restaurant& other){
   if(this==&other){
    return *this;
   }
  this->setRestaurantName(other.getRestaurantName());
  this->setRestaurantAddress(other.getRestaurantAddress());
  this->setRestaurantPhone(other.getRestaurantPhone());
  this->setRestaurantMenu(other.getRestaurantMenu());
  this->setMenuSize(other.getMenuSize());
  return *this;
}

/**set functions**/
void Restaurant::setRestaurantName(const char* _name){
   strcpy(this->name, _name);
}

void Restaurant::setRestaurantAddress(const char* _address){
   strcpy(this->address, _address);
}

void Restaurant::setRestaurantPhone(const char* _phone){
   strcpy(this->phone, _phone);
}

void Restaurant::setRestaurantMenu(Product* _menu){ ///!
   this->menu = _menu;
}

void Restaurant::setMenuSize(int _menuSize){
   this->menuSize = _menuSize;
}

/**get functions**/
const char* Restaurant::getRestaurantAddress() const{
   return this->address;
}

const char* Restaurant::getRestaurantName()const{
   return this->name;
}

const char* Restaurant::getRestaurantPhone()const{
   return this->phone;
}

int Restaurant::getMenuSize()const{
   return this->menuSize;
}

Product* Restaurant::getRestaurantMenu() const{
   return this->menu;
}

/**print functions**/
void Restaurant::printRestaurantMenu() const{
    for(int i=0;i<menuSize;i++){
         cout<<menu[i]<<endl;
    }
}

void Restaurant::printRestaurantInformation() const{
   cout<<"               Welcome to "<<name<<endl;
   cout<<"               address: "<<address<<endl;
   cout<<"               phone number: "<<phone<<endl;
   cout<<endl<<endl;
}

/**function add new product to the menu**/
void Restaurant::addToMenu(){
   cout<<"How many products would you like to add?: ";
   int howMany;
   cin>>howMany;
   int num, number;
   Category cat;
   char* name = new char[100];
   char* measure= new char[100];
   double price;
   for(int i=0;i<howMany;i++){
        cout<<"Input product number: ";
        cin>>num;
        cout<<"Input product category: ";
        cin>>number;
        Category cat = (Category)number;
        cout<<"Input product name: ";
        cin.ignore();
        cin.getline(name,100,'\n');
        cout<<"Input product measure: ";
        cin.getline(measure,100,'\n');
        cout<<"Input product price: ";
        cin>>price;
        menu[menuSize].setNumber(num);
        menu[menuSize].setCategory(cat);
        menu[menuSize].setName(name);
        menu[menuSize].setMeasure(measure);
        menu[menuSize].setPrice(price);
        menuSize = menuSize+1;
        cout<<"You successfully added "<<menuSize<<"th product into the menu"<<endl;
    }
    delete[] name;
    delete[] measure;
}


