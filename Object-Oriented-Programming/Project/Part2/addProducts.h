#ifndef ADDPRODUCTS_H_INCLUDED
#define ADDPRODUCTS_H_INCLUDED

#include "Products.h"

int const MAX = 100;

class addProduct
{
private:
	Product *arr;
	Product newProduct;

public:

	// създаване на празен стек
	addProduct();
	// Дестуктор
	~addProduct();


	void add(Product &newProduct);


};



#endif // ADDPRODUCTS_H_INCLUDED
