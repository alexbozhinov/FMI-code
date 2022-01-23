/**
*
* Solution to homework assignment 2
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

const int START_CHARACTER = 32;
const int LAST_CHARACTER = 126;
const int SIZE = 101;
const int MAX_VALUE_OF_M = 20;

  //function for the length of a string
     int strlen(char arr[]){
        int len = 0;
        while(arr[len] != '\0')
             len ++;
      return len;
     }
  //function which validates if every symbol of the string is between 32 and 126 ASCI
        bool ifIsValid(char str[]){
           int len = strlen(str);
           int counter = 0;
             for(int i=0; i<len; i++){
                 if( str[i] >= START_CHARACTER && str[i] <= LAST_CHARACTER ) counter ++;
                }
           if(counter == len) return true;
           return false;
     }
  //function which encrypts strings
      char* crypt(char str[], int M, int L){
      int len = strlen(str);
      int l, m;
      char result[SIZE];
      bool valid = ifIsValid(str);
        if(valid){
           for(int i=0; i<len; i++){
               result[i] = str[i];
        }

            for(int i=0; i<len; i++){
               if(i + L > len - 1){
                  result[0 + (L - (len - i) )] = str[i];
        }
               else result[i + L] = str[i];

        }
            for(int i=0; i<len; i++){
               if(result[i] <= LAST_CHARACTER - M){
                  result[i] = result[i] + M;
        }
               else result[i] = result[i] - START_CHARACTER + ( M - (LAST_CHARACTER - result[i]) ); //I do the same with M like with L when it reaches 126 it turns back to 32
        }


            for(int i=0; i<len; i++) str[i] = result[i];

            return str;
        }
        else {
                return str;
        }
   }
   int main(){
   int m, l;
   char str[SIZE];

   cout << "Input a string: ";
      cin.getline(str, SIZE);
      cout << endl;
   cout << "Input M which is a number from 0 to 20 and L which is no bigger than the length of the string" << endl;
      cout << endl;
      cout << "Input M: ";
      cin >> m;
   cout << "Input L: ";
      cin >> l;
      cin.ignore();

   while(2){
           if( cin.fail() ){
               cin.clear();
               cin.ignore(numeric_limits<streamsize>::max(),'\n');
                  continue;
               }
                if(strlen(str) > SIZE-1 || m > MAX_VALUE_OF_M || l > strlen(str)){
                     cout<<endl;
                     cout << "You have entered wrong input! Try with a string which has between 0 and 100 symbols, number L no bigger than the length of the string and number N no bigger than 20" << endl;
                     cout<<endl;
                     cout << "Input a string: ";
                         cin.getline(str, SIZE);
                         cout << endl;
                     cout << "Input M which is a number from 0 to 20 and L which is no bigger than the length of the string" << endl;
                         cout << endl;
                     cout << "Input M: ";
                         cin >> m;
                     cout << "Input L: ";
                         cin >> l;
                      cin.ignore();
                         continue;
                  }
               if( !cin.fail() )
                   break;
                 }

   cout << "The encrypted string is: " << crypt(str, m, l) << endl;
   }
