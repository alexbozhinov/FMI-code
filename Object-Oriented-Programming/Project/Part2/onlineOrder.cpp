#include "onlineOrder.h"
#include "User.h"
#include "Products.h"
#include <iostream>

/**in progress, not working yet**/
using namespace std;

onlineOrder::onlineOrder()
{
	Size = MAX_LENGTH;
	listProducts = new Product[Size];
	top = -1;
}

void onlineOrder::grow()
{
	Product *newProd = new Product[2 * Size];
	for (int i = 0; i < Size; i++)
		newProd[i] = listProducts[i];
	delete[] listProducts;
	listProducts = newProd;
	Size *= 2;
}

onlineOrder::~onlineOrder()
{
	delete[] listProducts;
}

bool onlineOrder::ifEmpty() const
{
	return top == -1;
}

Product onlineOrder::peek() const
{

	return listProducts[top];
}

void onlineOrder::push(Product prod) {
	if (full()) {
		grow();
	}
	listProducts[++top] = prod;
}

bool onlineOrder::full() const {
	return top == Size - 1;
}

Product onlineOrder::pop() {
	if (ifEmpty()) {
		cout << "Mistake\n";
	}
	return listProducts[top--];
}
