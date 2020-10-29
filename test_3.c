#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>


//  if struct field have different types, it will check the original type rather than the bitfield hints  
//  

typedef struct Format {
                uint32_t frac : 23 ;   // 4 bytes
                uint8_t expo  : 8  ;   // 1 byte
                bool sign     : 1  ;   // 1 byte 
                                       // padding 2 bytes
} Format;

typedef union __attribute__((__packed__)) Float1 {
        float num;
        struct __attribute__((__packed__)) {
                uint32_t frac : 23;   // 4 bytes
                uint8_t expo  : 8 ;   // 1 byte
                bool sign     : 1 ;   // 1 byte 
        };
} Float1; // max bytes 



typedef union __attribute__((__packed__)) Float2 {
        float num;
        struct  {
                uint32_t frac : 23; // 4 bytes
                uint8_t expo : 8;   // 1 byte
                bool sign : 1;   // 1 byte 
        };
} Float2;

typedef union  Float3 {
        float num;
        struct __attribute__((__packed__)) {
                uint32_t frac : 23; // 4 bytes
                uint8_t expo : 8;   // 1 byte
                bool sign : 1;   // 1 byte 
        };
} Float3;


typedef union Float4 {
        float num;
        struct {
                uint32_t frac : 23;  // 4 bytes
                uint32_t expo : 8;   // 1 byte
                uint32_t sign : 1;   // 1 byte 
        };
} Float4;

typedef union  Float5 {
        float num;
        struct __attribute__((__packed__)){
                uint32_t frac : 23; // 4 bytes
                uint8_t expo : 8;   // 1 byte
                uint8_t sign : 1;   // 1 byte 
        };
} Float5;

// <Question> 
// why typedef union Float {
//         float num;
//         struct {
//                 uint32_t frac : 23;
//                 uint8_t expo : 8;
//                 bool sign : 1;
//         };
// } Float;

// is 64 bits;

int main(){
        // Float my_float;
        // my_float.num = 65.65625;

        printf("booling size : %d\n", sizeof(bool) );
        printf("uint_8 size : %d\n", sizeof(uint8_t) );
        printf("Format size : %d\n", sizeof(Format) );
        printf("floating points 1 size : %d\n", sizeof(Float1) );
        printf("floating points 2 size : %d\n", sizeof(Float2) );
        printf("floating points 3 size : %d\n", sizeof(Float3) );
        printf("floating points 4 size : %d\n", sizeof(Float4) );
        printf("floating points 5 size : %d\n", sizeof(Float5) );


        // printf("floating number : %x\n", my_float.num);
        // printf("sign: %d, expo: %d, frac: %x\n", my_float.sign, my_float.expo, my_float.frac);
}




