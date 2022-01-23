#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<long long, int> foundedKeys;

int main() {
    long long n;
    cin>>n;
    long long a[n], b[n];
    long long keysToBuy = 0;
    for(int i=0;i<n-1;i++){
        cin>>b[i];
    }
    for(int i=0;i<n-1;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        if(foundedKeys.count(b[i])==0) foundedKeys.insert({b[i],1});
           else foundedKeys[b[i]]++;

        if(foundedKeys.count(a[i])>0 && foundedKeys[a[i]]>1) foundedKeys[a[i]]--;
        else if(foundedKeys.count(a[i])>0 && foundedKeys[a[i]]==1) foundedKeys.erase(a[i]);
        else keysToBuy++;
        //cout<<foundedKeys.size()<<endl;
    }
    cout<<keysToBuy<<endl;
    return 0;
}
