#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

set<long long> s;
vector<int> arr;

int main() {

   s.insert(0);
   int Q;
   cin>>Q;
   int minimal = 2147483647;
   for(int i=0;i<Q;i++){
       long long P;
       cin>>P;
       auto it = s.insert(P);
       auto prev = it.first;
       prev--;
       if(((*prev)^(*(it.first)))<minimal) minimal = ((*prev)^(*(it.first)));
       auto after = it.first;
       after++;
       if(after!=s.end()){
           if(((*after)^(*(it.first)))<minimal) minimal = ((*after)^(*(it.first)));
       }
       arr.push_back(minimal);
   }
   for(int i=0;i<arr.size();i++){
       cout<<arr[i]<<endl;
   }
   return 0;
}
