#include<string>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



struct Node{

    Node* next = nullptr;
    Node* previous = nullptr;
    long long data;

    Node(long long data, Node* next = nullptr, Node* previous = nullptr) {
        this->data = data;
        this->next = next;
        this->previous = previous;
    }
};

struct LinkedList{

Node *head;
Node *middle;
Node *tail;

LinkedList(){
    head = nullptr;
    middle = nullptr;
    tail = nullptr;
}


void pushBack(long long number){
    Node* newElement = new Node(number);

    if (head == nullptr)
        head = newElement;

    if (tail != nullptr)
        tail->next = newElement;

    newElement->next = nullptr;
    newElement->previous = tail;
    tail = newElement;
}

void popBack(){
    Node* temp;
    temp = tail;
    tail = tail->previous;
    temp->previous = nullptr;
    tail->next = nullptr;
    //delete temp;
}
/*
void popFront(){
  Node* temp;
  temp = head;
  head = head->next;
  temp->next = nullptr;
  head->previous = nullptr;
  //delete temp;
}
*/
void milenCaught(long long Size){

  Node* temp;
  Node* newTail;

  temp = middle->next;
  tail->next = head;
  head->previous = tail;
  middle -> next = nullptr;
  temp->previous = nullptr;
  head = temp;
  newTail = middle;
  if(Size%2==0) middle = tail;
  else middle = tail->previous;
  tail = newTail;
}

 void print(Node* head){
      Node* curr = head;
      while(curr!=nullptr){
          cout<<curr->data<<" ";
          curr = curr->next;
      }
   }

};


int main() {
   long long  N, Size = 0;
   cin>>N;
   LinkedList List;

   for(long long i=0;i<N;i++){
       string command;
       cin>>command;

       if(command == "add") {
         long long x;  cin>>x; List.pushBack(x);Size++;
         if(Size<=3) List.middle = List.head;
         else if(Size%2 == 0) List.middle = List.middle->next;
       }

       if(command == "gun" && Size > 0) {
              if(Size == 1) {
                    List.head = nullptr; List.middle = nullptr; List.tail = nullptr;
                    Size--;
                    //if(Size<=3) List.middle = List.head;
                    //else if(Size%2!=0) List.middle = List.middle->previous;
              }
              else  {
                    List.popBack();
                    Size--;
                    if(Size<=3) List.middle = List.head;
                    else if(Size%2!=0) List.middle = List.middle->previous;

                    }
        }

       if(command == "milen" && Size>1 && List.head && List.middle && List.tail) {
             List.milenCaught(Size);
       }
   }
   cout<<Size<<endl;
   List.print(List.head);

}
