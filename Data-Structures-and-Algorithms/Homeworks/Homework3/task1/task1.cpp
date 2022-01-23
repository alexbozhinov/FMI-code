#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int lowerBound(int arr[], int from , int to, int X)
{
    int mid;

    while (from < to) {
        mid = from + (to - from) / 2;

        if (X <= arr[mid]) {
            to = mid;
        }

        else {
            from = mid + 1;
        }
    }

    return from;
}

int upperBound(int arr[], int from, int to, int Y)
{
    int mid;

    while (from < to) {

        mid = from + (to - from) / 2;

        if (Y >= arr[mid]) {
            from = mid + 1;
        }

        else {
            to = mid;
        }
    }
    return from;
}


int main() {
    int n,q;
    cin>>n>>q;
    int mark[n], x[q], y[q], counter[q] = {0};

    for(int i=0;i<n;i++) cin>>mark[i];
    for(int i=0;i<q;i++){
        cin>>x[i];
        cin>>y[i];
        /*if(x[i]>y[i]) {
            int temp = x[i];
            x[i] = y[i];
            y[i] = temp;
        }*/
    }
    sort(mark,mark+n);

    for(int i=0;i<q;i++){
       if(x[i]>y[i]) counter[i] = 0;
        else{
        int lower = lowerBound(mark, 0, n, x[i]);
        int upper = upperBound(mark, 0, n, y[i]);
        counter[i] = fabs(upper - lower);
        }
    }

    for(int i=0;i<q;i++) cout<<counter[i]<<endl;
    return 0;
}
