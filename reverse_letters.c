/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//reverse the letters in a word

#include <stdio.h>

char* reverse_words(char *ptr, int size){
    char *new = ptr + size - 1;
    
   // printf("new %c", new);
    
    char *temp = (char*)malloc(size);
    char *head = temp;
   // char *temp = res;
    
    while(new>=ptr){
        *temp = *new;
         temp++;
         new--;
    }
    //printf("head %c", *head);
    return head;
}

//one letter is one byte
int main()
{
    char test[100] = "hi i am yashasvi";
   
    //printf("%d", sizeof(test));

    char *out = reverse_words(test,100);
    
    for(int i=0; i<=100; i++){
        printf("%c",out[i]);
    }
//    printf("output %c", *out);
    
    return 0;
}
