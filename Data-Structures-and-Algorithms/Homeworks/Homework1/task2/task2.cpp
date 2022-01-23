#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N,j=0,result,x;
    cin>>N;
    char que[N];
    int biggest[N]={0};
    for(int i=0;i<N;i++) cin>>que[i];

    for(int i=0;i<N;i++){
        if(que[i]=='x') {j++;x=i; continue;}
        else biggest[j]++;
    }
    if(j==N) result = -1;
    int maximal = biggest[0];
    for(int i=0;i<j;i++){
        if(maximal<biggest[i]) maximal = biggest[i];
    }
    if(maximal%2==0) result = maximal/2-1;
    else result = maximal/2;
    if(que[N-1]=='-'&&N-1-x>=maximal) result = N-1-x-1;
    if(que[0]=='-'&&biggest[0]-1>result) result = biggest[0]-1;
    cout<<result<<endl;  
    return 0;
}
