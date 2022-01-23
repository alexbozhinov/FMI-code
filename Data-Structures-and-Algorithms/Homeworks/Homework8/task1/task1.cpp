#include <bits/stdc++.h>
using namespace std;

void printMinimumClassRooms(long long startTime[], long long endTime[], int N){
   sort(startTime, startTime + N);
   sort(endTime, endTime + N);
   int i=0,j=0;
   int minimumRooms = 0;
   int currReservedRooms = 0;

    while(i<N){
        if(endTime[j] > startTime[i]){
           currReservedRooms++;
           if(currReservedRooms > minimumRooms){
              minimumRooms = currReservedRooms;
              //cout<<1<<endl; 
           }
            i++;
         }else{
            j++;
            currReservedRooms--;
            //cout<<2<<endl;
         }
    }
   //cout<<3<<endl;
   printf("%d",minimumRooms);
}





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
      int N;
      scanf("%d", &N);
      long long startTime[N], endTime[N];
      for(int i=0;i<N;i++){
        scanf("%lld",&startTime[i]);
        scanf("%lld",&endTime[i]);
      }
      //for(int i=0;i<N;i++) cout<<startTime[i]<<" ";
    printMinimumClassRooms(startTime,  endTime, N);

    return 0;
}
