#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED

#include<iostream>
#include "Point.h"
#include "Rectangle.h"

using namespace std;


class SVG{

public:

    SVG();
    SVG(Rectangle* );
    ~SVG();
    SVG(const SVG& );
    SVG& operator=(const SVG& );

    void addRectangles();

    int findBiggestAreaIndex();

    void setRectangles(Rectangle* );
    void setArrSize(Rectangle* );

    Rectangle* getRectangles()const;
    int getArrSize()const;
    ///bool full()const;

private:

    Rectangle* rectangles;
    int arrSize;
};


#endif // SVG_H_INCLUDED
