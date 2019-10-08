/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//find first non recurring character in a string
//algorithm:
//traverse through a string once and store these values in hashmap: index, count
//traverse through hashmap in order to get the character with a count of 1 



#include <stdio.h>
#include <limits.h>

#define SIZE 256

struct hashtable{
    int count;
    int index;
};

typedef struct hashtable hashtable_t;


int find_char_index(char *ptr){
    hashtable_t *dict = (hashtable_t*)calloc(1, sizeof(hashtable_t)*SIZE);

    
    //store values in the hashtable. hashtable is 256 units corresponding to 256 ascii characters
    for(int i=0; ptr[i]!='\0'; i++){
        dict[ptr[i]].count++; // ptr[i] is a character, but when put in [], it becomes an integer representing ascii value
        dict[ptr[i]].index = i;
        
    }
    
    int val = INT_MAX;
    
	// traverse through struct and find the lowest index with count of 1
    for(int j =0; j<SIZE; j++){
        if (dict[j].count == 1){
            if (dict[j].index < val){
                val = dict[j].index;
            }
        }
    }
    
    if(val==INT_MAX){
        return -1;
    }
    
    return val;

}


int main()
{
    char words[] = "abdaeebjodi";
    int ind = find_char_index(words);
    

    if (ind == -1){
        printf("");
    }
    else{
        printf("first non recurring character: %c", words[ind]);
    }

    

    return 0;
}
