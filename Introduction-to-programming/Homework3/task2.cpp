/**
*
* Solution to homework assignment 3
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
 #include<math.h>
 #include<limits>
 using namespace std;
 const int BAD_RETURN = 10;
 const int MAX = 100;
 const int SIZE = 500;
 const int RESULT_SIZE = 10000;
 const int TRANSFORM_TO_DIGITS = 10;
 const int LAST_DIGIT = 9;
 int strlen(char arr[]){
        int len = 0;
        while(arr[len] != '\0')
                  len ++;
      return len;
}


 int CharToInt(char ch){
   return ((ch >= '0' && ch <= '9')? ch - '0': BAD_RETURN);
 }

 //print +
 void printPlus(int result[], int len1, int len2, bool neg){
    if( neg == true ) cout<<"The result is: -";
       else cout<<"The result is: ";
    if(len1>len2) { for(int i=0; i<len1; i++) cout << result[i];}
       else if(len1<len2) { for(int i=0; i<len2; i++) cout << result[i];}
            else {
                  if(result[0] != 0){ for(int i=0; i<len2+1; i++) cout << result[i];}
                      else{
                            for(int i=1; i<=len2; i++) cout << result[i];
                          }

                 }
  }

 //print -
 void printMinus (int result[], int len1, int len2, bool negative, bool zero){

      if(len1 > len2) {
            cout << "The result is: "; if(result[len1-1] == 0) {
                        for(int i=len1 -2; i>=0; i--) cout << result[i];
                               } else {
                                        for(int i=len1-1; i>=0; i--) cout << result[i];
                                      }
                      }
     else if(len2 > len1) {
            cout << "The result is: -"; if(result[len2-1] == 0) {
                        for(int i = len2 -2; i >= 0; i--) cout << result[i];
                                      }else {
                                               for(int i = len2-1; i>=0; i--) cout << result[i];
                                            }
                        }
     else {
             if(zero == true) cout << "The result is: 0" << endl;
                 else{
                       if(negative == true){
                            cout << "The result is: -"; if(result[len2-1]==0) {
                                          for(int i=len2-2; i>=0; i--) cout << result[i];
                        } else {
                                  for(int i = len2-1; i>=0; i--) cout << result[i];
                               }
                        }
                        else {
                               cout << "The result is: "; if(result[len1-1] == 0) {
                                     for(int i=len2-2; i>=0; i--) cout << result[i];
                             } else {
                                     for(int i=len2-1; i>=0; i--) cout << result[i];
                                    }
                             }
                     }
         }
    }

 //print *
 void printMultiply( int result[], int len1, int len2, bool neg1, bool neg2){
      if(neg1 != neg2) cout << "The result is: -";
         else   cout << "The result is: ";
      if(result[len1 + len2 - 1] == 0) {
              for(int i=len1 + len2 - 2; i>=0; i--) cout << result[i];
            }else {
                   for(int i=len1 + len2 - 1; i>=0; i--) cout << result[i];
                  }
 }

 //+
 void copyCharArrToIntArrPlus(char str1[], char str2[], int number1[], int number2[], bool ifNeg){
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  int newNum[SIZE] = {0};
  int result[RESULT_SIZE] = {0};
  bool neg = ifNeg;

  if(str1[0] == '-') {
           for(int i=1;i<=len1;i++) number1[i-1] = CharToInt(str1[i]);  len1--;
     }else {
           for(int i=0;i<len1;i++) number1[i] = CharToInt(str1[i]);
           }
  if(str2[0] == '-') {
           for(int i=1;i<=len2;i++) number2[i-1] = CharToInt(str2[i]); len2--;
     }else {
           for(int i=0;i<len2;i++) number2[i] = CharToInt(str2[i]);
           }

 int diff = fabs(len2 - len1);

 if(len1 < len2){
     for(int i=0;i<len1;i++){
          newNum[i + diff] = newNum[i + diff] + number1[i];
    }

    for(int i = len2-1;i>=0; i--){
        if((newNum[i]+number2[i])>LAST_DIGIT) {
                  result[i] = (newNum[i]+number2[i])%TRANSFORM_TO_DIGITS; number2[i-1]++;
        }
        else result[i] = newNum[i] + number2[i];
    }
 }

 else if(len1 > len2){
      for(int i=0; i<len2; i++){
          newNum[i + diff] = newNum[i + diff] + number2[i];
    }

    for(int i = len1 - 1; i>=0; i--){
        if((newNum[i] + number1[i]) > LAST_DIGIT) {
                 result[i] = (newNum[i] + number1[i])%TRANSFORM_TO_DIGITS; number1[i-1]++;
        }
        else result[i] = newNum[i] + number1[i];
     }
 }

 else{
   for(int i = len2 -1;i>= 0; i--){
           if((number1[i]+number2[i])>LAST_DIGIT) {
                result[i+1] = (number1[i] + number2[i]) % TRANSFORM_TO_DIGITS; number1[i - 1]++; if(i == 0) result[0]++;
           }
           else result[i+1] = number1[i] + number2[i];
       }
   }
  printPlus(result, len1, len2, neg);

 }

 //-
 void copyCharArrToIntArrMinus(char str1[], char str2[], int number1[], int number2[]){
   int len1 = strlen(str1);
   int len2 = strlen(str2);
   int newNum[SIZE] = {0};
   int result[RESULT_SIZE] = {0};
   int k = 0;
   bool negative, zero = false;
   int counter = 0;
   int negCount = 0;

  if(str1[0] == '-') {
        for(int i=1;i<=len1;i++) number1[i-1] = CharToInt(str1[i]);  len1--;
  }else {
          for(int i=0;i<len1;i++) number1[i] = CharToInt(str1[i]);
        }
  if(str2[0] == '-') {
        for(int i=1;i<=len2;i++) number2[i-1] = CharToInt(str2[i]); len2--;
  }else {
          for(int i=0;i<len2;i++) number2[i] = CharToInt(str2[i]);
        }
  int diff = fabs(len2 - len1);

  if(len1 > len2){
    for(int i = 0; i < len2; i++) {
        newNum[i+diff] = newNum[i+diff] + number2[i];
    }

    for(int i = len1-1;i>=0;i--) {
             if((number1[i] - newNum[i])<0) {
                  result[k] = (number1[i]+TRANSFORM_TO_DIGITS) - newNum[i]; number1[i-1] --;
    }else{
           result[k] = number1[i] - newNum[i];
         }
        k++;
      }
  }
  else if(len2 > len1){
    for(int i=0; i < len1; i++){
        newNum[i+diff] = newNum[i+diff] + number1[i];
    }

      for(int i = len2 - 1; i>=0 ; i--){
          if((number2[i] - newNum[i]) < 0) {
                result[k] = (number2[i] + TRANSFORM_TO_DIGITS) - newNum[i]; number2[i-1] --;
          }else {
               result[k] = number2[i] - newNum[i];
                }
          k++;
       }
   }else {
          for(int i = 0;i<len2;i++){
             if(number1[i] == number2[i]) {counter ++;}
        }

        if(counter == len2) zero = true;
        for(int i = 0; i<len2;i++){
            if((number1[i] - number2[i])<0) negCount++;
        }

        if(negCount>0) negative = true;
           else negative = false;

        for(int i = len2 - 1; i>=0; i--){
           if(negative == false){ if((number1[i] - number2[i])<0) {
                 result[k] = (number1[i] + TRANSFORM_TO_DIGITS) - number2[i]; number1[i-1]--;
           }else {
                  result[k] = number1[i] - number2[i];
                 }
        }
           else if(negative == true) {
                if((number2[i] - number1[i])<0) {result[k] = (number2[i] + TRANSFORM_TO_DIGITS) - number1[i]; number2[i-1]--;
           }else {
               result[k] = number2[i] - number1[i];
                }
            }
          k++;
        }
     }
    printMinus(result, len1, len2, negative, zero);
 }

 //*
 void copyCharArrToIntArrMultiply(char str1[], char str2[], int number1[], int number2[]){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int result[RESULT_SIZE] = {0};
    int newNum1[SIZE];
    int newNum2[SIZE];
    bool firstNeg = false;
    bool secondNeg = false;
    if(str1[0] == '-') {
            for(int i=1;i<=len1;i++) number1[i-1] = CharToInt(str1[i]); firstNeg = true; len1--;
    }else {
            for(int i=0;i<len1;i++) number1[i] = CharToInt(str1[i]); firstNeg = false;
          }
    if(str2[0] == '-') {
            for(int i=1;i<=len2;i++) number2[i-1] = CharToInt(str2[i]); secondNeg = true; len2--;
    }else {
            for(int i=0;i<len2;i++) number2[i] = CharToInt(str2[i]); secondNeg = false;
          }

   for(int i=0;i<len1;i++) newNum1[i] = number1[len1-1-i];
   for(int i=0;i<len2;i++) newNum2[i] = number2[len2-1-i];
   //The next five rows I copied from Internet(Could be similar to someone else's code!
   for(int i=0;i<len1;i++){
       for(int j=0;j<len2;j++){
           result[i+j] += newNum1[i] * newNum2[j];
           result[i+j+1] = result[i+j+1] + result[i+j] / TRANSFORM_TO_DIGITS;
           result[i+j]%=TRANSFORM_TO_DIGITS;
      }
    }
   printMultiply(result, len1, len2, firstNeg, secondNeg);
 }



 //main
 int main(){
   int number1[SIZE];
   int number2[SIZE];
   char str1[SIZE];
   char str2[SIZE];
   char symbol;
   bool ifNeg = false;





   cout<<"Input an arithmetic symbol +, -, or *: ";
   cin>>symbol;

   while(1){
              if( cin.fail() ){
                 cin.clear();
                 cin.ignore(numeric_limits<streamsize>::max(),'\n');
                 continue;
                 }
   if(symbol!='+'&&symbol!='-'&&symbol!='*'){cout<<"Your input is incorrect! Try with +, - or * :"; cin>>symbol; continue;}
   if( !cin.fail() )
                 break;
                 }
   cin.ignore();

   cout<<"Input first number: ";
   cin.getline(str1, SIZE);
   cout<<"Input second number: ";
   cin.getline(str2,SIZE);

  if(symbol=='+'){
      if(str1[0]== '-' && str2[0] != '-') copyCharArrToIntArrMinus(str2, str1, number2, number1);
      else if(str1[0]!='-' && str2[0] == '-') copyCharArrToIntArrMinus(str1, str2, number1, number2);
      else if(str1[0]=='-' && str2[0]=='-') {ifNeg = true; copyCharArrToIntArrPlus(str1, str2, number1, number2, ifNeg); }
      else if(str1[0]!='-' && str2[0]!='-')  copyCharArrToIntArrPlus(str1, str2, number1, number2, ifNeg);
   }

  else if(symbol=='-') {
     if(str1[0]!='-' && str2[0]=='-') copyCharArrToIntArrPlus(str1, str2, number1, number2, ifNeg);
     else if(str1[0] =='-' &&  str2[0]=='-') copyCharArrToIntArrMinus(str2, str1, number2, number1);
     else if(str1[0]!='-' && str2[0]!='-') copyCharArrToIntArrMinus(str1, str2, number1, number2);
     else if(str1[0]=='-' && str2[0]!='-') {ifNeg = true; copyCharArrToIntArrPlus(str1, str2, number1, number2, ifNeg);}
  }

  else if(symbol=='*') copyCharArrToIntArrMultiply(str1, str2, number1, number2);

 }
