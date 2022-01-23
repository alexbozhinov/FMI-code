#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
   int data;
   Node* next;
   Node* nextMin;

   Node(int data = 0, Node* next = nullptr){
      this->data = data;
      this->next = next;
   }
};

struct Stack{

   Node* top;
   int Size;
   Node* minEl;
    long long Sum;

   Stack(Node* top = nullptr, int Size = 0, long long Sum = 0){
      this->top = top;
      this->Size = Size;
      this->Sum = Sum;
   }

   void push(int data){

      if(this->top == nullptr){
         this->top = new Node(data);
         this->minEl = this->top;
         this->Sum = data;
      }
      else{
         Node* temp = new Node(data, this->top);
         this->top = temp;
          this->Sum += data;
         if(this->top->data < this->minEl->data){
                this->top->nextMin = this->minEl;
                this->minEl = this->top;
          }
      }
      this->Size++;
   }

   void pop(){

      if(this->top == nullptr) return;

      if(this->minEl == this->top){
         this->minEl = this->minEl->nextMin;
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
      return this->minEl->data;
   }

   int minimumDays(int K){
      int currSum = 0, minimumDays = this->Size;
      int startIdx = 0, endIdx = 0;
      Node* start = this->top, *end = this->top;

      while(endIdx<this->Size){

         while(currSum <= K && endIdx < this->Size){
            currSum += end->data;
            end = end->next;
            endIdx++;
         }

         while(currSum > K && startIdx<this->Size){
            if(endIdx - startIdx < minimumDays){
                minimumDays = endIdx - startIdx;
            }
                currSum -= start->data;
                start = start->next;
                startIdx++;
         }

      }
      if(this->Sum < K) minimumDays = -1;
      return minimumDays;
   }
};

int main(){
   int N, K;
   cin>>N>>K;
   Stack S;
   for(int i=0;i<N;i++){
     int number;
     cin>>number;
     S.push(number);
   }
   cout<<S.minimumDays(K)<<endl;

}
