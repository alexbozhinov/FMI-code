#include<bits/stdc++.h>
using namespace std;

long long int findSheets(int T[], int k, long long int mid){

    long long int sheetsToCopy = 0;
    for (int i=0;i<k;i++)
        sheetsToCopy += (mid / T[i]);
    return sheetsToCopy;
}

long long int bSearch(int T[], int k, long long int n, long long int maxTime){

    long long int from = 1;

    while (from < maxTime){
    

        long long int mid = from + (maxTime - from) / 2;

        long long int sheets = findSheets(T, k, mid);

        if (sheets < n){
            from = mid + 1;
        }
        else{
            maxTime = mid;
        }
    }

    return maxTime;
}

long long int minTime(int T[], int k, long long int n){

    int maximal = T[0];

    for (int i=0;i<k;i++){
        if(maximal < T[i]) maximal = T[i];
    }

    return bSearch(T, k, n, maximal*n);
}

int main()
{
int k;
long long int n;
cin>>n;
cin>>k;
int T[k];
for(int i=0;i<k;i++) cin>>T[i];
cout<<minTime(T, k, n)<<endl;
return 0;
}
