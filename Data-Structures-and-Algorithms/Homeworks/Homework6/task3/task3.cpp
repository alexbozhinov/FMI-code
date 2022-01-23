#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    string data;
    Node(string _data){
        this->data = _data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BST{

private:
    Node* root;

    Node* Find(Node* curNode, string data){
        if(curNode == nullptr){
            return nullptr;
        }    
        if(curNode->data == data){
            return curNode;
        }    
        if(curNode->data < data){
            return Find(curNode->right, data);
        }    
         return Find(curNode->left, data);
    }

    Node* add(Node *curNode, string data){
        if(curNode == nullptr){
            return new Node(data);
        }
        if(curNode->data < data){
            curNode->right = add(curNode->right, data);
        }
        else{
            curNode->left = add(curNode->left, data);
        }
        return curNode;
    }

public:
    BST(){
        this->root = nullptr;
    }
    void add(string data){
        if(root == nullptr){
            root = new Node(data);
        }
        else{
            add(root, data);
        }
    }

    bool ifExist(string data){
        return Find(root, data) != nullptr;
    }

};

int main() {
    int N,Q;
    BST t;
    cin>>N;
    for(int i=0;i<N;i++){
        string word;
        cin>>word;
        t.add(word);
    }
    cin>>Q;
    bool answer[Q]={false};
    for(int i=0;i<Q;i++){
        string querry;
        cin>>querry;
        if(t.ifExist(querry)) answer[i] = true;
    }

    for(int i=0;i<Q;i++){
        if(answer[i] == true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
