#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;


int main() {
    int T,odd = 0,counter[256];
    cin>>T;
    bool result[T] = {false};
    for(int i=0;i<T;i++){
        string str;
        cin>>str;
            for(int j=0;j<256;j++) counter[j] = 0;

            for (int j = 0; j<str.length();  j++){
                   counter[str[j]]++;
            }
            odd = 0;
            for (int j = 0; j < 256; j++){
                if (counter[j] % 2 != 0)
                      odd++;
            }

            if (odd <= 1){

                 result[i] = true;
            }
    }
    for(int i=0;i<T;i++){
        if(result[i]==true) cout<<"TRUE"<<endl;
        else if(result[i]==false) cout<<"FALSE"<<endl;
    }
return 0;
}
