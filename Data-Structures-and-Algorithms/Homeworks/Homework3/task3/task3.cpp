#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void generateArray(long long int k,long long int left,long long int right, int add){
  if(right >= left){

  long long int mid1 = left + (right - left) / 3;
  long long int mid2 = right - (right - left) / 3;
  if((mid2-mid1+1)%2==0) mid2 = mid2 - 1;
 

  if(mid1<=k && k<=mid2) {cout<<add<<endl;}
  else if(k<mid1){add++;  generateArray(k,left,mid1,add);}
  else if(mid2<k){add++; generateArray(k,mid2+1,right,add);}
  }
  return ;
}



int main() {
    int N,P,add = 1;
    cin>>P>>N;
    long long int a[N];

    for(int i=0;i<N;i++) cin>>a[i];
    long long int Size = pow(3,P);
    for(int i=0;i<N;i++){
        generateArray(a[i]-1,0,Size,add);
    }
    return 0;
}
