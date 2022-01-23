#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long A,B,uniqueCounter = 0,i,number;

int main()
{
scanf("%llu%llu", &A, &B);
for(i=B;i>=A;i--){
    number = i;
    bool visited[10] = {false};

    while(number!=0){
        if(visited[number%10] == true) break;
        visited[number%10] = true;
        number /= 10;
    }
    if(number == 0)
    uniqueCounter++;
}
printf("%llu", uniqueCounter);
return 0;
}
