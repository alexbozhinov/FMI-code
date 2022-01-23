#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N,M;
    cin>>N;
    int arr1[N],newArr1[N];
    for(int i=0;i<N;i++) cin>>arr1[i];
    cin>>M;
    int arr2[M],newArr2[M];
    for(int i=0;i<M;i++) cin>>arr2[i];
    
    sort(arr1,arr1+N);
    sort(arr2,arr2+M);
    int k=0,counter = 0;
    for(int i=0;i<N;i++){
         counter = 0;
        for(int j=i+1;j<N;j++){
           
            if(arr1[i]==arr1[j]) counter++;
        }
        if(counter == 0) {newArr1[k] =  arr1[i]; k++;}
    }
    int l=0;
    counter=0;
    
        for(int i=0;i<M;i++){
            counter = 0;
        for(int j=i+1;j<M;j++){
            
            if(arr2[i]==arr2[j]) counter++;
        }
        if(counter == 0) {newArr2[l] =  arr2[i]; l++;}
    }
    int sum=0;
    for(int i=0;i<k;i++){
        for(int j=0;j<l;j++){
            if(newArr1[i]==newArr2[j]) sum+=newArr1[i];
        }
    }
    cout<<sum<<endl;
    
    return 0;
}
