
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    
    SinglyLinkedListNode *curr = head;
    SinglyLinkedListNode *prev = nullptr;
    
        if (position == 0) {    
               if(head!=nullptr){
                    head=head->next;
                }
            return head;         
        }

        for (int i = 0; i < position; i++) {
            if (curr->next != nullptr) {
                prev = curr;
                curr = curr->next;
            }
        }
        prev->next = curr->next;

        delete curr;
        return head;
}
