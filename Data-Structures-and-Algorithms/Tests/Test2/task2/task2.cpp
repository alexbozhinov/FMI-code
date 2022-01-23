#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int counting[500001] = {0};
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        counting[arr[i]]++;
    }
    for(int i=0;i<50001;i++) {
        if(counting[i]>0 )  
            cout<<i<<" ";
    }
    return 0;
