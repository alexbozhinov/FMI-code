#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include<iostream>
using namespace std;

const int MAX = 100;

class Point{

public:

	Point();
	Point(double, double);

	double getX() const;
	double getY() const;

	void print() const;

	void setX(double );

	void setY(double );

    Point& operator=(const Point& other);

private:

	double x;
	double y;
};



#endif // POINT_H_INCLUDED
