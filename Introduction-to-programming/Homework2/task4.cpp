/**
*
* Solution to homework assignment 2
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
using namespace std;

const int FIRST_BIG_LETTER = 65;
const int LAST_BIG_LETTER = 90;
const int FIRST_SMALL_LETTER = 97;
const int LAST_SMALL_LETTER = 122;
const int EXTRA_SYMBOL1 = 45;
const int EXTRA_SYMBOL2 = 95;
const int SIZE = 1000;

     //function that returns the length of a string
     int strlen(char arr[]){
         int len = 0;
             while(arr[len] != '\0')
                len ++;
      return len;
     }

     //function given string returns the number of shortest valid words
    int numberOfShortestWOrds(char str[]){
        int i = 0, counter1 = 0, counter2 = 0, strLenght = strlen(str);
        int counter[strLenght] = {0};
        int j = 0;

         while(strLenght - i > 0){
            if((str[i] >= FIRST_BIG_LETTER && str[i] <= LAST_BIG_LETTER) || (str[i] >= FIRST_SMALL_LETTER && str[i] <= LAST_SMALL_LETTER) || (str[i] == EXTRA_SYMBOL1) || (str[i] == EXTRA_SYMBOL2)){
            counter[j]++;
            i++;}
            else {j++; i++; }
         }

         int minimal = counter[0];

         for(i=0; i < strLenght; i++){
            if(minimal > counter[i] && counter[i] != 0) minimal = counter[i];
         }

         for(i=0; i < strLenght; i++){
            if (minimal == counter[i]) counter1++;
         }

     return counter1;
    }

    int main(){
    //Input a string:

    char str[SIZE] = "The best students are from FMI";

    int len = strlen(str);
    if(len == 0) cout << "There are no words in the string." << endl;
    else cout << "The shortest word of the string occurs " << numberOfShortestWOrds(str) << " times." << endl;
    }
