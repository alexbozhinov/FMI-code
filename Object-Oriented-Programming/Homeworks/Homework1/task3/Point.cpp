#include<iostream>
#include "Point.h"

using namespace std;

Point::Point(){
x = 0;
y = 0;
}

Point::Point(double _x, double _y){
   this->setX(_x);
   this->setY(_y);
}

void Point::setX(double _x){
   this->x = _x;
}

void Point::setY(double _y){
   this->y = _y;
}

double Point::getX()const{
   return this->x;
}

double Point::getY()const{
   return this->y;
}

void Point::print() const
{
	cout << '(' << x << ", " << y << ')';
}

Point& Point::operator=(const Point& other){
   if(this==&other){
    return *this;
   }
  this->setX(other.getX());
  this->setY(other.getY());

  return *this;
}
