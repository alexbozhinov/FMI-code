#include "User.h"
#include "Products.h"
#include "Orders.h"
#include "addProducts.h"
#include "onlineOrder.h"
#include "restaurant.h"
#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstring>
#include<limits>
#include<stdlib.h>

using namespace std;

int main(){
//https://stackoverflow.com/questions/19511734/c-dynamic-array-of-objects-sorting-by-property

User user("aleks_bozhinov","1234567890");
user.printClient();

Restaurant restaurant;
restaurant.setMenuSize(10);
restaurant.setRestaurantName("Aleks's restaurant");
restaurant.setRestaurantAddress("Gorna Oryahovitsa, Bulgaria");
restaurant.setRestaurantPhone("0123456789");
restaurant.printRestaurantInformation();

cout<<endl<<endl<<"1. MENU"<<endl;
cout<<endl<<endl<<"2. Exit"<<endl;
int choice1[10];
cout<<endl<<endl<<"Input your choice here: ";
cin>>choice1[0];
	while(true)
	{

       if(choice1[0]!=1&&choice1[0]!=2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice1[0]; continue;}
		else
		{
			break;
		}
	}
if(choice1[0]==2) {cout<<endl<<"You closed restaurant's page."<<endl;
                         return 0;}
if(choice1[0]==1){
        system("CLS");

cout<<"                                 -=MENU=-"<<endl<<endl;


Product* products = new Product[restaurant.getMenuSize()]; ///Firstly products was the array which was reading info from products.txt. I put freopen in comment for now and write my products by
/// the Product constructor. I will try letter to do the freopen reading from file, but for the moment it causes me problems with cin>>;

/** Here is the problem part.
freopen("products.txt","r",stdin);
int number;
int num;
Category cat;
double price;
char* name = new char[100];
char* measure = new char[100];
for(int i=0;i<restaurant.getMenuSize();i++){
    cin>>num;
    cin>>number;
    Category cat = (Category)number;
    cin.ignore();
    cin.getline(name,100,'\n');
    cin.getline(measure,100,'\n');
    cin>>price;
    products[i] = Product(num, cat, name, measure, price);
}
delete[] name;
delete[] measure;
fclose(stdin);
**/

products[0] = Product(1, Salads, "Tomatoes with cheese", "0.500 kg", 2.69);
products[1] = Product(2, Drinks, "Orange juice", "0.500 l", 2.39);
products[2] = Product(3, ChickenDishes, "Chicken steak", "0.400 kg", 3.59);
products[3] = Product(4, Desserts, "Chocolate cake", "0.350 kg", 2.89);
products[4] = Product(5, FishDishes, "Royal shrimps", "0.500 kg", 7.79);
products[5] = Product(6, Soups, "Borscht", "0.400 kg", 3.19);
products[6] = Product(7, BeefDishes, "Beef goulash", "0.500 kg", 7.29);
products[7] = Product(8, PorkDishes, "Pork chops with radishes and charred scallions", "0.400 kg", 6.79);
products[8] = Product(9, FishDishes, "Steamed salmon", "0.350 kg", 7.39);
products[9] = Product(10, Salads, "French salad", "0.450 kg", 5.79);



for(int i=0;i<restaurant.getMenuSize();i++){

    restaurant.getRestaurantMenu()[i] = products[i];

}

restaurant.printRestaurantMenu();
/**First page**/
    cout<<endl<<endl<<"1. Add new product";
    cout<<endl<<endl<<"2. Order a product by number";
    cout<<endl<<endl<<"3. Sort products by price (from lowest to highest)";
    cout<<endl<<endl<<"4. Sort products by price (from highest to lowest)";
    cout<<endl<<endl<<"5. Exit";
    cout<<endl<<endl<<"Input your choice here: ";
    cin>>choice1[1];
	while(true)
	{
       if(choice1[1]!=1&&choice1[1]!=2&&choice1[1]!=3&&choice1[1]!=4&&choice1[1]!=5){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice1[1]; continue;}
		else
		{
			break;
		}
	}



/** page: add new product**/

if(choice1[1]==1) {
                    system("CLS");
                    cout<<"You choose to add a new product."<<endl;
                    restaurant.addToMenu();
                    cout<<endl<<endl<<"1. Show the new menu"<<endl;
                    cout<<endl<<endl<<"2. Exit"<<endl;
                    cout<<endl<<endl<<"Input your choice here: ";
                    cin>>choice1[2];

                    while(true)
	{
       if(choice1[1]!=1&&choice1[1]!=2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice1[2]; continue;}
		else
		{
			break;
		}
	}

                    if(choice1[2]==2) { cout<<"You closed restaurant's page."<<endl; return 0;}
                    if(choice1[2]==1){


                    system("CLS");
                    cout<<endl<<endl<<"                                 -=MENU=-"<<endl<<endl;

                    restaurant.printRestaurantMenu();



                    cout<<endl<<endl<<"1. Order a product by number";
                    cout<<endl<<endl<<"2. Exit";
                    cout<<endl<<endl<<"Input your choice here: ";
                    cin>>choice1[5];
                   while(true)
	                  {
                          if(choice1[5]!=1&&choice1[5]!=2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice1[5]; continue;}
		                    else
		                            {
			                 break;
		                            }
	                  }
                    if(choice1[5] == 2){
                        cout<<"You closed restaurant's page."<<endl; return 0;
                    }
                    if(choice1[5] == 1){
                                            system("CLS");
                    cout<<"You choose to order product."<<endl;
                    int productNum, productQuantity, tableNum;
                    cout<<"Input the number of the product you chose: ";
                    cin>>productNum;                                            /**should add validation for inexistent product numbers**/
                    cout<<"Input quantity: ";
                    cin>>productQuantity;
                    cout<<"Input table number: ";
                    cin>>tableNum;
                    Order order(productNum, tableNum, restaurant.getRestaurantMenu()[productNum-1] ,productQuantity);
                    order.printOrder();
                    cout<<"Final price: "<<order.finalSum()<<endl;

                  }
    }
}





/** page: order product by number**/
if(choice1[1]==2) {
                    system("CLS");
                    cout<<"You choose to order product."<<endl;
                    int productNum, productQuantity, tableNum;
                    cout<<"Input the number of the product you chose: ";
                    cin>>productNum;
                    /**for(int i=0;i<restaurant.getMenuSize();i++){
                        if(productNum!= restaurant.getRestaurantMenu()[i].getNum()) {cout<<"You have inputted an inexistent product number"<<endl; return 0;}
                    }**/
                                                                                  /**should add validation for inexistent product numbers**/
                    cout<<"Input quantity: ";
                    cin>>productQuantity;
                    cout<<"Input table number: ";
                    cin>>tableNum;
                    Order order(productNum, tableNum, restaurant.getRestaurantMenu()[productNum-1] ,productQuantity);
                    order.printOrder();
                    cout<<"Final price: "<<order.finalSum()<<endl;

                  }


/**page: first sort type**/
if(choice1[1]==3) {
                    system("CLS");
                    cout<<"You chose to sort products by price (from lowest to highest)"<<endl;
                    cout<<endl<<endl<<"                                 -=MENU=-"<<endl<<endl;
                    restaurant.getRestaurantMenu()->sortPrintUp(restaurant.getMenuSize(), restaurant.getRestaurantMenu());
                    cout<<endl<<endl<<"1. Order a product by number";
                    cout<<endl<<endl<<"2. Exit";
                    cout<<endl<<endl<<"Input your choice here: ";
                    cin>>choice1[3];
                   while(true)
	                  {

                          if(choice1[3]!=1&&choice1[3]!=2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice1[3]; continue;}
		                    else
		                            {
			                 break;
		                            }
	                  }
                    if(choice1[3] == 2){
                        cout<<"You closed restaurant's page."<<endl; return 0;
                    }
                    if(choice1[3] == 1){
                                            system("CLS");
                    cout<<"You choose to order product."<<endl;
                    int productNum, productQuantity, tableNum;
                    cout<<"Input the number of the product you chose: ";
                    cin>>productNum;                                            /**should add validation for  product numbers**/
                    cout<<"Input quantity: ";
                    cin>>productQuantity;
                    cout<<"Input table number: ";
                    cin>>tableNum;
                    Order order(productNum, tableNum, restaurant.getRestaurantMenu()[productNum-1] ,productQuantity);
                    order.printOrder();
                    cout<<"Final price: "<<order.finalSum()<<endl;

                  }

            }


/**page: second sort type**/

if(choice1[1]==4) {
                    system("CLS");
                    cout<<"You chose to sort products by price (from highest to lowest)"<<endl;
                    cout<<"                                 -=MENU=-"<<endl<<endl;
                    restaurant.getRestaurantMenu()->sortPrintDown(restaurant.getMenuSize(), restaurant.getRestaurantMenu());


                    cout<<endl<<endl<<"1. Order a product by number";
                    cout<<endl<<endl<<"2. Exit";
                    cout<<endl<<endl<<"Input your choice here: ";
                    cin>>choice1[4];
                   while(true)
	                  {

                          if(choice1[4]!=1&&choice1[4]!=2){   cout<<"Incorrect input! Try again! Input your choice here: "; cin>>choice1[4]; continue;}
		                    else
		                            {
			                 break;
		                            }
	                  }
                    if(choice1[4] == 2){
                        cout<<"You closed restaurant's page."<<endl; return 0;
                    }
                    if(choice1[4] == 1){
                                            system("CLS");
                    cout<<"You choose to order product."<<endl;
                    int productNum, productQuantity, tableNum;
                    cout<<"Input the number of the product you chose: ";
                    cin>>productNum;                                            //should add validation for unreal product numbers
                    cout<<"Input quantity: ";
                    cin>>productQuantity;
                    cout<<"Input table number: ";
                    cin>>tableNum;
                    Order order(productNum, tableNum, restaurant.getRestaurantMenu()[productNum-1] ,productQuantity);
                    order.printOrder();
                    cout<<"Final price: "<<order.finalSum()<<endl;

                  }



                   }
/** page: Exit**/
if(choice1[1]==5){cout<<"You closed restaurant's page."<<endl; return 0; }

}



//fclose(stdin);
/*int how;
cin>>how;
cout<<how;*/
//restaurant.addToMenu();
//restaurant.printRestaurantMenu();
//restaurant.setRestaurantMenu(products, restaurant.getMenuSize);

//restaurant.setRestaurantMenu(products, restaurant.getMenuSize());


/*
products[0] = Product(1,Salads,"Tomatoes with cheese", "0.450 kg", 4.29); productsSize++;
products[1] = Product(2,BeefDishes,"Beef goulash", "0.400 kg", 5.39);productsSize++;
products[2] = Product(3,Drinks,"Orange juice", "0.300 l", 2.29);productsSize++;
*/
/*
for(int i=0;i<productsSize;i++){
    products[i].printAll();
*/
/*
char buttonSort;
cout<<"If you want to sort the products by price from lower to higher press: 1"<<endl;
cout<<"If you want to sort the products by price from higher to lower press: 2"<<endl;
cout<<"If you do not want to sort the products press: 0"<<endl;
cout<<"Input your choice here: ";
cin>>buttonSort;*/

 /*           while(1){
              if( cin.fail() ){
                 cin.clear();
                 cin.ignore(numeric_limits<streamsize>::max(),'\n');
                 continue;
                 }
              if(buttonSort!='0'){
                 cout << "Your input code is incorrect! Try with 0,1 or 2" << endl;
                 cout<<"If you want to sort the products by price from lower to higher press: 1"<<endl;
                 cout<<"If you want to sort the products by price from higher to lower press: 2"<<endl;
                 cout<<"If you do not want to sort the products press: 0"<<endl;
                 cout<<"Input your choice here: ";
                         cin>>buttonSort;
                      continue;
                 }
             if( !cin.fail() )
                 break;
                 }
*/
/*
addProduct arr;
for(int i=0;i<productsSize;i++){
    arr.add(products[i]);
}
Product prod = Product(11,Salads,"Shpska","0.450 kg", 4.59);
arr.add(prod);
*/

/*
for(int i=0;i<productsSize;i++){
    products[i].printAll();
}*/
/*
cout<<"UUUUUUUUUUUUUUUPPPPPPPPPPPPPPPPPPPPPPP"<<endl;
products->sortPrintUp(productsSize, products);
cout<<"DDDDDDDOOOOOOOOWWWWWWWWNNNNNNNN"<<endl;
products->sortPrintDown(productsSize, products);*/
/*
Product prod = Product(11,Salads,"Shpska","0.450 kg", 4.59);
prod.addProduct(products,productsSize,prod);
products[9].printAll();*/

/*
cout<<"                ORDERS"<<endl<<endl;

char check = 'Y';
int num;
int quantity1, quantity2, quantity3;
while(check=='Y'){
cout<<"Choose and input the number of the product and the quantity to be ordered:"<<endl;
cout<<"Number of product: "; cin>>num;

if(num == 1) {
   cout<<"Quantity: "; cin>>quantity1;
   Order order1(1,2,products[0],quantity1);
   order1.printOrder();
   cout<<"Final price: "<<order1.finalSum()<<endl<<endl;
}
else if(num == 2){
   cout<<"Quantity: "; cin>>quantity2;
   Order order2(3,5,products[1],quantity2);
   order2.printOrder();
   cout<<"Final price: "<<order2.finalSum()<<endl<<endl;

}
else {
   cout<<"Quantity: ";  cin>>quantity3;
   Order order3(4,4,products[2],quantity3);
   order3.printOrder();
   cout<<"Final price: "<<order3.finalSum()<<endl<<endl;
}
cout<<"Would you make another order? Pres Y for yes or N for no: "; cin>>check;
}
*/

/*
cout<<"ONLINE ORDER"<<endl;
onlineOrder onOrder;
onlineOrder.push(products[1]);
onlineOrder.peek();
*/
}


