/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Aleks Bozhinov
* @idnumber 62457
* @task 5
* @compiler GCC
*
*/
#include<iostream>
#include<math.h>
#include<limits>
using namespace std;
   int main()
   {
   	short realRootCounter = 0 ;
   	double a, b, c, Discriminant, t1, t2, x1, x2, x3, x4 ;
   	cout<<"Input the factors a,b and c of a bicuadratic equation:"<<endl;
   	cout<<endl;
   	cout << "a= ";
   	cin >> a;
   	cout << "b= ";
   	cin >> b;
   	cout << "c= ";
   	cin >> c;
   	 while(5){
       if( cin.fail() ){
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(),'\n');
         cout << "You have entered wrong input! Try with another numbers." << endl;
         cout << "a= " ;
         cin >> a;
         cout << "b= " ;
         cin >> b;
         cout << "c= " ;
         cin >> c;
        }
          if( !cin.fail() )
                 break;
              }
   	/* If a is 0 the equation becomes quadratic of type b*x^2+c=0 and then x^2 = -c/b so c must be negative or 0 in the input so when it is settled on the right side of the equation
   	it becomes positive or 0 and we can search the two roots X12 =  sqrt(c/b) where c/b >=0 */
   	if(a==0 && b==0 && c==0){
        cout<<"Every real number is a root of the biquadratic equation"<<endl;
   	}
   	else if(a!=0 && b==0 && c==0){
        cout<<"The biquadratic equation has only one root - x= 0"<<endl;
   	}
   	else if(a!=0 && b==0 &&c!=0){
        if(c<0){
            x1 = sqrt( sqrt(((-1) * c) / a));
            x2 = (-1) * sqrt( sqrt(((-1) * c) / a));
            cout<<"The biquadratic equation has two doubled roots: x1= "<<x1<<" and x2= "<<x2<<endl;
               }
   	}
   	else if(a==0 && b==0 && c!=0){
        cout<<"The biquadratic equation does not have roots"<<endl;
   	}
   	else if(a==0 && b!=0 && c==0){
        cout<<"The biquadratic equation has only one root - x= 0"<<endl;
   	}
   	else if(a == 0 && b!=0 && c!=0){
   		if(c < 0) {
		   x1 = sqrt(((-1) * (c)) / b);
		   x2 = (-1)*(sqrt(((-1) * (c)) / b));
		   cout << "The equation becomes quadratic with the real roots: " << "x1= " << x1 << " " << "x2= "<< x2 << endl;
	            }
	            else cout << "The biquadratic equation does not have real roots" << endl;
	        }
    /*When a is different from 0 we can search the Discriminant of the equation. Imagine we have t=x^2 and the equation becomes quadratic: a*t^2+b*t+c=0.
    So because t=x^2 t should be a positive number or 0. With the Discriminant we search the two roots of the new quadratic equation. They are two different and if the Discriminant = 0
    they are equal. Then we make checks if t1 and t2 (the two roots) are >=0. Or if just one of them or none of them is >=0; If both are >=0 we have 4 real roots of the biquaratic equation
    x1,x2,x3,x4. We search them with that expression x1,3=sqrt(t1 or t2) and x2,4=-1*sqrt(t1 or t2). If just the one t is positive or 0 we have just two real roots an if both are <0 there are no
    real roots. I use the realRootCounter to count the number of real roots an use it in the cout section. */
	 else if ((a != 0 && b!=0 && c!=0) || (a!=0 && b!=0 && c==0)){
	 	Discriminant = (b*b) - (4*a*c);
		    t1 = ((-1) * b + sqrt(Discriminant)) / (2*a);
		     t2 = ((-1) * b - sqrt(Discriminant)) / (2*a);
		       if (t1 > 0) {
		                 x1 = sqrt(t1);
		                 x2 = (-1) * sqrt(t1); realRootCounter = realRootCounter + 2;
	                    }
	                 else realRootCounter = 0;
		 	   if(t2 > 0){
		 	   	         x3 = sqrt(t2);
		 	   	         x4 = (-1) * sqrt(t2); realRootCounter = realRootCounter + 2;
				       }
				     else realRootCounter = 0;
		  if(realRootCounter == 0){
		  	          cout << "The biquadratic equation does not have real roots" << endl;
		           }
		  else if(realRootCounter == 2) {
		            cout << "The biquadratic equation has only two real roots"<<endl;
		             if( t1>0 )    cout << "x1= " << x1 <<" "<< "x2= " << x2 << endl;
					 if( t2>0 )    cout << "x1= " << x3 <<" "<< "x2= " << x4 << endl;
                    cout<<"and two unreal roots"<<endl;
	                     }
	       else if(realRootCounter == 4) {
		                  cout << "The biquadratic equation has four real roots" << endl;
		                  cout << "x1= " << x1 << " " << "x2= " << x2 << " " << "x3= " << x3 << " " << "x4= " << x4 << endl;
					      }
	               }
    return 0;
   }
