#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
int N;
cin>>N;
int counter = 0;
int left=1; int right=1;
long long int arrL[N], arrR[N], result[2*N];
    
for(int i=0;i<N;i++){
    cin>>arrL[i];
    cin>>arrR[i];
}
    
if(N==1) {result[0] = arrL[0]; result[1] = arrR[0]; N=0;} 
sort(arrL, arrL+N);
sort(arrR, arrR+N);
    
result[0] = arrL[0];
for(int i=0;i<N-1;i++){
    if(arrL[i+1]<=arrR[i]) {
        counter++; result[right] = arrR[i+1];continue;
    }
    else{
        left = right + 1; 
        if(counter == 0) {result[right] = arrR[i];}
        result[left] = arrL[i+1]; right = left+1; result[right] = arrR[i+1];continue;
    }
}

for(int i=0;i<right+1;i++){
    cout<<result[i]<<" ";
    if(i%2!=0) cout<<endl;
}

    return 0;
}
