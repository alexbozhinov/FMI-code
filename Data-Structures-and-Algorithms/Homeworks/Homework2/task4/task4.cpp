#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int End;
};

bool compareInterval(Interval i1, Interval i2)
{
    if(i1.start < i2.start) return true;
    else if(i1.start == i2.start){if(i1.End>=i2.End) return true;}
    return  false;
}

int main()
{   int N;
    cin>>N;
    int A[N],B[N];
    for(int i=0;i<N;i++){
        cin>>A[i];
        cin>>B[i];
    }
    Interval arr[N];
    for(int i=0;i<N;i++){
        arr[i].start = A[i];
        arr[i].End = B[i];
    }

    sort(arr, arr + N , compareInterval);

    int counter = 0;
    Interval first = arr[0];
    for (int i = 1; i < N ; i++){
        if (first.start<=arr[i].start&&first.End>=arr[i].End){
            counter ++;}
         else {first = arr[i];}
   }

    cout<<counter<<endl;

    return 0;
}
