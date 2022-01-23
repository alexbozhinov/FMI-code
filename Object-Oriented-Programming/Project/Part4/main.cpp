#include "Budget.h"
#include "Cart.h"
#include "Ingredient.h"
#include "Item.h"
#include "Menu.h"
#include "OnlineOrder.h"
#include "Order.h"
#include "Person.h"
#include "Storage.h"
#include "Table.h"
#include "User.h"
#include<iostream>
#include<string>
#include<vector>
#include "Restaurant.h"
#include "Main_Menu.h"

using namespace std;

int main(){

///***MAIN FUNCTION***///

///***INGREDIENTS DECLARATION***///
Ingredient i1("tomato", 15.0, kg, 2.50, lev);
Ingredient i2("cucumber", 20.0, kg, 2.20, lev);
Ingredient i3("pepper", 30.0, kg, 2.80, lev);
Ingredient i4("onion", 30.0, kg, 3.00, lev);
Ingredient i5("garlic", 20.0, kg, 3.20, lev );
Ingredient i6("potato", 50.0, kg, 2.20, lev);
Ingredient i7("lettuce", 30.0, piece, 0.50, lev);
Ingredient i8("cabbage", 30.0, kg, 1.20, lev);
Ingredient i9("corn", 2.0, kg, 3.90, lev);
Ingredient i10("mushroom", 7.0, kg, 3.85, lev);
Ingredient i11("carrot", 45, piece, 0.40, lev);
Ingredient i12("pea", 4.0, kg, 3.20, lev);
Ingredient i13("salt", 3.0, kg, 2.80, lev);
Ingredient i14("sugar", 4.0 , kg, 1.95, lev);
Ingredient i15("black pepper", 0.500, kg, 2.75, lev);
Ingredient i16("parsley", 50.0, piece, 0.20, lev);
Ingredient i17("celery", 25.0, piece, 0.25, lev);
Ingredient i18("oil", 20.0, bottle, 2.40, lev);
Ingredient i19("savory", 1.5, kg, 3.60, lev);
Ingredient i20("vinegar", 5.0, bottle, 2.50, lev);
Ingredient i21("basil", 0.800, kg, 1.50, lev);
Ingredient i22("ginger", 0.700, kg, 1.80, lev);
Ingredient i23("saffron", 0.300, kg, 40.0, lev);
Ingredient i24("chicken meat", 15.0, kg, 3.20, lev);
Ingredient i25("chicken fillet", 45.0, piece, 2.00, lev);
Ingredient i26("chicken wings", 40.0, piece, 0.90, lev);
Ingredient i27("fish", 20.0, piece, 3.50, lev);
Ingredient i28("beef meat", 20.0, kg, 6.80, lev);
Ingredient i29("beef cutlet", 30.0, piece, 2.10, lev);
Ingredient i30("flour", 25.0, kg, 1.00, lev);
Ingredient i31("egg", 100.0, piece, 0.18, lev);
Ingredient i32("chocolate",3.00, kg, 3.80, lev);
Ingredient i33("vanilla", 0.400, kg,  0.75, lev);
Ingredient i34("baking powder", 0.300, kg, 0.45, lev);
Ingredient i35("whipped cream", 4.0, kg, 2.80, lev);
Ingredient i36("cinnamon", 0.400, kg, 1.20, lev);
Ingredient i37("cherry", 1.00, kg, 3.30, lev);
Ingredient i38("apple", 2.00, kg,  2.20, lev);
Ingredient i39("lemon", 4.0, piece, 0.80, lev);
Ingredient i40("honey", 3.0, kg, 6.80, lev);
Ingredient i41("rice", 5.0, kg, 1.60, lev);
Ingredient i42("cheese", 3.50, kg, 4.50, lev);
Ingredient i43("milk", 3.0, l, 1.20, lev);

///***ITEMS DECLARATION***///
vector<Ingredient> ing1,ing2,ing3,ing4,ing5,ing6,ing7,ing8,ing9,ing10,ing11,ing12,ing13,ing14,ing15,ing16,ing17,ing18;
ing1.push_back(i1); ing1.push_back(i2);ing1.push_back(i4);ing1.push_back(i42);
ing2.push_back(i1); ing2.push_back(i2);ing2.push_back(i4);ing2.push_back(i3);ing2.push_back(i9);ing2.push_back(i10);ing2.push_back(i42);
ing3.push_back(i4); ing3.push_back(i6);ing3.push_back(i16);
ing4.push_back(i4); ing4.push_back(i3);ing4.push_back(i11);ing4.push_back(i24);ing4.push_back(i16);ing4.push_back(i17);
ing5.push_back(i1); ing5.push_back(i3);ing5.push_back(i4);ing5.push_back(i6);ing5.push_back(i11); ing5.push_back(i16); ing5.push_back(i17);
ing6.push_back(i27); ing6.push_back(i39); ing6.push_back(i18);
ing7.push_back(i24); ing7.push_back(i6); ing7.push_back(i1); ing7.push_back(i2);
ing8.push_back(i26);
ing9.push_back(i25);
ing10.push_back(i28); ing10.push_back(i41); ing10.push_back(i9); ing10.push_back(i11); ing10.push_back(i12);
ing11.push_back(i29); ing11.push_back(i6); ing11.push_back(i1); ing11.push_back(i2);
ing12.push_back(i28); ing12.push_back(i6); ing12.push_back(i1); ing12.push_back(i4);ing12.push_back(i15);
ing13.push_back(i27); ing13.push_back(i6); ing13.push_back(i39);
ing14.push_back(i27); ing14.push_back(i1); ing14.push_back(i39);
ing15.push_back(i27); ing15.push_back(i41); ing15.push_back(i11); ing15.push_back(i12);
ing16.push_back(i30); ing16.push_back(i14); ing16.push_back(i43); ing16.push_back(i31); ing16.push_back(i33); ing16.push_back(i34); ing16.push_back(i35); ing16.push_back(i37);
ing17.push_back(i30); ing17.push_back(i14); ing17.push_back(i31); ing17.push_back(i43); ing17.push_back(i32); ing17.push_back(i34); ing17.push_back(i37);
ing18.push_back(i30); ing18.push_back(i14); ing18.push_back(i31); ing18.push_back(i34); ing18.push_back(i38);

FoodItem f1("Shopska salata", 0.400, kg, 3.40, lev, Salad, ing1, 5.0, "Firs chop the tomatoes and the cucumbers and add onion and cheese");
FoodItem f2("Ovcharska salata", 0.450, kg, 5.20, lev, Salad, ing2, 10.0,"Firs chop the tomatoes and the cucumbers and add onion and cheese. Then add some mushrooms, pepper and corn" );
FoodItem f3("Salad with potato", 0.350, kg, 3.00, lev, Salad, ing3, 20.0, "Boil some potato in hot water. Add onion and parsley");
FoodItem f4("Chicken soup", 0.350, l, 2.80, lev, Soup, ing4, 90.0, "Heat water. Add the meat and the vegetables and boil the soup.");
FoodItem f5("Soup with vegetables", 0.350, l, 2.50, lev, Soup, ing5, 75.0,"Heat water. Chop the vegetables and add them. Now boil till it is ready");
FoodItem f6("Fish soup", 0.350, l, 3.00, lev, Soup, ing6, 90.0,"Heat water. Clean the fish meat and add to the water. Add some lemon. Boil it.");
FoodItem f7("Chicken steak with potato and vegetables", 0.450, kg, 6.80, lev, ChickenDish, ing7, 30.0, "Roast the steak. Fry the potatoes, and chop tomato and cucumber");
FoodItem f8("Fried chicken wings", 0.400, kg, 5.20, lev, ChickenDish, ing8, 25.0, "Fry some chicken wings");
FoodItem f9("Fried chicken fillets", 0.400, kg, 6.80, lev, ChickenDish, ing9, 25.0, "Fry some chicken fillets");
FoodItem f10("Beef with rice with vegetables", 0.450, kg, 7.20, lev, BeefDish, ing10, 70.0, "Roast rice with vegetables. Add beef meat.");
FoodItem f11("Beef cutlet with roast potatoes", 0.500, kg, 7.80, lev, BeefDish, ing11, 80.0, "Roast beef cutlet with some potatoes and add some tomato and cucumber");
FoodItem f12("Beef burger", 0.400, kg, 4.80, lev, BeefDish, ing12, 3.0, "Everyone knows how to do it.");
FoodItem f13("Fried fish with potatoes and lemon", 0.450, kg, 5.80, lev, FishDish, ing13, 90.0, "Fry a fish. Roast some potatoes and add a lemon");
FoodItem f14("Fish with tomato sauce and lemon", 0.450, kg, 5.50, lev, FishDish, ing14, 80.0, "Roast a fish. Make tomato sauce and add lemon");
FoodItem f15("Fish with rice and vegetables", 0.450, kg, 5.50, lev, FishDish, ing15, 85.0, "Roast fish and rice with vegetables");
FoodItem f16("Vanilla cake", 1.0, piece, 3.50, lev, Dessert, ing16, 60.0, "Make a vanilla cake");
FoodItem f17("Chocolate cake", 1.0, piece, 4.20, lev, Dessert, ing17, 70.0, "Make a chocolate cake");
FoodItem f18("Apple pie",  1.0, piece, 3.80, lev, Dessert, ing18, 80.0, "Make an apple pie.");

DrinkItem d1("Orange juice", 0.400, l, 2.50, lev, Juice, "Cappy", 0.0);
DrinkItem d2("Banana juice", 0.400, l, 2.50, lev, Juice, "Cappy", 0.0);
DrinkItem d3("Pine apple juice", 0.400, l, 2.50, lev, Juice, "Cappy", 0.0);
DrinkItem d10("Lemonade", 0.400, l, 3.20, lev, SoftDrink, "Derby", 0.0);
DrinkItem d8("Coca-cola", 0.450, l, 3.20, lev, FizzyDrink, "CocaCola", 0.0);
DrinkItem d9("Fanta", 0.450, l, 2.80, lev, FizzyDrink, "CocaCola", 0.0);
DrinkItem d7("Sprite", 0.450, l, 2.90, lev, FizzyDrink, "CocaCola", 0.0 );
DrinkItem d4("Beer", 1, bottle, 2.80, lev, Alcohol, "Tuborg", 5.0);
DrinkItem d5("White wine", 1, glass, 3.50, lev, Alcohol, "Chardonnay", 11.0);
DrinkItem d6("Red wine", 1, bottle, 45.0, lev, Alcohol, "French Bordeaux", 14.0);

vector<FoodItem> f;
f.push_back(f1);f.push_back(f2);f.push_back(f3);f.push_back(f4);f.push_back(f5);f.push_back(f6);f.push_back(f7);f.push_back(f8);f.push_back(f9);
f.push_back(f10);f.push_back(f11);f.push_back(f12);f.push_back(f13);f.push_back(f14);f.push_back(f15);f.push_back(f16);f.push_back(f17);f.push_back(f18);

vector<DrinkItem> d;
d.push_back(d1);d.push_back(d2);d.push_back(d3);d.push_back(d4);d.push_back(d5);d.push_back(d6);d.push_back(d7);d.push_back(d8);d.push_back(d9);d.push_back(d10);

///***MENU***///
Menu m(f,d);
//m.printFull();

///***USERS DECLARATION***///
User u1("alex2000", "0123456789");
User u2("alexicus", "2233445566");
User u3("alex_bozhinov", "9876543210");

vector<User> u;
u.push_back(u1); u.push_back(u2); u.push_back(u3);

///***STORAGE DECLARATION***///
pair<Ingredient,double> p1(i1,i1.getQuantity()), p2(i2,i2.getQuantity()), p3(i3,i3.getQuantity()), p4(i4,i4.getQuantity()), p5(i5,i5.getQuantity()), p6(i6,i6.getQuantity()), p7(i7,i7.getQuantity())
, p8(i8,i8.getQuantity()), p9(i9,i9.getQuantity()), p10(i10,i10.getQuantity()), p11(i11,i11.getQuantity()), p12(i12,i12.getQuantity()), p13(i13,i13.getQuantity()), p14(i14,i14.getQuantity()), p15(i15,i15.getQuantity())
, p16(i16,i16.getQuantity()), p17(i17,i17.getQuantity()), p18(i18,i18.getQuantity()), p19(i19,i19.getQuantity()), p20(i20,i20.getQuantity()), p21(i21,i21.getQuantity()), p22(i22,i22.getQuantity()), p23(i23,i23.getQuantity())
, p24(i24,i24.getQuantity()), p25(i25,i25.getQuantity()), p26(i26,i26.getQuantity()), p27(i27,i27.getQuantity()), p28(i28,i28.getQuantity()), p29(i29,i29.getQuantity()), p30(i30,i30.getQuantity()), p31(i31,i31.getQuantity())
, p32(i32,i32.getQuantity()), p33(i33,i33.getQuantity()), p34(i34,i34.getQuantity()), p35(i35,i35.getQuantity()), p36(i36,i36.getQuantity()), p37(i37,i37.getQuantity()), p38(i38,i38.getQuantity()), p39(i39,i39.getQuantity())
, p40(i40,i40.getQuantity()), p41(i41,i41.getQuantity()), p42(i42,i42.getQuantity()), p43(i43,i43.getQuantity());
vector<pair<Ingredient, double> > a;
a.push_back(p1);a.push_back(p2);a.push_back(p3);a.push_back(p4);a.push_back(p5);a.push_back(p6);a.push_back(p7);a.push_back(p8);a.push_back(p9);a.push_back(p10);a.push_back(p11);
a.push_back(p12);a.push_back(p13);a.push_back(p14);a.push_back(p15);a.push_back(p16);a.push_back(p17);a.push_back(p18);a.push_back(p19);a.push_back(p20);a.push_back(p21);a.push_back(p22);
a.push_back(p23);a.push_back(p24);a.push_back(p25);a.push_back(p26);a.push_back(p27);a.push_back(p28);a.push_back(p29);a.push_back(p30);a.push_back(p31);a.push_back(p32);a.push_back(p33);
a.push_back(p34);a.push_back(p35);a.push_back(p36);a.push_back(p37);a.push_back(p38);a.push_back(p39);a.push_back(p40);a.push_back(p41);a.push_back(p42);a.push_back(p43);

Storage storage(a);
//storage.print();


///***TABLES DECLARATION***///
Table t1(1,4,Square), t2(2, 5, Circle), t3(3, 6, Rectangle), t4(4, 4, Square), t5(5, 6, Rectangle), t6(6, 6, Rectangle);
vector<Table> tables; tables.push_back(t1); tables.push_back(t2); tables.push_back(t3); tables.push_back(t4); tables.push_back(t5); tables.push_back(t6);
vector<Table> tables1,tables2; tables1.push_back(t1); tables1.push_back(t2); tables1.push_back(t3); tables2.push_back(t4); tables2.push_back(t5); tables2.push_back(t6);

///***EMPLOYEE DECLARATION***///
Waiter w1("Maria Petrova", "9205181489","maria.petrova","12345",660.0, lev, 8.0, tables1, 80.0);
Waiter w2("Ivan Georgiev", "8908141456","ivan.georgiev","67890",720.0, lev, 8.0, tables2, 90.0);
vector<Waiter> w; w.push_back(w1); w.push_back(w2);

Chef c1("Vladimir Babev", "5610181428", "vladimir.babev", "54321", 1000.0, lev, 8.0, Executive);
Chef c2("Andrey Petkov", "7311291408","andrey.petkov", "09876", 800.0, lev, 8.0, Senior);
Chef c3("Nikoleta Petrova", "8206141429", "nikoleta.petrova", "13579", 780.0, lev, 8.0, Confectioner);
vector<Chef> c; c.push_back(c1); c.push_back(c2); c.push_back(c3);

double salaryOut = w1.getSalary() + w2.getSalary() + c1.getSalary() + c2.getSalary() + c3.getSalary();
double ingredientOut = i1.getPrice() + i2.getPrice() +i3.getPrice() +i4.getPrice() +i5.getPrice() +i6.getPrice() +i7.getPrice() +i8.getPrice() +i9.getPrice() +i10.getPrice() +i11.getPrice() +
i12.getPrice() +i13.getPrice() +i14.getPrice() +i15.getPrice() +i16.getPrice() +i17.getPrice() +i18.getPrice() +i19.getPrice() +i20.getPrice() +i21.getPrice() +i22.getPrice() +i23.getPrice() +
i24.getPrice() +i25.getPrice() +i26.getPrice() +i27.getPrice() +i28.getPrice() +i29.getPrice() +i30.getPrice() +i31.getPrice() +i32.getPrice() +i33.getPrice() +i34.getPrice() +i35.getPrice() +
i36.getPrice() +i37.getPrice() +i38.getPrice() +i39.getPrice() +i40.getPrice() +i41.getPrice() +i42.getPrice() +i43.getPrice();

///***BUDGET DECLARATION***///
Budget b(ingredientOut, salaryOut, 0.0, 0.0, lev);

///***RESTAURANT DECLRATION***///
Restaurant r("ALEX'S RESTAURANT", "Gorna Oryahovitsa", "alex.restaurant@gmail.com", "0878253678", "www.alex-restaurant.bg", storage, m, tables, u, w, c, b);

///***MAIN PROGRAM MENU***///
MainMenu(r);








































/*
i1.printIngredient();
cout<<"-------------------------------------"<<endl;

vector<Ingredient> ing;
ing.push_back(i1);

FoodItem f1("shopska salata", 0.500, kg, 4.50, lev, Salad, ing, 5.00, "get knife and chop the tomatoes");
DrinkItem d1("Orange Juice", 0.400, l, 2.70, lev, Juice, "Cappy", 0.0);

f1.print();
cout<<"-------------------------------------"<<endl;
d1.print();


Menu m;
m.printFull();


Budget b(500.0,2500.0,1500.0,2000.0, lev);
b.print();


vector<FoodItem> f;
f.push_back(f1);
vector<DrinkItem> d;
d.push_back(d1);

Order o(f,d);
o.print();

double q = 200.0;
vector< pair<Ingredient, double> > ava;
ava.push_back({i1,q});
Storage s(ava);
s.print();
*/

}
