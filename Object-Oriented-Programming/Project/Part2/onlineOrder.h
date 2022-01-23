#ifndef ONLINEORDER_H_INCLUDED
#define ONLINEORDER_H_INCLUDED
#include "Products.h"
/**now in progress, not working yet**/

class onlineOrder
{
private:
	Product *listProducts;
	int top;
	int Size;

	bool full() const;

	void grow();

public:

	onlineOrder();
	~onlineOrder();


	bool ifEmpty() const;

	Product peek() const;

	void push(Product);

	Product pop();

};

#endif // ONLINEORDER_H_INCLUDED
