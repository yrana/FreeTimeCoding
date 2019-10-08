/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//implement a queue with push/pop functionality using linked lists
//queue is a linked list

#include <stdio.h>
#include <limits.h>
#include <string.h>


// s2 is the substring
// s1 is the main string to be searched for s2
// if not found, returns NULL


//GeefksfoGeeks; 
//"for";
    
//while loop implementation: uses less variables
char* mystrstr(const char *str1, const char *str2){
    int j=0;
    char* ret;
    int found=1;
    
    while(*str1){
        char *s1 = str1;
        char *s2 = str2;
        
        while(*str1 && *s2 && *str1==*s2){
            str1++;
            s2++;
        }
        
        if(!*s2){
            return s1;
        }
        str1 = s1+1;
    }
    return NULL;
}

// my implementation for loop	
/* char* mystrstr(const char *s1, const char *s2){
    int j=0;
    char* ret;
    int found=1;

    for(int i=0; s1[i]!='\0'; i++){ 
        if (s2[j]==s1[i] && found==1){
            if(j==0){
                ret = (s1)+i;
            }
            
            j++;
        }
        else if (s2[j]=='\0'){
            return ret;
        }
        else if (j!=0){
            found = 0;
            j=0;
        }
        else{
            found=1;
        }
    }
    
    return NULL;
}
 */
int main(){
    char s1[] = "GeefksforGeeks"; 
    char s2[] = "fors"; 
    char* p; 
  
    // Find first occurence of s2 in s1 
    p = mystrstr(s1, s2); 
  
    // Prints the result 

   
    if (p) { 
        printf("String found\n"); 
        printf("First occurrence of string '%s' in '%s' is '%s'", s2, s1, p); 
    } else
        printf("String not found\n"); 
    

    return 0;
}