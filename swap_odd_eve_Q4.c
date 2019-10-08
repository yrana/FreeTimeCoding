//swap adjacent odd and even bits

#include <stdint.h>

uint32_t swap(uint32_t num){
    uint32_t odd = num & 0x55555555;
    uint32_t even = num & 0xAAAAAAAA;
    

    uint32_t res = (odd << 1) | (even >> 1);
    return res;
}

int main(){
    uint32_t res = 0x111;
    uint32_t out = swap(res);
    
    printf("result %d", out);
}