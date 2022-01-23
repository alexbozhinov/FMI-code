SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    SinglyLinkedListNode* temp = new SinglyLinkedListNode(0);
    SinglyLinkedListNode* head = temp;
    SinglyLinkedListNode* curr1 = head1;
    SinglyLinkedListNode* curr2 = head2;
    
    while(curr1!=nullptr && curr2!=nullptr ){
        if(curr1 -> data < curr2 -> data){
            temp ->next = curr1;
            curr1 = curr1 -> next;
        }
        else{
            temp -> next = curr2;
            curr2 = curr2 -> next;
        }
        temp = temp->next;
    }
    if(curr1!= nullptr){
        temp->next = curr1;
        curr1 = curr1->next;
    }
    else{
        temp -> next = curr2;
        curr2 = curr2 -> next;
    }
    return head -> next;

}
