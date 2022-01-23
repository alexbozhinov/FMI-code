/**
*
* Solution to homework assignment 1
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
#include<math.h>
#include<limits>
using namespace std;
   int main()
   {
   	char arithmeticSymbol, hexNumber1, hexNumber2, hexDigit1,hexDigit2 ;
   	int decimalNumber1, decimalNumber2, decimalResult, hexResult, hexNumberOfDigitsCounter = 0 ;
   	cout<<"Input an arithmetic symbol and two hex positive digits: "<<endl;
   	cout<<endl;
   	cout<<"Arithmetic symbol: " ;
   	cin >> arithmeticSymbol ;
   	cout<<"First positive hex digit= ";
   	cin >> hexNumber1 ;
   	cout<<"Second positive hex digit= ";
	cin >> hexNumber2 ;
while(2){

           if( cin.fail() ){
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
                continue;
            }
       // I tried with this validation but it does not work!
/*if( arithmeticSymbol!=43||arithmeticSymbol!=45||arithmeticSymbol!=42||arithmeticSymbol!=47||arithmeticSymbol!=37||hexNumber1!='0' ||hexNumber1!='1'||hexNumber1!='2'||hexNumber1!='3'
              ||hexNumber1!='4'||hexNumber1!='5'||hexNumber1!='6'||hexNumber1!='7'||hexNumber1!='8'||hexNumber1!='9'||hexNumber1!='A'||hexNumber1!='B'||hexNumber1!='C'||hexNumber1!='D'||hexNumber1!='E'
              ||hexNumber1!='F'||hexNumber2!='0' ||hexNumber2!='1'||hexNumber2!='2'||hexNumber2!='3'||hexNumber2!='4'||hexNumber2!='5'||hexNumber2!='6'||hexNumber2!='7'||hexNumber2!='8'||hexNumber2!='9'
              ||hexNumber2!='A'||hexNumber2!='B'||hexNumber2!='C'||hexNumber2!='D'||hexNumber2!='E'||hexNumber2!='F'){
              cout << "You have entered wrong input, try with another values" << endl;

             cout<<endl;
              cout<<endl;
    cout<<"Enter an arithmetic symbol: ";
   	cin >> arithmeticSymbol ;
   	cout<<"Enter the first positive hex digit= ";
   	cin >> hexNumber1 ;
   	cout<<"Enter the second positive hex digit= ";
	cin >> hexNumber2 ;
              continue;
            }*/
           if( !cin.fail() )
                 break;
   	        }
//In the next 4 lines I transform the inputed hex digits into decimal numbers.
if( hexNumber1 == 'A' || hexNumber1 == 'B' || hexNumber1 == 'C' || hexNumber1 == 'D' || hexNumber1 == 'E' || hexNumber1 == 'F' ) decimalNumber1 = hexNumber1 - 'A' +10;
if( hexNumber1 >= '0' && hexNumber1 <= '9' ) decimalNumber1 = hexNumber1 - '0';
if( hexNumber2 == 'A' || hexNumber2 == 'B' || hexNumber2 == 'C' || hexNumber2 == 'D' || hexNumber2 == 'E' || hexNumber2 == 'F' ) decimalNumber2 = hexNumber2 - 'A' + 10;
if( hexNumber2 >= '0' && hexNumber2 <= '9') decimalNumber2 = hexNumber2 - '0';

//Making the arithmetic operations. It depends on what the inputed arithmetic symbol is.
switch( arithmeticSymbol )
   {
   	case '+': {
   	    decimalResult = decimalNumber1 + decimalNumber2;
   	    break;
    }
    case '-': {
        if(decimalNumber1 < decimalNumber2)
        decimalResult = decimalNumber2 - decimalNumber1;
        else
    	decimalResult = decimalNumber1 - decimalNumber2;
		break;
	}
	case '*': {
		decimalResult = decimalNumber1 * decimalNumber2;
		break;
	}
	case '/': {
		decimalResult = decimalNumber1 / decimalNumber2;
		break;
	}
	case '%': {
		decimalResult = decimalNumber1 % decimalNumber2;
		break;
	}

   }
   /*In the while loop I transform the decimalResult which is a decimal number to a hex number. Because the biggest result can be 15*15=225 every result in hex can be written with 1 or 2
   symbols(digits). So I have a counter if it is 1 I print the first digit. And if it is 2 firstly I print the second and then concatenate it with the first because when we transform a digit from
   decimal to hex we divide on 16 and get the rest from the last to the first. The loop works similarly to the loop for in the first program*/
   while( decimalResult > 0 ){
   	hexResult = decimalResult % 16;
   	 if( hexResult >= 0 && hexResult <= 9) hexResult = hexResult + '0';
   	   if( hexResult == 10 || hexResult == 11 || hexResult == 12 || hexResult == 13 || hexResult == 14 || hexResult == 15 ) hexResult = hexResult + 'A' - 10 ;


   	   hexNumberOfDigitsCounter ++;
   	   if( hexNumberOfDigitsCounter == 1) hexDigit1 = hexResult;
   	   if( hexNumberOfDigitsCounter == 2) hexDigit2 = hexResult;
   	   decimalResult = decimalResult / 16;

   }
   //The input can't be a negative number, but in ways the result could be so then I print "-" before the result.(It happens when the arithmetic symbol is - and the first digit is lower then the second.)

   switch( hexNumberOfDigitsCounter ){
   	case 1: {
   	    if((arithmeticSymbol == '-') && (decimalNumber1 < decimalNumber2))
        cout << "The result is: -" << hexDigit1 << endl;
        else
		cout << "The result is: "<< hexDigit1 << endl;
		break;
	   }
   	case 2: {
        if(( arithmeticSymbol == '-') && (decimalNumber1 < decimalNumber2))
        cout << "The result is: -" << hexDigit2 << hexDigit1 << endl;
        else
	    cout << "The result is:  "<< hexDigit2 << hexDigit1  << endl;
	    break;
	   }
   }
   return 0;
}
