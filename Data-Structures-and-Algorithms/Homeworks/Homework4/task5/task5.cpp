int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
  SinglyLinkedListNode* curr1 = head1;
  SinglyLinkedListNode* curr2 = head2;
    int answer = -1;
    while(curr1!=nullptr){
        while(curr2 != nullptr){
            if(curr1 == curr2) {answer = curr1->data; break;}
            else curr2 = curr2->next;
        }
        if(answer>-1) break;
        curr1 = curr1 -> next;
        curr2 = head2;
    }
    return answer;

}
