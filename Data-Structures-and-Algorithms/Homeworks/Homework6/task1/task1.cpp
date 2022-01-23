#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node{
    Node *left;
    Node *right;
    int data;
    Node(int _data){
        this->data = _data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BST{

private:
    Node* root;

    Node* add(Node *curNode, int data){
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

    Node* Remove(Node* curNode, int data){
        if(curNode == nullptr){
            return nullptr;
        }
        if(curNode->data < data){
            curNode->right = Remove(curNode->right, data);
        }
        else if(curNode->data > data){
            curNode->left = Remove(curNode->left, data);
        }
        else{
            if(curNode->left == nullptr){
                Node* temp = curNode->right;
                delete curNode;
                return temp;
            }
            Node* minInRightSubTree = findMin(curNode->right);
            curNode->data = minInRightSubTree->data;
            curNode->right = Remove(curNode->right, curNode->data);
        }
        return curNode;
    }

    Node* findMin(Node *root){
        if(root->left != nullptr){
            return findMin(root->left);
        }
        return root;
    }

public:
    BST(){
        root = nullptr;
    }

    Node* getRoot(){
       return this->root;
    }

    void add(int data){
        if(root == nullptr){
            root = new Node(data);
        }
        else{
            add(root, data);
        }
    }

    void Remove(int data){
        root = Remove(root, data);
    }

    void printKLR(Node* root){
       queue<Node* >q;
       q.push(root);
       while(! q.empty()){
           Node* t = q.front();
           cout<<t->data<<" ";
           if(t->left){
               q.push(t->left);
           }
           if(t->right){
               q.push(t->right);
           }
           q.pop();
       }

    }

    int kLargest(Node* root, int K){
    Node* curr = root;
    Node* largest = nullptr;

    int counter = 0;

    while(curr != nullptr){
    
        if(curr->right == nullptr){
            counter++;
            
            if (counter == K){
                largest = curr;
            }
            curr = curr->left;
        }
        else{

            Node* inheritor = curr->right;

            while(inheritor->left != nullptr && inheritor->left != curr){
                inheritor = inheritor->left;
            }    

            if(inheritor->left == nullptr){                
                inheritor->left = curr;
                curr = curr->right;
            }
            else{

                inheritor->left = nullptr;
                counter++;
                if(counter == K){
                    largest = curr;
                }
                curr = curr->left;
            }
        }
    }
    return largest->data;
}

};

int main() {
    int N, K;
    BST t;
    cin>>N>>K;
    for(int i=0;i<N;i++){
        int number;
        cin>>number;
        t.add(number);
    }
    t.Remove(t.kLargest(t.getRoot(), K));
    t.printKLR(t.getRoot());

    return 0;
