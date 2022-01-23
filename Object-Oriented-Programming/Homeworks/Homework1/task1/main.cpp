#include<iostream>
#include<cstring>
#include "MyString.h"

using namespace std;

int main(){


MyString temp1("Hello world");
temp1.append('!');                     /// add symbol in the end of the string
MyString temp2("Hello world!");
temp1.print();                         ///function print()
cout<<temp2<<endl;                     ///operator <<

if(temp1==temp2) cout<<"==YES they are equal"<<endl;      ///check operator ==
else cout<<"==NO they are not equal"<<endl;

if(temp1!=temp2) cout<<"!=YES they are different"<<endl;   ///check operator !=
else cout<<"!=NO they are not different"<<endl;

if(temp1>temp2) cout<<">YES the left string is bigger than the right"<<endl;   ///check operator >
else cout<<">NO the left string is not bigger than the right"<<endl;

if(temp1<temp2) cout<<"<YES the left string is smaller than the right"<<endl;   ///check operator <
else cout<<"<NO the left string is not smaller than the right"<<endl;

return 0;
}
