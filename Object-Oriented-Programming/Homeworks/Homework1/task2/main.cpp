#include<iostream>
#include "IntCounter.h"
using namespace std;


int main(){

/**examples from the condition of the task**/
int* some_number = new int(5);
IntCounter first(some_number);
cout << first.getCount() << endl;
IntCounter second = first;

cout << first.getCount() << endl;

{
	IntCounter third(second);
	cout << first.getCount() << endl;
}
cout << first.getCount() << endl;


/**
int* some_number = new int(5);
IntCounter first(some_number);
cout << first.getCount() << endl;

int* some_other_number = new int(7);
IntCounter second(some_other_number);
cout << second.getCount() << endl;
*/

/**
int* some_number = NULL;
IntCounter first(some_number);
cout << first.getCount() << endl;
IntCounter second = first;
cout << first.getCount() << endl;
*/
}
