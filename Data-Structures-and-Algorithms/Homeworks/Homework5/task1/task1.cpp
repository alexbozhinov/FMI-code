#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
   int data;
   Node* next;
   Node* prevMinimal;

   Node(int data = 0, Node* next = nullptr){
      this->data = data;
      this->next = next;
   }
};

struct Stack{

   Node* top;
   int Size;
   Node* minimal;

   Stack(Node* top = nullptr, int Size = 0){
      this->top = top;
      this->Size = Size;
   }

   void push(int data){

      if(this->top == nullptr){
         this->top = new Node(data);
         this->minimal = this->top;
      }
      else{
         Node* temp = new Node(data, this->top);
         this->top = temp;
         if(this->top->data < this->minimal->data){
                this->top->prevMinimal = this->minimal;
                this->minimal = this->top;
          }
      }
      this->Size++;
   }

   void pop(){

      if(this->top == nullptr) return;

      if(this->minimal == this->top){
         this->minimal = this->minimal->prevMinimal;
      }
       
      Node* temp = this->top;
      this->top = this->top->next;
      delete temp;
      this->Size--;
      if(this->Size == 0) this->top = nullptr;
   }

   int peek(){
      return this->top->data;
   }

   int minElement(){
      return this->minimal->data;
   }

};


int main() {

   int N;
   cin>>N;
   Stack S;

   for(int i=0;i<N;i++){
       string querry;
       cin>>querry;

       if(querry == "push"){
           int X;
           cin>>X;
           S.push(X);
       }
       else if(querry == "pop"){
           S.pop();
       }
       else if(querry == "peek"){
           cout<<S.peek()<<endl;
       }
       else if(querry == "min"){
           cout<<S.minElement()<<endl;
       }
   }


    return 0;
}
