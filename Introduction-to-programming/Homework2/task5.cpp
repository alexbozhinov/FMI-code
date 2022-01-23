/**
*
* Solution to homework assignment 2
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
using namespace std;

const int SIZE_MATRIX = 100;
const int SIZE_BIG_MATRIX_ROW = 10000;
const int SIZE_BIG_MATRIX_COLUMN = 10;
const int SIZE_ARRAY = 50;
const int ZERO = 0;
const int ONE = 1;
const int TWO = 2;
const int THREE = 3;
const int FOUR = 4;
const int FIVE = 5;
const int SIX = 6;
const int SEVEN = 7;
const int EIGHT = 8;
const int NINE = 9;

 //Input n and n*n matrix:
 int n=6;

 int matrix[SIZE_MATRIX][SIZE_MATRIX]={
     {5,4,3,8,0,6},
     {9,4,5,1,0,8},
     {8,5,8,0,6,1},
     {0,9,6,8,4,2},
     {6,1,0,2,6,1},
     {2,1,8,4,2,6}
     };

 int used[SIZE_ARRAY];
 int permute1[SIZE_ARRAY], permute2[SIZE_ARRAY];

 //function which tries if there is a "good" permutation of the rows of the matrix and prints the changed matrix if possible
 void print( ){
        long long permutationMat[SIZE_BIG_MATRIX_ROW][SIZE_BIG_MATRIX_COLUMN]; // every row of this matrix is a permutation of 0 to n-1
        long long newResult[SIZE_BIG_MATRIX_ROW][SIZE_BIG_MATRIX_COLUMN];  //this is the new matrix where rows are swapped if possible
        int k=-1;
         for(int i=0;i<n;i++){
             for(int j=0;j<n;j++){
               permutationMat[i][j] = permute1[j]-1;
        }
   }


        for(int i=0;i<n;i=i+1){ k++;
            for(int j=0;j<n;j++){
                newResult[k][j] = matrix[permutationMat[i][k]][j];
        }
   }

 int counter = 0;
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           if(n==1){
              cout<<newResult[i][j]<<" ";
            }
           if(n==2){
              if(newResult[ZERO][ZERO]<=newResult[ONE][ONE])
                  {cout<<newResult[i][j]<<" ";counter++;}
           }else
           if(n==3){
              if(newResult[ZERO][ZERO]<=newResult[ONE][ONE]&&newResult[ONE][ONE]<=newResult[TWO][TWO])
                  {cout<<newResult[i][j]<<" ";counter++;}
           }else
            if(n==4){
              if(newResult[ZERO][ZERO]<=newResult[ONE][ONE]&&newResult[ONE][ONE]<=newResult[TWO][TWO]&&newResult[TWO][TWO]<=newResult[THREE][THREE])
                  {cout<<newResult[i][j]<<" ";counter++;}
           }else
            if(n==5){
              if(newResult[ZERO][ZERO]<=newResult[ONE][ONE]&&newResult[ONE][ONE]<=newResult[TWO][TWO]&&newResult[TWO][TWO]<=newResult[THREE][THREE]&&newResult[THREE][THREE]<=newResult[FOUR][FOUR])
                  {cout<<newResult[i][j]<<" ";counter++;}
           }else
            if(n==6){
               if(newResult[ZERO][ZERO]<=newResult[ONE][ONE]&&newResult[ONE][ONE]<=newResult[TWO][TWO]&&newResult[TWO][TWO]<=newResult[THREE][THREE]&&newResult[THREE][THREE]<=newResult[FOUR][FOUR]&&newResult[FOUR][FOUR]<=newResult[FIVE][FIVE])
                  {cout<<newResult[i][j]<<" ";counter++;}
           }else
            if(n==7){
              if(newResult[ZERO][ZERO]<=newResult[ONE][ONE]&&newResult[ONE][ONE]<=newResult[TWO][TWO]&&newResult[TWO][TWO]<=newResult[THREE][THREE]&&newResult[THREE][THREE]<=newResult[FOUR][FOUR]&&newResult[FOUR][FOUR]<=newResult[FIVE][FIVE]&&newResult[FIVE][FIVE]<=newResult[SIX][SIX])
                  {cout<<newResult[i][j]<<" ";counter++;}
           }else
            if(n==8){
              if(newResult[ZERO][ZERO]<=newResult[ONE][ONE]&&newResult[ONE][ONE]<=newResult[TWO][TWO]&&newResult[TWO][TWO]<=newResult[THREE][THREE]&&newResult[THREE][THREE]<=newResult[FOUR][FOUR]&&newResult[FOUR][FOUR]<=newResult[FIVE][FIVE]&&newResult[FIVE][FIVE]<=newResult[SIX][SIX]&&newResult[SIX][SIX]<=newResult[SEVEN][SEVEN])
                  {cout<<newResult[i][j]<<" "; counter++;}
           }else
            if(n==9){
              if(newResult[ZERO][ZERO]<=newResult[ONE][ONE]&&newResult[ONE][ONE]<=newResult[TWO][TWO]&&newResult[TWO][TWO]<=newResult[THREE][THREE]&&newResult[THREE][THREE]<=newResult[FOUR][FOUR]&&newResult[FOUR][FOUR]<=newResult[FIVE][FIVE]&&newResult[FIVE][FIVE]<=newResult[SIX][SIX]&&newResult[SIX][SIX]<=newResult[SEVEN][SEVEN]&&newResult[SEVEN][SEVEN]<=newResult[EIGHT][EIGHT])
                  {cout<<newResult[i][j]<<" "; counter++;}
           }else
            if(n==10){
               if(newResult[ZERO][ZERO]<=newResult[ONE][ONE]&&newResult[ONE][ONE]<=newResult[TWO][TWO]&&newResult[TWO][TWO]<=newResult[THREE][THREE]&&newResult[THREE][THREE]<=newResult[FOUR][FOUR]&&newResult[FOUR][FOUR]<=newResult[FIVE][FIVE]&&newResult[FIVE][FIVE]<=newResult[SIX][SIX]&&newResult[SIX][SIX]<=newResult[SEVEN][SEVEN]&&newResult[SEVEN][SEVEN]<=newResult[EIGHT][EIGHT]&&newResult[EIGHT][EIGHT]<=newResult[NINE][NINE])
                  {cout<<newResult[i][j]<<" "; counter++;}
        }

        else cout<<"You have inputted a forbidden value for n! Try with a number between 1 and 10!"<<endl;
    }
    if(counter>0) {cout<<endl;}
   }
 }


 //recursive function to generate all permutations from 0 to n-1
 void permute(int i)
 {
    int k;
    if(i>=n) print();
    for(k=0;k<n;k++){
        if(!used[k]){
            used[k] = 1; permute1[i]=permute2[k]; permute(i+1);used[k]=0;
        }
    }
 }

 int main(){
   int i;
        for(i=0;i<n;i++) permute2[i] = i+1;
        for(i=0;i<n;i++) used[i] = 0;
               cout<<"The result is: "<<endl;
               permute(0);
               cout<<endl;
               cout<<endl;
        cout<<"P.S.:If you don't see any matrix in the console as a result, this means that there are no rows that can be swapped that the main diagonal becomes a growing row!"<<endl;
 }

