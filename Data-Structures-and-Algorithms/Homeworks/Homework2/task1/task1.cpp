#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N,counter = 0,position;
    cin>>N;
    long long int arr[N];
    double median[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
        counter++;
        long long int newArr[counter]={0};
        position = 0;
        for(int j=0;j<counter;j++){
            if(arr[i]>arr[j]){
                 newArr[j] = arr[j]; position++; continue;
            }
            else newArr[position] = arr[i];
        }
        //cout<<"P "<<position<<endl;
        for(int j=position+1;j<counter;j++){
            newArr[j] = arr[j-1];
        }

        if(counter%2!=0) median[i] = (double)newArr[counter/2];
        else
            median[i] = (double)(newArr[(counter-1)/2] + newArr[counter/2])/2.0;

        for(int j=0;j<counter;j++){
            arr[j] = newArr[j];
        }
    }

    for(int i=0;i<N;i++) cout<<median[i]<<endl;  
    return 0;
}
