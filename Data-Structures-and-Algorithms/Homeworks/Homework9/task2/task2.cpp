#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    unordered_map<int, int> m;
    int N, sum = 0, longestSubArr = 0;
    cin>>N;
    bool arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    m.insert({0,-1});
    for(int i=0;i<N;i++){
        if(arr[i] == 0) sum+=-1;
        else sum+=1;
        if(m.count(sum)!=0){
            int indx = m.at(sum);
            int length = i-indx;
            if(longestSubArr < length) longestSubArr = length;
        }
        else{
            m.insert({sum,i});
        }
    }
    cout<<longestSubArr<<endl;
    return 0;
}
