/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Aleks Bozhinov
* @idnumber 62457
* @task 6
* @compiler GCC
*
*/
#include<iostream>
#include<math.h>
#include<limits>
using namespace std;
   int main()
   {
   	double x, y, radius ;
   	cout<<"Input the coordinates x and y of a point:"<<endl;
   	cout<<endl;
   	cout << "x= " ;
   	cin >> x;
   	cout << "y= " ;
   	cin >> y;
   	while(6){
       if( cin.fail() ){
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(),'\n');
         cout << "You have entered wrong input, try with new values for x and y" << endl;
         cout << "x= ";
         cin >> x;
         cout << "y= ";
         cin >> y;
        }
          if( !cin.fail() )
                 break;
              }
    radius = sqrt( (x*x) + (y*y) ); //I use the Pythagorean theorem to find the distance from the point with coordinates (x;y) and the center of the coordinate system.
    /*four if checks for the four cases*/
    if(((x > -1 && x <= 1) && (y > -1 && y < 1 ))||(x >= 2 && x <= 3 && radius > 2 && radius < 3) || (x >= -3 && x <= -2 && radius > 2 && radius < 3) || (y >= 2 && y <= 3 && radius > 2 && radius < 3) || (y >= -3 && y <= -2 && radius > 2 && radius < 3))
        cout<<"Answer: Black"<<endl;
    else if(((x == 1 || x == -1) && (y >= -1 && y <= 1)) || ((y == 1 || y == -1) && (x >= -1 && x <= 1)) || (radius == 2) || (radius == 3))
       cout<<"Answer: Undefined"<<endl;
    else if((x >= 1 && x <= 2 && radius < 2) || (x >= -2 && x <= -1 && radius < 2) || (y >= 1 && y <= 2 && radius <2 ) || (y >= -2 && y <= -1 && radius < 2))
       cout<<"Answer: White"<<endl;
    else if(radius > 3) cout<<"Answer: Outside"<<endl;
   }
