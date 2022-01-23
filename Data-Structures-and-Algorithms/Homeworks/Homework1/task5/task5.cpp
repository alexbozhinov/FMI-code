#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const long long int DIVIDER = 1000000007;
int main() {
   int N;
   cin>>N;
   long long int A[N],B[N];
   for(int i=0;i<N;i++) cin>>A[i];

   for(int i=0;i<N;i++){
        B[i] = 1;
    for(int j=0;j<N;j++){
        if(j!=i) B[i]=A[j]*B[i]%DIVIDER;
    }
   }
   for(int i=0;i<N;i++) {
        cout<<B[i]<<" ";
   }   
    return 0;
}
