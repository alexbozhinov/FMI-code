#include<iostream>
#include<cstring>
using namespace std;


class User{
public:

   User() = default;

   User(const char* _username, const char* _password){
        this->setAllU(_username, _password);
   }

   void setAllU(const char* _username, const char* _password){
      strcpy(this->username, _username);
      strcpy(this->password, _password);
   }

   void printClient(){
      cout<<"Client username: "<<this->username<<endl;
      cout<<endl;
   }

private:
    char username[50];
    char password[20];

};

enum Categories{
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


class Products{
public:

  Products() = default;

  Products(int _num, Categories _cat, const char* _name, const char* _quantity, double _price){
     this->setAllP(_num, _cat, _name, _quantity, _price);
  }

  void setAllP(int _num,Categories _cat, const char* _name, const char* _quantity, double _price){
     this->id = _num;
     this->cat = _cat;
     strcpy(this->name, _name);
     strcpy(this->quantity, _quantity);
     this->price = _price;
  }

  double getPrice() const{
     return this->price;
  }
  const char* getName()const {
     return this->name;
  }

  void printAll(){
    cout<<"No: "<<id<<endl;
    cout<<"Category: "<<cat<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Quantity: "<<quantity<<endl;
    cout<<"Price: "<<price<<endl;
      for(int i=0;i<50;i++) cout<<"-";
            cout<<endl;
  }

private:
  //unsigned int id=0;
  unsigned int id;
  Categories cat;
  char name[50];
  char quantity[50];
  double price;
};

 class Order{
 public:

  Order() = default;

  Order(int _orderNo, int _tableNo, Products _prod, int _quality){
     this->setAllO(_orderNo, _tableNo, _prod, _quality);
  }


  void setAllO(int _orderNo, int _tableNo, Products _prod, int _quality){
      this->orderNo = _orderNo;
      this->tableNo = _tableNo;
      this->prod = _prod;
      this->quality = _quality;
  }

  double finalSum(){
    double sum = 0;
    sum+=prod.getPrice()*quality;
    return sum;
  }

  void printOrder(){
     cout<<endl;
     cout<<"YOUR ORDER: "<<endl;
     cout<<"Order number: "<<orderNo<<endl;
     cout<<"Table number: "<<tableNo<<endl;
     cout<<"Product: "<<prod.getName()<<endl;
     cout<<"Quality: "<<quality<<endl;
     cout<<"Price: "<<prod.getPrice()<<endl;
       for(int i=0;i<50;i++) cout<<"-";
          cout<<endl;
  }

 private:
   Products prod;
   int quality;
   int tableNo;
   int orderNo;
};


int main(){

User user("aleks_bozhinov","1234567890");
user.printClient();

cout<<"             -=MENU=-"<<endl<<endl;
Products product1(1,Salads,"Tomatoes and cheese", "0.500 kg",2.69);
Products product2(2,Drinks,"Orange juice", "0.500 l", 2.39);
Products product3(3,ChickenDishes, "Chicken steak", "0.400 kg", 3.59);

product1.printAll();
product2.printAll();
product3.printAll();

cout<<"                ORDERS"<<endl<<endl;

char check = 'Y';
int num;
int quality1, quality2, quality3;
while(check=='Y'){
cout<<"Choose and input the number of the product and the quality to be ordered:"<<endl;
cout<<"Number of product: "; cin>>num;

if(num == 1) {
   cout<<"Quality: "; cin>>quality1;
   Order order1(1,2,product1,quality1);
   order1.printOrder();
   cout<<"Final price: "<<order1.finalSum()<<endl<<endl;
}
else if(num == 2){
   cout<<"Quality: "; cin>>quality2;
   Order order2(3,5,product2,quality2);
   order2.printOrder();
   cout<<"Final price: "<<order2.finalSum()<<endl<<endl;

}
else {
   cout<<"Quality: ";  cin>>quality3;
   Order order3(4,4,product3,quality3);
   order3.printOrder();
   cout<<"Final price: "<<order3.finalSum()<<endl<<endl;
}
cout<<"Would you make another order? Pres Y for yes or N for no: "; cin>>check;
}


}



