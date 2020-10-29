#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


#define SIGN_BIT_SIZE     1
#define EXPONENT_BIT_SIZE 8
#define FRACTION_BIT_SIZE 23



void dump_float(float *num){
        uint32_t bits;
        memcpy(&bits, num, sizeof(float));
        printf("%f 0x%x\n", *num, bits);
} 

// little endian, prevent from alignment 

// to do : big endian   ? reorder the property --> change the result ?  
// to do : no alignment ? 
// Analyze if using big-endian 

// 32----------------------------------------------------------------0                  
// | <- 1 bit: sign -> | <- 8 bits: exp -> | <- 23 bits: fraction -> |  
// 32----------------------------------------------------------------0

// floating bit pattern : 0x12345678
//            big-endian                 little-endian
// low mem       0x12                 0x78 (fraction       )      
//  |            0x34                 0x56 (fraction       )
//  |            0x56                 0x34 (exp , fraction )
// high mem      0x78                 0x12 (sign, exp      )

// how to know big or little endian ? ( union )
// how to convert a int to a byte array ? ( union )
// how to use union to seperate a float to three part of format ? 

typedef struct __attribute__((__packed__)) Float {
    unsigned int fraction : FRACTION_BIT_SIZE;
    unsigned int exponent : EXPONENT_BIT_SIZE;
    unsigned int sign     : SIGN_BIT_SIZE; 
} Float; 
// low ---> high : // little endian 

int main()
{
        Float f1 = { .fraction = 1 << 22, .exponent = 0 + 127 };

        // little endian
        // 0 01111111 1000000000000000 --> 0x3fc00000
        // 1000000000000000 01111111 0 --> 0x800000fe (reverse property order)
        
        // big endian
        // 1000000000000000 01111111 0 --> 0x800000fe (original pattern)
        // 0 01111111 1000000000000000 --> 0x3fc00000 (reverse property order)

        // if change the order of property. 
        // it will be change, you need to check it 
        
        dump_float(&f1);
        
        float f2 = 1.5;
        dump_float(&f2);

        float f3 = *(float*)(&f1) + f2;
        dump_float(&f3);
        
        // 1.00
        Float f4 = { .fraction = 1, .exponent = 0 + 127 };
        dump_float(&f4);

        // 1.25
        Float f5 = { .fraction = 1 << 21, .exponent = 0 + 127 };
        dump_float(&f5);
        
        // 1.125
        Float f6 = { .fraction = 1 << 20, .exponent = 0 + 127 };
        dump_float(&f6);

        // 0.125
        Float f7 = { .fraction = 0, .exponent = -3 + 127 };
        dump_float(&f7);


        return 0;
}       