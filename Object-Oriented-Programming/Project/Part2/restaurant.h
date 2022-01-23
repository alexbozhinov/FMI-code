#ifndef RESTAURANT_H_INCLUDED
#define RESTAURANT_H_INCLUDED

#include  "Products.h"

class Restaurant{

public:
    /**constructors, destructor, copy constructor, operator=**/
    Restaurant();
    Restaurant(const char*, const char*, const char*);
    Restaurant(const char*, const char*, const char*, Product*, int);
    ~Restaurant();
    Restaurant(const Restaurant& other);
    Restaurant& operator=(const Restaurant& other);

   /**set functions**/
    void setRestaurantName(const char* );
    void setRestaurantAddress(const char* );
    void setRestaurantPhone(const char* );
    void setRestaurantMenu(Product*);
    void setMenuSize(int );

  /**get functions**/
    const char* getRestaurantName() const;
    const char* getRestaurantAddress() const;
    const char* getRestaurantPhone() const;
    Product* getRestaurantMenu() const;
    int getMenuSize() const;

  /**print functions**/
    void printRestaurantInformation() const;
    void printRestaurantMenu() const;

    /**operator <<**/
    friend ostream& operator << (ostream& os, const Restaurant& r)
{
    os<<r.getRestaurantMenu() <<endl;
    return os ;
}
    /**other methods**/
    void read();
    void addToMenu() ;

private:
    char name[50];
    char address[50];
    char phone[20];
    Product* menu = new Product[100];
    int menuSize;
};

#endif // RESTAURANT_H_INCLUDED
