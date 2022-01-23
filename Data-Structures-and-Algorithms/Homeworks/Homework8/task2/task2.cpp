#include <bits/stdc++.h>
using namespace std;

priority_queue < double, vector<double>, less<double> > beforeMedian;
priority_queue < double, vector<double>, greater<double> > afterMedian;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
      cout << fixed << setprecision(1);

      beforeMedian.push(DBL_MIN);
      afterMedian.push(DBL_MAX);

      int N;
      scanf("%d", &N);
      //cout<<afterMedian.top()<<endl;
      //cout<<beforeMedian.top()<<endl;
      for(int i=0;i<N;i++){
        double median;
        double money;
        scanf("%lf", &money);

        if(money >= afterMedian.top()) afterMedian.push(money);
        else beforeMedian.push(money);

        if(beforeMedian.size() - afterMedian.size() == 2){
            afterMedian.push(beforeMedian.top());
            beforeMedian.pop();
        }
        else if(afterMedian.size() - beforeMedian.size() == 2){
            beforeMedian.push(afterMedian.top());
            afterMedian.pop();
        }

        if(beforeMedian.size() == afterMedian.size()){
            median = (beforeMedian.top() + afterMedian.top()) / 2.0;
        }
        else if(beforeMedian.size()>afterMedian.size()) median = beforeMedian.top();
        else median = afterMedian.top();

        cout<<median<<'\n';
      }

    return 0;
}
