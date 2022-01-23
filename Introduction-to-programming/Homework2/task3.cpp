/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Aleks Bozhinov
* @idnumber 62457
* @task 3
* @compiler GCC
*
*/
#include<iostream>
using namespace std;

const int SIZE = 1000;
   //function which returns the length of an array
    int strlen(char arr[]){
       int len = 0;
         while(arr[len] != '\0')
              len ++;
         return len;
     }

     // function given two strings returns the smaller
    int smallerStringLen(char str1[], char str2[]){

       int smaller, len1 = strlen(str1), len2 = strlen(str2);
           smaller = len1;
           if(smaller>len2) smaller = len2;
             else smaller = len1;

       return smaller;
    }

     // function given two strings returns the bigger
    int biggerStringLen(char str1[], char str2[]){

      int bigger, len1 = strlen(str1), len2 = strlen(str2);
          bigger = len1;
          if(bigger<len2) bigger = len2;
             else bigger = len1;

      return bigger;
    }

    // function which compares the two given strings and replaces the bigger one with a few repetitions of the smaller one
    char* stringCompare(char str1[], char str2[]){

       int bigger = biggerStringLen(str1, str2), smaller = smallerStringLen(str1, str2) ;
       char result[bigger + 1], smallerArray[smaller + 1];
       int len1 = strlen(str1), len2= strlen(str2);

       if(len1 > len2) {
          for(int i=0; i < len2; i++) smallerArray[i] = str2[i];
       }
       else {
          for(int i=0; i < len1; i++) smallerArray[i] = str1[i];
       }

       for(int i=0; i < smaller; i++){
           for(int j=0;j < bigger;j = j + smaller){
             result[i + j] = smallerArray[i];
          }
       }
       if(len1 > len2) {
          for(int i=0; i<bigger; i++)
              str1[i] = result[i];
          return str1;}
       else {
          for(int i=0; i<bigger; i++)
              str2[i] = result[i];
          return str2;
       }
   }

   int main(){
     //Input two strings with different lengths and at least one symbol inside them:

     char str1[SIZE] = "we", str2[SIZE] = "We are the champions!";

     int len1 = strlen(str1), len2 = strlen(str2);
       if(len1 == len2) cout << "Wrong input! The two strings should have different length." << endl;
          else if(len1 == 0 || len2 == 0) cout<<"Wrong input! Each of the two strings should have at least one symbol."<<endl;
                  else cout << "The bigger string is transformed to: " << stringCompare(str1, str2) << endl;
     }
