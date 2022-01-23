#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N,result;
      cin>>N;
      int A[N];
      for(int i=0;i<N;i++) cin>>A[i];
      int counter = 0;
      sort(A,A+N);
      while(A[counter]<=0) counter++;
      for(int i=counter+1;i<N;i++){
        if(A[i]-A[i-1]>1) {result = A[i-1]+1;break;}
      }
      cout<<result<<endl;  
    return 0;
}
