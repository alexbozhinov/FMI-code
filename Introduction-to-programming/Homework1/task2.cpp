/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Aleks Bozhinov
* @idnumber 62457
* @task 2
* @compiler GCC
*
*/
#include<iostream>
#include<limits>
using namespace std;

   int main()
   {
   	int daysCount, leapYearCounter = 0, year = 1;
   	cout << "Days count= " ;
   	cin >> daysCount;

   	    while(2){
           if( cin.fail() ){
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
                continue;
            }
           if( daysCount < 1 || daysCount > 1000000 ){
              cout << "You have entered wrong input! Try with a number between 1 and 1000000." << endl;
              cout << "Input a number: " ;
              cin >> daysCount;
              continue;
            }
           if( !cin.fail() )
                 break;
   	        }
    /*In this loop I search how many the leap years are. There is a leap year on every 4 years. That is why i (which increases till i=daysCount) is divided with 1461 so then we increase our leapYearCounter*/
   	for(int i = 1; i <= daysCount; i ++){
         	if(i % 1461 == 0) leapYearCounter ++;
            }
     /*Then year starts from 1 because the first year is 1. Then from daysCount we take out the leapYearCounter, because every leap year has one day more. So what the number of leap years is, it is
     the same number as the days that are unnecessary. When we do that it becomes like every year has just 365 days(there are no leap years) so we can divide with /365 and sum it with year = 1*/
     year = year + (daysCount - leapYearCounter) / 365;
     /*This verification is necessary because, when we are on the last they of a normal, or of a leap year the operation / 365 returns 1 and year increases and becomes the next year, but the last day is still
     the same year (that is why I use year--). For example if the input is 365 or 1461, without the if operator, the output would have been 2 and 5, but it should be 1 and 4. The mistake comes from the
     line:45: year = year + (daysCount - leapYear)/365; if the input is 365 => year = 1 + (365-0)/365=1+1=2, but it is still the year 1 the other example => year = 1 + (1461-1)/365 = 1+4=5 but the year is still 4
     thats why I have If for this borderline cases and if the operation is true I decrease the year with -1 and then print the answer*/
     if( (daysCount - leapYearCounter ) % 365 == 0 || (daysCount % 1461 == 0) ) year --;
     cout << "The year is: " << year << endl;
   }

