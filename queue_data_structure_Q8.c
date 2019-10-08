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
        head->next = NULL;
        return head;
    }
    
    else{
        queue *temp = head;
        while(head->next!=NULL){
            head=head->next;
        }
        queue *new = (queue*)malloc(sizeof(queue));
        head->next = new;
        head->next->val = num;
        head->next->next = NULL;
        return temp;
    }
}

queue* pop_item(queue *head){
    if(head==NULL){
        return NULL;
    }
    else{
            queue *new = head;
            head = head -> next;
            new -> next = NULL;
            //int ret = new -> val;
            free(new);
            new = NULL;
            //return ret;
            return head;
        }
}
    



void print_items(queue *head){
    while(head){
        printf("%d\t",head->val);
        head=head->next;
    }
}

int main(){

    //test code
    
    queue *test = NULL;
    test = push_item(5, test);
    test = push_item(6, test);
    test = push_item(7, test);
    test = push_item(4, test);
    
   // int value = pop_item(test);
    
  //  printf("value popped %d", value);
  
    test = pop_item(test);
    test = pop_item(test);
    
    test = push_item(10, test);
    test = push_item(2, test);
    

    print_items(test);
    return 0;
}