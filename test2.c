#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

const uint8_t FLOAT_PRECISION = 100 ;

// range = -65536.99 ~ +65536.99 
typedef struct my_float {
        uint16_t yuan;  // 2^16 = 65536
        uint8_t fen  ;  // 256 -> 99 
        bool negative;
} my_float;

int32_t float_to_fen(my_float r){
        const int32_t fen = r.yuan * FLOAT_PRECISION + r.fen ;
        return r.negative ? -fen : fen ;
}

bool float_eq(my_float a, my_float b){
        return ( a.yuan == b.yuan && a.fen == b.fen && a.negative == b.negative );
}

bool float_ls(my_float a, my_float b){
        return float_to_fen(a)  < float_to_fen(b) ;
}

bool float_gt(my_float a, my_float b){
        return !( float_ls(a, b) || float_eq(a, b) ) ;
}

bool float_gte(my_float a, my_float b){
        return !float_ls(a, b);
}

bool float_gte(my_float a, my_float b){
        return !float_gt(a, b);
}

int main() {


}
