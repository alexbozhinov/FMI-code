/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Aleks Bozhinov
* @idnumber 62457
* @task 1
* @compiler GCC
*
*/
#include<iostream>
#include<limits>
using namespace std;

const int SIZE = 101;
const int ALPHABED_SIZE = 26;
const int DIFFERENCE = 16;
const char CHAR_TO_NUMBER = '0';
const char FIRST_LETTER = 'A';
const char LAST_LETTER = 'Z';

//function for the length of a string
   int strlen(char arr[]){
      int len = 0;
         while(arr[len] != '\0')
             len ++;
      return len;
     }

//function which transforms the name of the column to it's number
   int excellTable(char str[]){
      int strLength = strlen(str), result;
      char first, second, third;
         if( strLength == 1 ){
            if(str[0] >= FIRST_LETTER && str[0] <= LAST_LETTER){
               result = str[0] - CHAR_TO_NUMBER - DIFFERENCE;
        }
      }

      else if( strLength == 2 ){
         first = str[0]; second = str[1];
            if(first >= FIRST_LETTER && first <= LAST_LETTER && second >= FIRST_LETTER && second <= LAST_LETTER){
               result = ALPHABED_SIZE * (first - CHAR_TO_NUMBER - DIFFERENCE) + (second - CHAR_TO_NUMBER - DIFFERENCE);
        }
      }

      else if( strLength == 3 ){
         first = str[0]; second = str[1]; third = str[2];
           if(first >= FIRST_LETTER && first <= LAST_LETTER && second >= FIRST_LETTER && second <= LAST_LETTER && third >= FIRST_LETTER && third <= LAST_LETTER){
              result = ALPHABED_SIZE * ALPHABED_SIZE *(first - CHAR_TO_NUMBER - DIFFERENCE) + ALPHABED_SIZE * (second - CHAR_TO_NUMBER - DIFFERENCE) + (third - CHAR_TO_NUMBER - DIFFERENCE);
        }
      }
      return result;
   }

   int main(){
      char str[SIZE];
       cout<<"Input the name of a column in Excel: ";
       cin >> str;
           while(1){
              if( cin.fail() ){
                 cin.clear();
                 cin.ignore(numeric_limits<streamsize>::max(),'\n');
                 continue;
                 }
              if(strlen(str) > 3 || str[0] < FIRST_LETTER || str[0] > LAST_LETTER || str[1] < FIRST_LETTER || str[1] > LAST_LETTER || str[2] < FIRST_LETTER || str[2] > LAST_LETTER){
                 cout << "You have entered wrong input! Try with one to three symbols between A and Z" << endl;
                 cout << "Input the name of a column in Excel: " ;
                      cin >> str;
                      continue;
                 }
             if( !cin.fail() )
                 break;
                 }

       cout <<"The number of column "<<str<<" is: " << excellTable(str) << endl;
   }
