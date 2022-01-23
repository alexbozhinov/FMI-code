#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include<iostream>
#include "Point.h"

using namespace std;



class Rectangle{

public:

    Rectangle();
    Rectangle(Point, Point);
    Rectangle(const Rectangle& );
    Rectangle& operator=(const Rectangle& );

    void setArea();
    void setLeftDown(Point );
    void setRightUp(Point );

    Point getLeftDown()const;
    Point getRightUp()const;
    double getArea()const;

private:

    Point leftDown;
    Point rightUp;
    double area;
};




/*
class Rectangle{

public:
    Rectangle();
    Rectangle(double, double, double, double);

    void setX1(double );
    void setX2(double );
    void setY1(double );
    void setY2(double );
    void setArea();

    double getX1()const;
    double getX2()const;
    double getY1()const;
    double getY2()const;
    double getArea()const;

    double recArea();

private:
    double x1;
    double y1;
    double x2;
    double y2;
    double area;
};

*/

#endif // RECTANGLE_H_INCLUDED
