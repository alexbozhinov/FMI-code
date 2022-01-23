#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void check(int edges[][2], int N){
  int answer[N] = {0};
  for(int i=0;i<N-1;i++){
      int u = edges[i][0];
      answer[u]++;
  }
  for(int i=N-2;i>=0;i--){
     int u=edges[i][0];
     int v=edges[i][1];
     answer[u]+=answer[v];
  }
  for(int i=0;i<N;i++){
    cout<<answer[i]<<" ";
}
}


int main(){

int N;
cin>>N;
int edges[N][2];
for(int i=0;i<N-1;i++){
    for(int j=0;j<2;j++){
        cin>>edges[i][j];
    }
}
check(edges,N);


    return 0;
}
