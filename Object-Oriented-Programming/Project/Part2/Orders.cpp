#include "Orders.h"
#include "Products.h"
#include<iostream>

using namespace std;

/**constructors**/
Order::Order() = default;
Order::Order(int _orderNo, int _tableNo, Product _prod, int _quantity){

       this->setOrderNo(_orderNo);
       this->setTableNo(_tableNo);
       this->setProduct(_prod);
       this->setQuantity(_quantity);
}

/**set functions**/
void Order::setAllO(int _orderNo, int _tableNo, Product _prod, int _quantity){

      this->orderNo = _orderNo;
      this->tableNo = _tableNo;
      this->prod = _prod;
      this->quantity = _quantity;
}

void Order::setOrderNo(int _orderNo){
      this->orderNo = _orderNo;
}

void Order::setTableNo(int _tableNo){
      this->tableNo = _tableNo;
}

void Order::setProduct(Product _prod){
      this->prod = _prod;
}

void Order::setQuantity(int _quantity){
      this->quantity = _quantity;
}

/**final sum method**/
double Order::finalSum(){

     double sum = 0;
     sum+=prod.getPrice()*quantity;
     return sum;
}

/**print order bill**/
void Order::printOrder()const{

     cout<<endl;
     cout<<"YOUR ORDER: "<<endl;
     cout<<"Product number: "<<orderNo<<endl;
     cout<<"Table number: "<<tableNo<<endl;
     cout<<"Product: "<<prod.getName()<<endl;
     cout<<"Quantity: "<<quantity<<endl;
     cout<<"Price: "<<prod.getPrice()<<endl;
        for(int i=0;i<50;i++) cout<<"-";
           cout<<endl;
}
