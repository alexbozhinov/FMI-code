
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
   SinglyLinkedListNode* curr = head;
   SinglyLinkedListNode* prev = nullptr;
   SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
   
   if(position == 0){
       head = newNode;
   }
   for(int i=0; i<position; i++){
       prev = curr;
       curr = curr -> next;
   }
   prev -> next = newNode;
    newNode -> next = curr;
   //delete curr;
   return head;

}
