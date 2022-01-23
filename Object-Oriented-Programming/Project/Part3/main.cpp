#include<iostream>
#include "MyString.h"
#include "MyArray.h"
//#include "MyArray.cpp"
#include "User.h"
#include "Ingredient.h"
#include "FoodItem.h"
#include "Salad.h"
#include "Menu.h"
#include "Restaurant.h"
#include "USER_MENU.h"
#include "ADMIN_MENU.h"
#include "CLIENT_MENU.h"
#include "Cart.h"
#include "OnlineOrder.h"

using namespace std;

int main(){

    User us1("alex2000", "1234567890");
    User us2("programmer10", "223344");
    User us3("admin", "ADMIN");
    MyArray<User> user;
    user.addBack(us1); user.addBack(us2); user.addBack(us3);

   Ingredient i11("tomato", 20.0, 2.65);
   Ingredient i12("cucumber", 30.0, 2.25);
   Ingredient i13("onion", 45.0, 3.20);
   Ingredient i14("garlic", 40.0, 3.40);
   Ingredient i15("pepper", 50.0, 3.50);
   Ingredient i16("potato", 100.0, 2.50);
   Ingredient i17("lettuce", 25.0, 0.90);
   Ingredient i18("cabbage", 20.0, 1.80);
   Ingredient i19("corn", 25.0, 3.25);
   Ingredient i10("mushrooms", 40.0, 4.55);

   Ingredient i21("salt", 46.8, 2.49);
   Ingredient i22("black pepper", 20.5, 3.69);
   Ingredient i23("parsley", 55.0, 0.90);
   Ingredient i24("celery", 40.0, 1.59);
   Ingredient i25("oil", 55.5, 3.69);
   Ingredient i26("savory", 40.0, 3.69);
   Ingredient i27("vinegar", 25.5, 3.89);
   Ingredient i28("basil", 33.1, 4.59);
   Ingredient i29("ginger", 25.0, 3.79);
   Ingredient i20("saffron", 40.0, 100.0);

   Ingredient i31("chicken meat", 40.0, 6.89);
   Ingredient i32("chicken fillet", 45.0, 7.29);
   Ingredient i33("chicken wings", 48.0, 6.89);
   Ingredient i34("fish meat", 25.0, 6.79);

   Ingredient i41("flour", 40.0, 2.89);
   Ingredient i42("egg", 50.0, 0.25);
   Ingredient i43("sugar", 50.0, 2.59);
   Ingredient i44("Chocolate", 45.0, 3.89);
   Ingredient i45("vanilla", 30.5, 2.99);
   Ingredient i46("baking powder", 30.0, 1.29);
   Ingredient i47("whipped cream", 50.0, 3.65);
   Ingredient i48("cinnamon", 45.0, 2.65);
   Ingredient i49("cherry", 40.0, 3.89);
   Ingredient i40("apple", 50.0, 2.69);

   MyArray<Ingredient> arr11;
   arr11.addBack(i11); arr11.addBack(i12); arr11.addBack(i13); arr11.addBack(i25);
   FoodItem f11("Shopska salata", arr11, 4.50, 0.500, 0.05);

   MyArray<Ingredient> arr12;
   arr12.addBack(i11); arr12.addBack(i12); arr12.addBack(i13); arr12.addBack(i15); arr12.addBack(i19); arr12.addBack(i10); arr12.addBack(i21); arr12.addBack(i25); arr12.addBack(i42);
   FoodItem f12("Ovcharska salata", arr12, 3.70, 0.350, 0.05);

   MyArray<Ingredient> arr13;
   arr13.addBack(i17); arr13.addBack(i21); arr13.addBack(i25); arr13.addBack(i27);
   FoodItem f13("Proletna zelena salata",arr13, 4.00, 0.400, 0.05);

   MyArray<Ingredient>arr22;
   arr22.addBack(i31); arr22.addBack(i15); arr22.addBack(i21); arr22.addBack(i25); arr22.addBack(i13); arr22.addBack(i23);
   FoodItem f21("Chicken soup", arr22, 3.80, 0.350, 0.1);

   MyArray<Ingredient>arr21;
   arr21.addBack(i14); arr21.addBack(i15); arr21.addBack(i16); arr21.addBack(i21);arr21.addBack(i11);
   FoodItem f22("Soup with vegetables", arr21, 2.90,0.350,0.2);

   MyArray<Ingredient> arr23;
   arr23.addBack(i13); arr23.addBack(i21); arr23.addBack(i34);
   FoodItem f23("Fish soup", arr23, 4.20, 0.400, 0.3);

   MyArray<Ingredient> arr33;
   arr33.addBack(i32); arr33.addBack(i21); arr33.addBack(i16); arr33.addBack(i22);
   FoodItem f31("Chicken steak with fried potatoes", arr33, 7.60, 0.450, 0.2);

   MyArray<Ingredient> arr31;
   arr31.addBack(i33);
   FoodItem f32("Fried chicken wings", arr31, 6.99, 0.400, 0.1);

   MyArray<Ingredient> arr32;
   arr32.addBack(i32);
   FoodItem f33("Fried chicken fillets", arr32, 7.19,0.400, 0.3);

   MyArray<Ingredient> arr44;
   arr44.addBack(i41); arr44.addBack(i42); arr44.addBack(i43); arr44.addBack(i46); arr44.addBack(i47); arr44.addBack(i49);
   FoodItem f41("Vanilla cake", arr44, 4.20, 0.250, 1.0);

   MyArray<Ingredient> arr41;
   arr41.addBack(i41); arr41.addBack(i42); arr41.addBack(i43); arr41.addBack(i46); arr41.addBack(i44); arr41.addBack(i49);
   FoodItem f42("Chocolate cake", arr41, 4.70, 0.300, 1.5);

   MyArray<Ingredient> arr42;
   arr42.addBack(i41); arr42.addBack(i42); arr42.addBack(i43); arr42.addBack(i46); arr42.addBack(i40);
   FoodItem f43("Apple pie", arr42, 3.90, 0.300, 1.0);

   MyArray<FoodItem> salads;
   salads.addBack(f11); salads.addBack(f12); salads.addBack(f13);
   Salad salad(salads);

   MyArray<FoodItem> soups;
   soups.addBack(f21); soups.addBack(f22); soups.addBack(f23);
   Soup soup(soups);

   MyArray<FoodItem> chickenDishes;
   chickenDishes.addBack(f31); chickenDishes.addBack(f32); chickenDishes.addBack(f33);
   ChickenDish chickenDish(chickenDishes);

   MyArray<FoodItem> desserts;
   desserts.addBack(f41); desserts.addBack(f42); desserts.addBack(f43);
   Dessert dessert(desserts);

   Menu menu(salad, soup, chickenDish, dessert);


   Restaurant restaurant("ALEKS'S RESTAURANT", "Gorna Oryahovitsa","aleks.restaurant@gmail.com","www.aleksrestaurant.bg",menu,user);
   restaurant.printRestaurantData();

   ///CART AND ORDER TEST///
   /*
   Cart cart(restaurant.getMenu().getAllSalads().getSalads());
   cart.printCart();
   OnlineOrder order(cart);
   order.printOnlineOrder();
    */
   ///****************************************************///

   usersInput(restaurant); /// First page of the program
}
