#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;

struct Point{
int x;
int y;
int value;
Point(int x=0, int y=0, int value = 0){
   this->x = x;
   this->y = y;
   this->value = value;
}
};

struct Node{
    Node *left;
    Node *right;
    Point point;
    Node(Point _point){
        this->point = _point;
        this->left = nullptr;
        this->right = nullptr;
    }
};

struct BST{
    Node* root;

    Node* add(Node *curNode, Point point){
        if(curNode == nullptr){
            return new Node(point);
        }
        if(curNode->point.x < point.x){
            curNode->right = add(curNode->right, point);
        }
        else if(curNode->point.x>point.x){
            curNode->left = add(curNode->left, point);
        }
        return curNode;
    }
    BST(){
        this->root = nullptr;
    }
    void add(Point point){
        if(root == nullptr){
            root = new Node(point);
        }
        else{
            add(root, point);
        }
    }

void DFS(Node* root){
   if(!root) return;
   DFS(root->left);
   cout<<root->point.value<<" ";
   DFS(root->right);
}


};


int main() {
    int N;
    cin>>N;
    Point points[N];
    points[0]=Point(0,0);
    for(int i=0;i<N;i++){
        int right, left;
        cin>>left>>right;
        if(left!=-1){
                points[left].x = points[i].x-1;
                points[left].y = points[i].y-1;
                points[left].value = left;
        }
        if(right!=-1){
                points[right].x = points[i].x+1;
                points[right].y = points[i].y-1;
                points[right].value = right;
        }
    }
    BST t;
    for(int i=0;i<N;i++){
        t.add(points[i]);
    }

    t.DFS(t.root);
    return 0;
}
