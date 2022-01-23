#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N,K,A,Q;
    cin>>N>>K>>A;
    cin>>Q;
    int shoots[Q];
    for(int i=0;i<Q;i++) cin>>shoots[i];
    int arr[N];
    for(int i=0;i<N;i++) arr[i] = i+1;

    int counter = 0;
    bool shooted = false;
    for(int i=0;i<Q;i++){
       /* if(N-shoots[i]<A && shoots[i] > A+1){
            counter++; break;
        }
        else{
            counter++; continue;
        }*/
       int freePlaces = N-A*K;
       if(Q<freePlaces) {counter = -1; break;}
    

    }
    if(counter == 0) cout<<-1<<endl;
    else cout<<counter<<endl;

    return 0;
}
