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


void check(int edges[][2], int queries[][2], int N, int Q){
  bool answer[Q] = {false};
  for(int i=0;i<Q;i++){
    int son = queries[i][0];
    int father = edges[son][1];//queries[i][1];
    while(father != -1){
        if(father == queries[i][1]) answer[i] = true;
        son = edges[father][0];
        father = edges[son][1];
    }
  }
   for(int i=0;i<Q;i++){
    if(answer[i] == true) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
   }

}



int main(){

int N;
cin>>N;
int edges[N][2];
edges[0][0] = 0;
edges[0][1] = -1;
for(int i=1;i<N;i++){
    for(int j=1;j>=0;j--){
        cin>>edges[i][j];
    }
}

int Q;
cin>>Q;
int queries[Q][2];
for(int i=0;i<Q;i++){
    for(int j=1;j>=0;j--){
        cin>>queries[i][j];
    }
}
check(edges, queries, N, Q);

    return 0;
}
