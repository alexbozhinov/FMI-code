#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <deque>
#include <climits>
using namespace std;

vector<pair<int,int>> adj[10000];


void BFS(int source, int N){
   int distance[N];
   for(int i=0;i<N;i++){
        distance[i] = INT_MAX;
   }
   deque<int> Q;
   distance[source] = 0;
   Q.push_back(source);

   while(!Q.empty()){
        int k = Q.front();
        Q.pop_front();

        for(int i=0;i<adj[k].size();i++){
           if(distance[adj[k][i].first] > distance[k] + adj[k][i].second){
              distance[adj[k][i].first] = distance[k] + adj[k][i].second;

                if(adj[k][i].second == 0){
                    Q.push_front(adj[k][i].first);
                }
                else{
                    Q.push_back(adj[k][i].first);
                }
            }
        }
    }
    if(distance[N-1] == INT_MAX) cout<<-1<<endl;
    else cout<<distance[N-1]<<endl;
}



int main(){
    int N,M,K;
    cin>>N>>M>>K;
    for(int i=0;i<M;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back({y,0});
        adj[y].push_back({x,0});
    }
    for(int i=0;i<K;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back({y,1});
        adj[y].push_back({x,1});
    }
    BFS(0,N);

    return 0;
}
