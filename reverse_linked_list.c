//reverse_list    
//4 -> 5 -> 6
//6 -> 5 -> 4

queue* reverse_list(queue *head){
    if (head == NULL || head -> next == NULL){
        return NULL;
    }
    
    queue *prev = NULL;
    queue *curr = head;
    queue *next = NULL;

    
    while(curr != NULL){
        next = curr-> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    
    head = prev;
    return head;
}

