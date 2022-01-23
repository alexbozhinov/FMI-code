#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct Node{
   int data;
   Node* next;
   Node* prev;

   Node(int data = 0, Node* next = nullptr, Node* prev = nullptr){
      this->data = data;
      this->next = next;
      this->prev = prev;
   }
};

struct myDeque{
   Node* Front;
   Node* End;
   int Size;

   myDeque(int Size = 0, Node* Front = nullptr, Node* End = nullptr){
      this->Front = Front;
      this->End = End;
      this->Size = Size;
   }

   bool isEmpty(){
       return (this->Front == nullptr);
   }

   int getFront(){
      if(this->isEmpty()){
         return -1;
      }
      return this->Front->data;
   }

   int getEnd(){
      if(this->isEmpty()){
         return -1;
      }
      return this->End->data;
   }

   void pushBack(int data){
        Node* temp = new Node(data);
        if(temp == nullptr) return;

        if(this->End == nullptr){
            this->Front = temp;
            this->End = temp;
        }

        else{
            temp->prev = this->End;
            this->End->next = temp;
            this->End = temp;
        }
        this->Size++;
   }

   void popBack(){
      if(this->isEmpty()) return;

      Node* toPop = this->End;
      this->End = this->End->prev;

      if(this->End == nullptr){
         this->Front = nullptr;
      }

      else{
         this->End->next = nullptr;
      }
      delete toPop;
      this->Size--;
   }

   void popFront(){
      if(this->isEmpty()) return;

      Node* toPop = this->Front;
      this->Front = this->Front->next;

      if(this->Front == nullptr){
         this->End = nullptr;
      }
      else{
         this->Front->prev = nullptr;
      }
      delete toPop;
      this->Size--;

   }

};

void sumOfMinElements(int A[], int N, int d){
   myDeque Deq(d);
   long long int idx = 0, sum = 0;
   if(N == 0 || d == 0 || d>N){ cout<<sum<<endl; return;}

   for(int i=0;i<d;i++){

       while( !(Deq.isEmpty())&& A[i]<= A[Deq.getEnd()]){
            Deq.popBack();
       }
       Deq.pushBack(i);
       idx = i;
   }
   for(int j=idx+1;j<N;j++){

       sum += A[Deq.getFront()];

       while( !Deq.isEmpty() && Deq.getFront()<= j-d){
           Deq.popFront();
       }
       while( !Deq.isEmpty() && A[j] <= A[Deq.getEnd()]){
           Deq.popBack();
       }
       Deq.pushBack(j);
   }
   sum += A[Deq.getFront()];
   cout<<sum<<endl;
}


int main() {
    int N, d;
    cin>>N>>d;
    int A[N];
    for(int i=0;i<N;i++) cin>>A[i];
    sumOfMinElements(A,N,d);
    return 0;
}
