#include<iostream>
#include<math.h>
#include "Point.h"
#include "Rectangle.h"

using namespace std;


Rectangle::Rectangle(){
leftDown = Point(0,0);
rightUp = Point(0,0);
area = 0;
}

Rectangle::Rectangle(Point _leftDown, Point _rightUp){
  this->setLeftDown(_leftDown);
  this->setRightUp(_rightUp);
  this->setArea();
}

Rectangle::Rectangle(const Rectangle& other){
    this->area = other.getArea();
    this->setLeftDown(other.getLeftDown());
    this->setRightUp(other.getRightUp());
}

Rectangle& Rectangle::operator= (const Rectangle& other){

    if(this == &other) return *this;
    area = other.getArea();

    this->setLeftDown(other.getLeftDown());
    this->setRightUp(other.getRightUp());
    return *this;
}

void Rectangle::setLeftDown(Point _leftDown){
  this->leftDown = _leftDown;
}

void Rectangle::setRightUp(Point _rightUp){
   this->rightUp = _rightUp;
}

void Rectangle::setArea(){
   double length = fabs(rightUp.getX() - leftDown.getX());
   double width = fabs(rightUp.getY() - leftDown.getY());
   this->area = length*width;
}

Point Rectangle::getLeftDown()const{
   return this->leftDown;
}

Point Rectangle::getRightUp()const{
   return this->rightUp;
}

double Rectangle::getArea()const{
   return this->area;
}

























