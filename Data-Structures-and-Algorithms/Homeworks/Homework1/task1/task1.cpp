#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N,result=0;
    cin>>N;
    int prices[N];
    for(int i=0;i<N;i++) cin>>prices[i];
    int curr = 0;
    for(int i=0;i<N;i++){
        if(i<N-1&&prices[i+1]>=prices[i]) continue;
        else {result+=(prices[i]-prices[curr]);curr+=(i-curr+1);}
        if(i==N-1&&curr<N&&prices[i]>prices[curr]){result+=(prices[i]-prices[curr]);}
    }
    cout<<result<<endl;  
        return 0;
}
