    #include <cmath>
    #include <cstdio>
    #include <vector>
    #include <iostream>
    #include <algorithm>
    #include <list>
    #include <unordered_map>
    #include <unordered_set>
    #include <string>
    #include <deque>
    #include <climits>
    using namespace std;

    const int ALPHABET_SIZE = 26;
    const int DICTIONARY_SIZE = 100;
    bool dfs(vector<vector<bool>>& , int , vector<bool>& , string& );
    void newAlphabet(vector<string>& );

    void newAlphabet(vector<string>& dictionary){
        vector<vector<bool>> l(ALPHABET_SIZE, vector<bool>(ALPHABET_SIZE));
        vector<bool> visited(ALPHABET_SIZE);
        string alphabet;
        for(int i=0;i<dictionary.size();i++){
            for(int j=0;j<dictionary[i].size();j++){
                 //cout<<dictionary[i]<<" "<<dictionary[i][j]<<endl;
                l[dictionary[i][j] - 'a'][dictionary[i][j] - 'a'] = true;
            }
        }
        for(int i=0;i<(int)dictionary.size()-1;i++){
            int minimal = min(dictionary[i].size(), dictionary[i + 1].size());
            int j=0;
            for(j=0;j<minimal;j++){
                if(dictionary[i][j] != dictionary[i + 1][j]){
                    l[dictionary[i][j] - 'a'][dictionary[i + 1][j] - 'a'] = true;
                    break;
                }
            }
            if(j==minimal && dictionary[i].size() > dictionary[i + 1].size()) alphabet = "";
        }
        for(int i=0;i<ALPHABET_SIZE;i++){
            if(!dfs(l, i, visited, alphabet)) alphabet = "";
        }
        for(int i=0;i<alphabet.size();i++){
            cout<<alphabet[i]<<" ";
        }
    }
    
    bool dfs(vector<vector<bool>>& l, int indx, vector<bool>& visited, string& alphabet){
        if(!l[indx][indx]) return true;
        visited[indx] = true;
        for(int i=0;i<ALPHABET_SIZE;i++){
            if(i==indx || !l[i][indx]) continue;
            if(visited[i]) return false;
            if(!dfs(l, i, visited, alphabet)) return false;
        }
        visited[indx] = false;
        l[indx][indx] = false;
        alphabet += 'a' + indx;
        return true;
    }
    
    int main(){
       vector<string> dictionary(DICTIONARY_SIZE);
       int N;
       cin>>N;
       for(int i=0;i<N;i++){
          string newWord;
          cin>>newWord;
          dictionary.push_back(newWord);
       }
       newAlphabet(dictionary);
       return 0;
    }
