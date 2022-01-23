#include <bits/stdc++.h>
using namespace std;


long long upperBound( long long arr[],  long long to,  long long Y, long long Size) {


    long long mid, from = 0;

    while (from < to) {

        mid = from + (to - from) / 2;

        if (Y >= arr[mid]) {
            from = mid + 1;
        }

        else {
            to = mid;
        }
    }
return to-1;
}

 long long lowerBound(long long arr[], long long to, long long X)
{
     long long mid, from = 0;

    while (from < to) {
        mid = from + (to - from) / 2;

        if (X <= arr[mid]) {
            to = mid;
        }

        else {
            from = mid + 1;
        }
    }
    if(arr[mid] == X) return to;
    else return to;
}



struct Query{
    long long S;
    long long P;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     long long N,Q,sum = 0, startIdx, sumIdx, counter = 0, i=0;
    scanf("%lld%lld", &N, &Q);
    long long arr[N], sumArr[N];
    Query queries[Q];

    for(i=0;i<N;i++) scanf("%lld", &arr[i]);
    sort(arr, arr+N);
    for(int i=0;i<N;i++){
        sum = sum + arr[i];
        sumArr[i] = sum;
    }
    sum = 0;

    for(i=0;i<Q;i++){
         scanf("%lld%lld", &queries[i].S, &queries[i].P);
    }

    for(i=0;i<Q;i++){
        startIdx = upperBound(arr,N,queries[i].P,N);


        sumIdx = upperBound(sumArr, N, sumArr[startIdx] - queries[i].S,N);


        if(sumArr[startIdx] - queries[i].S>0) counter = startIdx - sumIdx-1;
        else  counter = startIdx+1;
        if(sumArr[startIdx] - queries[i].S == sumArr[sumIdx]) counter = startIdx - sumIdx;
        if(startIdx<0) counter = 0;

        printf("%lld\n", counter);
        sum = 0;
        counter = 0;
    }

    return 0;
}
