#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

unsigned long long int degree(int counter){
   unsigned long long int result = 1;
   for(int i=0;i<counter;i++){
     result*=10;
   }
   return result;
}

string fromDecToBinary(long long int number){

    int counter = 19;
    string bin = "00000000000000000000";
    while (number != 0) {
        int remainder = number % 2;
        if(remainder!=0) bin[counter] = 'a';
        number /= 2;
        counter--;
    }
   return bin;
}

int countA(string number){
int counter = 0;
for(int i=0;i<number.size();i++){
    if(number[i] == 'a') counter++;
}
return counter;
}

int firstA(string number){
    int idx;
for(int i=0;i<number.size();i++){
    if(number[i]!='a') continue;
    else {idx = i; break;}
}
return idx;
}

    set<string> s;



void generateMasks(string number){

//int counter = countA(number);
//cout<<countA(number)<<endl;
if(countA(number)==0) s.insert(number);
else{
    string num1 = number;
    num1[firstA(num1)] = '0';
    generateMasks(num1);
    string num2 = number;
    num2[firstA(num2)] = '1';
    generateMasks(num2);
    //cout<<s.size();
}


}


int main() {

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        generateMasks(fromDecToBinary(num));
    }
    //for(auto it = s.begin(); it != s.end(); it++) cout<<*it<<endl;
    cout<<s.size()<<endl;
   //cout<<fromDecToBinary(3);
}
