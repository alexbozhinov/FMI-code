#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
   int data;
   Node* next;

   Node(int data = 0, Node* next = nullptr){
      this->data = data;
      this->next = next;
   }
};

struct Stack{

   Node* top;
   int Size;

   Stack(Node* top = nullptr, int Size = 0){
      this->top = top;
      this->Size = Size;
   }

   void push(int value){
      if(this->top == nullptr){
        this->top = new Node(value);
      }
      else{
        Node* temp = new Node(value, this->top);
        this->top = temp;
      }
      this->Size++;
   }

   void pop(){
      if(this->top == nullptr) return;
      Node* temp = this->top;
      this->top = this->top->next;
      delete temp;
      this->Size--;
      if(this->Size == 0) this->top = nullptr;
   }

   int peek(){
      return this->top->data;
   }

   void print(){
      if(this->Size == 0) {cout<<endl; return;}
      else{
        int toPrint[this->Size];
        int i=0;
        Node* curr = this->top;
        while(curr!=nullptr){
             toPrint[i] = curr->data;
             curr = curr ->next;
             i++;
        }
        for(int j=this->Size-1;j>=0;j--){
            cout<<toPrint[j]<<" ";
        }
      }
   }


};

bool isPositive(int number){
   return (number > 0);
}

int fabs(int number){
   if(number>0) return number;
   else return number*(-1);
}

void race(int A[], int N){
   Stack s;
   for(int i=0; i<N; i++){

      if(s.Size == 0 || s.peek()<0){
          if(A[i]<0){ s.push(A[i]); continue;}
      }

      if(s.Size == 0 || s.peek()>0){
          if(A[i]>0){ s.push(A[i]); continue;}
      }

      if(s.Size == 0 || s.peek()<0){
          if(A[i]>0){ s.push(A[i]); continue;}
      }

      while(s.peek() > 0 && A[i]<0){
         if(s.peek()>fabs(A[i])) break;
         else if(s.peek() == fabs(A[i])){
            s.pop(); break;
         }
         else if(s.peek()<fabs(A[i])){
            s.pop();
            if(s.Size == 0 || s.peek()<0){s.push(A[i]); break;}
            else continue;
         }
      }

      }
         s.print();

   }




int main(){

int N;
cin>>N;
int A[N];

for(int i=0;i<N;i++){
   cin>>A[i];
}
race(A,N);
}
