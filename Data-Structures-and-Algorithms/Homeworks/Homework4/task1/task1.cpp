#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{

    Node* next = nullptr;
    int data;

    Node(int data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

struct LinkedList
  {
    Node *head;
    Node *tail;

    LinkedList(){
         head = nullptr;
         tail = nullptr;
    }

     void pushBack(int number) {
        if (head == nullptr) {
            head = new Node(number);
            tail = head;
        }
        else {
            tail->next = new Node(number);
            tail = tail->next;
        }
    }


Node* reverseNodes(Node* head, int X, int Y){

    Node* prev = nullptr;
    Node* curr = head;
    Node* after = nullptr;
    Node* end = nullptr;
    Node* newHead = nullptr;
    Node* connect = nullptr;
    int counter;

    while (curr!=nullptr) {
        counter = X;
        connect = curr;
        prev = NULL;

        while (curr!=nullptr && counter!=0) {
            after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;
            counter--;
        }

        if (end!=nullptr)
            end->next = prev;
        
        if (newHead == nullptr)
            newHead = prev;

        end = connect;
        end->next = curr;
        counter = Y;

        while (curr!=nullptr && counter!=0) {
            prev = curr;
            curr = curr->next;
            counter--;
        }
        end = prev;
    }
    return newHead;
}


   void print(Node* head, int N){
       Node* curr = head;
      for(int i=0;i<N;i++){
          cout<<curr->data<<endl;
          curr = curr->next;
      }
   }

};


int main() {
    int N,X,Y;
    cin>>N;
    cin>>X;
    cin>>Y;
    LinkedList List;

    for(int i=0;i<N;i++){
        int value;
        cin>>value;
        List.pushBack(value);
    }
    List.head = List.reverseNodes(List.head,X,Y);
    List.print(List.head,N);
    return 0;
}
