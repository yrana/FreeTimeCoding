// Write a C program to encode bits in a 32-bit number such that,
// most significant 16 bits should be reversed but lower 16 bits should 
// be untouched. Then asked to generalize this to any number of bits in the 
// file reverse_upper_bits.c


//32 bits
// 0000 1111 1110 1010 1001 1010 0000 1011
// 0101 0111 1111 0000 1001 1010 0000 1011

//algorithm
// mask with 0xFFFF to get the lower 16 bits
// shift right by 16 bits
// reverse the remaning bits and store in a new var
// shift bits left by 16 bits
// or with the lower bits

#include <stdint.h>

uint32_t reverse_upper(uint32_t num){
    uint32_t mask = 0x0000FFFF;
    
    uint32_t lower = num & mask;
    
    num = num >> 16;
    
    uint32_t res = 0;
    
    for(int i =0; i<16; i++){
        res = res | (num&0x1);
        if(i==15){
            break;
        }
        res = res << 1;
        num = num >> 1;
    }
    printf("print res %d",res);
    res = res << 16;
    res = res | lower;
    
    return res;
}


int main(){
    uint32_t num = 0x0FEA9A0B;
    
    uint32_t out = reverse_upper(num);
  
    printf("Output %d", out);
    
    return 0;
}