/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//implement a queue with push/pop functionality using linked lists
//queue is a linked list

#include <stdio.h>
#include <limits.h>


struct Queue{
  int val;
  struct Queue *next;
};

typedef struct Queue queue;


//push item onto the queue. push it at the back of the queue cause fifo structure
queue* push_item(int num, queue *head){
    if(head==NULL){
        queue *new = (queue*)malloc(sizeof(queue));
        head = new;
        head->val = num;
        head->next = head;
        return head;
    }
    
    else{
        queue *temp = head;
        while(temp->next!=head){
            temp=temp->next;
        }
        queue *new = (queue*)malloc(sizeof(queue));
        temp->next = new;
        temp->next->val = num;
        temp->next->next = head;
        return head;
    }
}


//delete item using value
queue* delete_item(queue *head, int val){
    if(head==NULL){
        return NULL;
    }
    
    
    if(head->val == val){
        if(head->next == head){
            head = NULL;
            return NULL;
        }
        
        queue *tem = head;
        while(tem->next != head){
            tem = tem->next;
        }
        tem->next = tem->next->next;
        tem = head;
        head = head->next;
        free(tem);
        tem = NULL;
        return head;
    }
    
    else{
            queue *new = head;
            
            while(new->next->val != val){
                new = new->next;
            }
            
            queue *temp = new -> next;
            new->next = new->next->next;
            free(temp);
            new=NULL;
            return head;
        }
}
    

//delete item using only pointer to the node
queue* delete_item_node(queue *node){
    queue *temp = node;
    
    if(temp->next == temp){
        return NULL;
    }
    
    while(temp->next != node){
        temp = temp->next;
    }
    
    temp->next = temp->next->next;
    free(node);
    node=NULL;
    return temp;
}
    


void print_items(queue *head){
    if(!head){
        return;
    }
    
    queue *temp = head;
    printf("%d\t",temp->val);
    
    temp = temp->next;
    
    while(temp != head){
        printf("%d\t",temp->val);
        temp=temp->next;
    }
}

int main(){

    //test code
    
    queue *test = NULL;
    test = push_item(5, test);
    test = push_item(6, test);
    test = push_item(7, test);
    // test = push_item(7, test);
    // test = push_item(4, test);
    
   // int value = pop_item(test);
    
  //  printf("value popped %d", value);
    print_items(test);
    printf("\n");
  
    queue *node;
    node = test -> next;

    test = delete_item_node(node);
    
    // node = test -> next;

    // test = delete_item_node(node);
  
  
    // node = test;

    // test = delete_item_node(node);
  
    
    // test = push_item(10, test);
    // test = push_item(2, test);
    

    print_items(test);
    return 0;
}