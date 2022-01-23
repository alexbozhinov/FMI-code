#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long bs(long long A[], long long N, long long el) {
  long long L = 0;
  long long R = N - 1;

  while (L <= R) {
    long long M = L + ((R - L) / 2);
    if (A[M] == el) return M;


    if (A[L] <= A[M]) {
      if (A[L] <= el && el < A[M])
        R = M - 1;
      else
        L = M + 1;
    }
    else {
      if (A[M] < el && el <= A[R])
        L = M + 1;
      else
        R = M - 1;
    }
  }
  return -1;
}


int main() {
    long long int N,Q;
    cin>>N;
    long long int A[N];
    for(int i=0;i<N;i++) cin>>A[i];
    cin>>Q;
    long long int Query[Q];
    for(long long i=0;i<Q;i++) cin>>Query[i];
    
    for(long long i = 0;i<Q;i++) cout<<bs(A,N,Query[i])<<endl;
    
    
    return 0;
}
