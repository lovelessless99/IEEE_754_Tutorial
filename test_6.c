#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

int main(){
        // 1) 普通
        // 2) 非規格化小數 (subnormal, denormal)
        // 3) + - 無窮大
        // 4) Not a numberm NAN : atof("abc")

        float nan = NAN;
        float inf = INFINITY;
        float num = 123456789;

        assert(nan != nan);


        printf("Floating point: %f\n", num);

}