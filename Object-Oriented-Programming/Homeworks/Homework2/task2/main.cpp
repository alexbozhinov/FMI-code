#include "intCounter.h"
#include "intCounter.cpp"
#include<iostream>

using namespace std;

int main(){

unsigned int* some_number = new unsigned int(1);
IntCounter<unsigned int> first(some_number);
std::cout << first.get_count() << std::endl;
IntCounter<unsigned int> second = first;
std::cout << first.get_count() << std::endl;
{
	IntCounter<unsigned int> third(second);
	std::cout << first.get_count() << std::endl;
}
std::cout << first.get_count() << std::endl;

}
