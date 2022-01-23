#include<iostream>
#include "Point.h"
#include "Rectangle.h"
#include "SVG.h"

using namespace std;

SVG::SVG(){
   arrSize = 0;
   rectangles = new Rectangle[0];
}

SVG::SVG(Rectangle* _rectangles){
   this->setArrSize(_rectangles);
   this->setRectangles(_rectangles);
}

void SVG::setRectangles(Rectangle* _rectangles){
   if (_rectangles){
        int n = 0;
        while (_rectangles[n].getLeftDown().getX()!=0 && _rectangles[n].getLeftDown().getY() !=0 && _rectangles[n].getRightUp().getX() !=0 && _rectangles[n].getRightUp().getY() !=0 ) {
            n++;
        }
        this -> rectangles = new Rectangle[n];
        this->rectangles = _rectangles;

    } else{
           this -> rectangles = new Rectangle[0];
    }

}

void SVG::setArrSize(Rectangle* _rectangles){
   if (_rectangles){
        int n = 0;
        while (_rectangles[n].getLeftDown().getX()!=0 && _rectangles[n].getLeftDown().getY() !=0 && _rectangles[n].getRightUp().getX() !=0 && _rectangles[n].getRightUp().getY() !=0 ) {
            n++;
        }
        this->arrSize = n;
    } else{
        this->arrSize = 0;
    }
}

SVG::~SVG(){
   delete[] rectangles;
}

int SVG::getArrSize()const{
   return this->arrSize;
}

Rectangle* SVG::getRectangles()const{
   return this->rectangles;
}

SVG::SVG(const SVG& other){
    this->arrSize = other.getArrSize();
    this->rectangles = new Rectangle[arrSize];
    this->setRectangles(other.getRectangles());
    this->setArrSize(other.getRectangles());
}

SVG& SVG::operator= (const SVG& other){

    if(this == &other) return *this;

    delete[] rectangles;
    arrSize = other.getArrSize();
    rectangles = new Rectangle[arrSize];

    this->setRectangles(other.getRectangles());
    this->setArrSize(other.getRectangles());
    return *this;
}
/**
bool SVG::full() const {
	return arrSize == MAX - 1;
}
**/
void SVG::addRectangles(){
   cout<<"How many rectangles would you like to add?: ";
   int howMany;
   cin>>howMany;
   	while(true)
	{
       if(arrSize + howMany>MAX){   cout<<"Error: You are exceeding the capacity of the array! Try again: ";cin>>howMany; continue;}
		else
		{
			break;
		}
	}
   double x1,x2,y1,y2;
   for(int i=0; i<howMany; i++){
      cout<<"Input coordinates for the left down corner point of the rectangle: "<<endl;
      cout<<"Input x1: ";
      cin>>x1;
      cout<<"Input y1: ";
      cin>>y1;
      cout<<"Input coordinates for the right up corner point of the rectangle: "<<endl;
      cout<<"Input x2: ";
      cin>>x2;
      cout<<"Input y2: ";
      cin>>y2;
      rectangles[arrSize].setLeftDown(Point(x1,y1));
      rectangles[arrSize].setRightUp(Point(x2,y2));
      rectangles[arrSize].setArea();
      arrSize = arrSize+1;
      cout<<"You successfully added "<<arrSize<<"th rectangle into the array"<<endl;
   }
}

int SVG::findBiggestAreaIndex(){
   int maxIdx = 0;
   Rectangle maximalArea = getRectangles()[0];
   for(int i=0;i<getArrSize();i++){
        if(getRectangles()[i].getArea()>maximalArea.getArea()){
            maxIdx = i;
            maximalArea = getRectangles()[i];
        }
   }
   return maxIdx;
}






