#include<iostream>
#include "Point.h"
#include "Rectangle.h"
#include "SVG.h"
using namespace std;


int main(){

Rectangle arr[MAX];

arr[0] = Rectangle(Point(2,2),Point(4,4));
arr[1] = Rectangle(Point(3,3),Point(9,9));
arr[2] = Rectangle(Point(4,4),Point(5,5));

SVG S(arr);
S.addRectangles();


///cout<<S.getArrSize()<<endl;
///cout<<S.getRectangles()[3].getArea()<<endl;


cout<<"The index of the rectangle which has the biggest area is: "<<S.findBiggestAreaIndex()<<endl;
return 0;
}
