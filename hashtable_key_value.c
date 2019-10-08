// hashtable data structure simple with key and value pair
#define SIZE 1000000

struct hashmap {
    int key;
    int val;
};

typedef struct hashmap MyHashMap;

/** Initialize your data structure here. */

MyHashMap* myHashMapCreate() {
    MyHashMap* new = (MyHashMap*)calloc(1,sizeof(MyHashMap)*SIZE);
    
    for(int i=0; i<SIZE; i++){
        new[i].key = -1;
        new[i].val = -1;
    }
    
    return new;
}

/** value will always be non-negative. */
//this is the hash function
void myHashMapPut(MyHashMap* obj, int key, int value) {
    //key is used as the index
    obj[key].key = key;
    obj[key].val = value;
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap* obj, int key) {
    return obj[key].val;
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) {
  if(obj[key].key!= -1){
      obj[key].key = -1;
      obj[key].val = -1;
    }
}

void myHashMapFree(MyHashMap* obj) {
    free(obj);
    obj = NULL;
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/