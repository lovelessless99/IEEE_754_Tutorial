/*
        floating and bias
*/
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef union Float{
        float num;
        struct {
               uint32_t frac: 23 ;
               uint32_t exp : 8  ;
               uint32_t sign: 1  ; 
        };
} Float ;


char* float_format_info(Float f){
        const int max_len = 64; // 64 bits
        char *buf = calloc(max_len, sizeof(char));
        sprintf(buf, "sign : %s, exp = %x, frac = 0x%x \n",
                ~f.sign ? "+" : "-", f.exp, f.frac  ); 
        
        return buf;
} 

void dump_Float(float num)
{
        Float f = *(Float *)&num;
        printf("%f --> %s\n", num, float_format_info(f)) ;
}


void dump_float(float num){
        uint32_t ui32;

        // Method 1 : copy bit pattern
        memcpy(&ui32, &num, sizeof(num));
        printf("%f = 0x%x\n", num, ui32);

        // Method 2 : using pointer to change the type compiler seen.
        unsigned int *iptr = (unsigned int*)(&ui32);
        printf("%f = 0x%x\n", num, *iptr);
}

int main(){

        // > 1 floating 
        dump_float(3.14);
        dump_Float(9.0); // (1001)_2 = (1.001 * 2^3)_2, 0x100000 (23 bits)
                         //  exp = 3 + 127 = 130 ( Why 127 ? 8 bits --> - all are zeros or ones (special floating ) 
                         //  --> ( -126 ~ +127 ) --> add 127 ( 2^8 - 1 )
                         //  2^8 - 2 = 254 (1 ~ 254) )

}

/*

floating point 32bits 同 integer 32 bits

如果不加 bias， 在 exp 上 ， 負的較小值反而在 bit pattern上 exp 比較大
這樣不能單純把幅點數視為整數或是無號整數去比較

但加 bias後， exp 小的對應到 指數比較小的，如此一來就可以比較實彈純看作 unsigned int 
進行正負號的比較 小的福點數看起來像小的整數大的福點數看起來就是大整數 超聰明的對吧 

這也是為什麼福點數先用 符號排序 再用 指數排序 再用小數排序



*/