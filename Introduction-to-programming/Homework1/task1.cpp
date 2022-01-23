/**
*
* Solution to homework assignment 1
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

   int main()
   {
    int number, digitCounter = 0, eachDigitOfNumber, counterRepeatingDigits=0;
    cout<<"Input a number: ";
	cin>>number;
	//if the input is not an integer the program will request for a new input.
     while(1){
       if( cin.fail() ){
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(),'\n');
         cout << "You have entered wrong input! Try with a number between -2147483648 and 2147483647." << endl;
         cout << "Input a number: " ;
         cin >> number;
        }
          if( !cin.fail() )
                 break;
              }

	int numberSubstituteWhile = number, currentDigit, rememberNumber = number, rememberNumberReplacement = number;
    /*I use the while loop to count the number of digits in the number so I can use it as a condition in the two for loops.*/
	while(numberSubstituteWhile != 0){
		numberSubstituteWhile = numberSubstituteWhile / 10;
		digitCounter ++;
	}

	for(int i = 0; i < digitCounter; i ++){
            /*In the first for loop I assign the last digit of the number to currentDigit. Then after the second for loop in the end of the first I remove the last digit of the number
            so in the next iteration currentDigit will become the next digit. */
            currentDigit = number % 10;
            rememberNumber = rememberNumberReplacement; /*rememberNumber and rememberNumberReplacement are used to assign the value of number when needed.
            /*Here in the second for loop the currentDigit is compared with each digit of the number. If they are equal the counter increases*/
            for(int j = 0; j < digitCounter; j ++){
                eachDigitOfNumber = rememberNumber % 10;
                if(eachDigitOfNumber == currentDigit) counterRepeatingDigits ++;
                /*The syntax here is like in the first loop. I get the last digit, after the if operator I remove the last digit of rememberNumber which is equal to number
                 and then in the next iteration eachDigitOfNumber becomes the next digit.*/
                rememberNumber = rememberNumber / 10;
            }
    number = number / 10;
	}
        /*I take digitCounter out of counterRepeatingDigits because in the second loop in each iteration the currentDigit is being compared with itself so the if then is true and
        counterRepeatingDigits increases and increases as many times as the number of digits is so we need to take them out (the number of digits is remembered in digitCounter)*/
	    if(counterRepeatingDigits - digitCounter > 0) cout << "Answer: " << "Yes" <<endl; //If there were more repeating digits out of those which are compared with itself the if will be true.
		    else cout << "Answer: " << "No" <<endl;
   }
