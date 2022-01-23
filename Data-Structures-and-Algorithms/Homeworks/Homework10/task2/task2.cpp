#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

bool flag;

void dfs(int u, int visited[], vector<int> adj[]){
   if(visited[u] == -1){
       flag = true;
       return;
   }
   visited[u] = -1;

   for(int v: adj[u]){
       if(visited[v]!=1){
          dfs(v,visited,adj);
       }

   }
   visited[u] = 1;
}

int main() {
    int N;
    cin>>N;
    string answer[N];
    for(int i=0;i<N;i++){
        int V,E;
        cin>>V>>E;
        int x[E],y[E],z[E];
        vector<int> adj[100000];
        flag = false;

        for(int j=0;j<E;j++){
            cin>>x[j]>>y[j]>>z[j];
            adj[x[j]].push_back(y[j]);
        }
        int visited[V+1] = {0};
        for(int j=1;j<=V;j++){
           if(!visited[j]) dfs(j,visited,adj);
           if(flag == true) break;
        }
       if(flag) answer[i] = "true";
       else answer[i] = "false";

    }
    for(int i=0;i<N;i++) cout<<answer[i]<<" ";
    return 0;
}
