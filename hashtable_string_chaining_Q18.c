//string hashing with separate chaining
// each string is 4 letters long


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


#define SIZE 1000


struct hashmap {
  //  int key; key not used
    char val[4];
    struct hashmap* next;
};

typedef struct hashmap MyHashMap;

/** Initialize your data structure here. */

MyHashMap* myHashMapCreate() {
    MyHashMap* new = (MyHashMap*)malloc(sizeof(MyHashMap)*SIZE);
    
    for(int i=0; i<SIZE; i++){
        new[i].val[0] = '\0'; //to give a signal that its not mapped
      
        new[i].next = NULL;
    }
    
    return new;
}

int hashFunction(char *string){
    int ind = 0;
    
    for(int i=0; string[i]!='\0'; i++){
        ind += (int) string[i];
    }
    
    return ind;
}

/** value will always be non-negative. */
void myHashMapPut(MyHashMap* obj, char *str) {
    int index = hashFunction(str);
   
   if (obj[index].val[0] != '\0'){
       MyHashMap *map = (MyHashMap*)malloc(sizeof(MyHashMap));
       obj[index].next = map;
       map->next = NULL;
       for(int i=0; str[i]!='\0'; i++){
            map->val[i] = str[i];
    }
   }
   else{
       for(int i=0; str[i]!='\0'; i++){
        obj[index].val[i] = str[i];
    }
   }
   
   

}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
char* myHashMapGet(MyHashMap* obj, char *str) {
    int index = hashFunction(str);
    MyHashMap *temp = obj+index;
    
    int word_found = 0;
    while(temp != NULL && word_found==0){
        for(int i=0; str[i]!='\0'; i++){
            if (obj[index].val[i] != str[i]){
                temp = temp->next;
                break;
            }
            word_found = 1;
        }
      
    }
    return temp -> val;
}

//not implemented
/** Removes the mapping of the specified value key if this map contains a mapping for the key */
// void myHashMapRemove(MyHashMap* obj, char *str) {

// }

void myHashMapFree(MyHashMap* obj) {
    free(obj);
    obj = NULL;
}


int main(){
    MyHashMap *new = myHashMapCreate();
    char str1[] = "test";
    
    char str2[] = "tste";
    
    myHashMapPut(new, str1);
    myHashMapPut(new, str2);
    
    char *param_1 = myHashMapGet(new, str1);
    char *param_2 = myHashMapGet(new, str2);
    
    for(int i=0; param_1[i]!='\0'; i++){
        printf("%c", param_1[i]);
    }
    
     printf("\n");
    
    for(int i=0; param_2[i]!='\0'; i++){
        printf("%c", param_2[i]);
    }
    

    myHashMapFree(new);
    
    return 0;
}
