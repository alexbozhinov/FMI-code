#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Node{
    long long key;
    int height;
    Node* left;
    Node* right;
    Node(long long data){
       key = data;
       left = right = 0;
       height = 1;
    }
};

int height(Node* curr){
    if(curr) return curr->height;
    else return 0;
}

int balanceFactor(Node* curr){
    return height(curr->right)-height(curr->left);
}

void fixHeight(Node* curr){
    int heightLeft = height(curr->left);
    int heightRight = height(curr->right);
    if(heightLeft > heightRight) curr->height = heightLeft + 1;
    else curr->height = heightRight + 1;
}

Node* rotateToRight(Node* curr){
    Node* currLeft = curr->left;
    curr->left = currLeft->right;
    currLeft->right = curr;
    fixHeight(curr);
    fixHeight(currLeft);
    return currLeft;
}

Node* rotateToLeftt(Node* curr){
    Node* currRight = curr->right;
    curr->right = currRight->left;
    currRight->left = curr;
    fixHeight(curr);
    fixHeight(currRight);
    return currRight;
}

Node* balanceNode(Node* curr){
    fixHeight(curr);
    if( balanceFactor(curr)==2 ){
        if( balanceFactor(curr->right) < 0 )
            curr->right = rotateToRight(curr->right);
        return rotateToLeftt(curr);
    }
    if( balanceFactor(curr)==-2 ){
        if( balanceFactor(curr->left) > 0  )
            curr->left = rotateToLeftt(curr->left);
        return rotateToRight(curr);
    }
    return curr;
}

Node* Find(Node* curNode, long long value){
    if(curNode == NULL)
        return NULL;
    if(curNode->key == value)
        return curNode;
    if(curNode->key < value)
       return Find(curNode->right, value);
       return Find(curNode->left, value);
}

bool ifExist(Node* curr, long long value){
    return Find(curr, value) != NULL;
}


Node* add(Node* curr, long long key){

    if( !curr ) return new Node(key);
    if( key<curr->key )
        curr->left = add(curr->left,key);
    else
        curr->right = add(curr->right,key);
    return balanceNode(curr);

}
Node* findMinimal(Node* curr){
    if(curr->left) return findMinimal(curr->left);
    else return curr;
}

Node* removeMinimal(Node* curr){
    if( curr->left==0 )
        return curr->right;
    curr->left = removeMinimal(curr->left);
    return balanceNode(curr);
}

Node* pop(Node* curr, long long key){
    if( !curr ) return 0;
    if( key < curr->key )
        curr->left = pop(curr->left,key);
    else if( key > curr->key )
        curr->right = pop(curr->right,key);
    else{
        Node* currLeft = curr->left;
        Node* currRight = curr->right;
        delete curr;
        if( !currRight ) return currLeft;
        Node* minimal = findMinimal(currRight);
        minimal->right = removeMinimal(currRight);
        minimal->left = currLeft;
        return balanceNode(minimal);
    }
    return balanceNode(curr);
}

void inorder(Node* curr){
    if (curr == nullptr)
        return;
    inorder(curr->left);
    cout<<curr->key<<" ";
    inorder(curr->right);
}

int main(){
    Node* root = nullptr;
    long long N;
    cin>>N;
    for(long long i=0;i<N;i++){
        string instruction;
        cin>>instruction;
        if(instruction == "add"){
            long long x;
            cin>>x;
            if(ifExist(root, x) == true) continue;
            else
            root = add(root, x);
        }
        else if(instruction == "del"){
            long long y;
            cin>>y;
            root = pop(root, y);
        }
        else if(instruction == "inorder"){
            inorder(root);
            cout<<endl;
        }
    }

    return 0;
}
