/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//reverse the words in a sentence
// sentence a in words the reverse

#include <stdio.h>

void reverse(char *startptr, char* endptr){
    char temp;

    while(startptr<endptr){
        temp = *startptr;
        *startptr = *endptr;
        *endptr = temp;
        startptr++;
        endptr--;
    }
    
}

void reverse_words(char *ptr){
    //individual words first
    char *s = ptr;
    char *begin = ptr;
    while(*ptr){
        ptr++;
        if(*ptr == ' '){
            reverse(begin, ptr-1);
            begin = ptr+1;
        }
        else if(*ptr == '\0'){
            reverse(begin, ptr-1);
        }
    }
    reverse(s,ptr-1);
}

//one letter is one byte
int main()
{
    
    char s[] = "i like this program very much"; 
  //  char* temp = s; 
    reverse_words(s); 
    printf("%s", s); 

    return 0;
}
