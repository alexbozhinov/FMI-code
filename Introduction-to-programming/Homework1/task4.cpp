/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Aleks Bozhinov
* @idnumber 62457
* @task 4
* @compiler GCC
*
*/
#include<iostream>
#include<limits>
#include<stdlib.h> //this library is because of system("CLS"). Without it the compiler sends me system was not declared in this scope.
using namespace std;
   int main()
   {
    int timer;      //the data type of timer should be unsigned short int but then the validation doesn't work.
   	cout << "Input a number: "  ;
   	cin >> timer;
   	while(4){
           if( cin.fail() ){
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
                continue;
            }
           if( timer < 1 || timer > 65535 ){
              cout << "You have entered wrong input! Try with a number between 1 and 65535." << endl;
              cout << "Input a number: " ;
              cin >> timer;
              continue;
            }
           if( !cin.fail() )
                 break;
   	        }

   	for(int	i = timer; i >= 0; i --){
   		cout << "Timer: " << i;   //The loop starts from timer and goes till 0 and every i-value is printed and then removed with system("CLS").
   		system("CLS");
	   }
	cout << "Timer: " << "0" <<endl;
	return 0;
   }
