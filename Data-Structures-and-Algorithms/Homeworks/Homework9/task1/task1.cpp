#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

unordered_set<string> prefixes;
unordered_map<string, int> studentNames;


int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        string name;
        string prefix="";
        bool isPrinted = false;
        cin>>name;
        for(int j=0;j<name.size();j++){
            prefix += name[j];
            if(prefixes.count(prefix)==0 && isPrinted == false){
                cout<<prefix<<endl;
                isPrinted = true;
            }
            prefixes.insert(prefix);
        }
        if(studentNames.count(name) == 0){
            if(isPrinted == false){
                cout<<name<<endl;
            }
            studentNames[name] = 1;
        }
        else{
            studentNames[name]++;
            cout<<name<<" "<<studentNames[name]<<endl;
        }
    }

    return 0;
}
