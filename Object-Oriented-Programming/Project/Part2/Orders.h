#ifndef ORDERS_H_INCLUDED
#define ORDERS_H_INCLUDED
#include "Products.h"

class Order{

public:

    /**constructors**/
    Order();
    Order(int, int, Product, int);

    /**set functions**/
    void setOrderNo(int );
    void setTableNo(int );
    void setProduct(Product );
    void setQuantity(int );

    /**final sum method**/
    double finalSum();

    /**print order bill**/
    void printOrder()const;

private:

    /**fields and big set function**/
   Product prod;
   int quantity;
   int tableNo;
   int orderNo;

   void setAllO(int, int, Product, int);

};




#endif // ORDERS_H_INCLUDED
