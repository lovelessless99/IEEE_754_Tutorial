#include <stdio.h>

int main()
{
        float fval = 12.34f;
        int *iptr = (int *) &fval;


        double db_num_p = 0.0;
        double db_num_n = -0.0;
        
        printf("positive : %8x, negative: %8x\n", db_num_p, db_num_n);
        
        if (db_num_p == db_num_n) { printf("p == n\n"); }
        else { printf("p!=n\n"); }

        // type conversion
        // let compiler can treat the pointer with another way.
        // so move pointer will change the move step. 

        printf("%f -> 0x%08x\n", fval, fval);
        printf("%f -> 0x%08x\n", fval, *iptr);
        printf("%f -> 0x%08x\n", fval, fval);

        fval = 1 / 0.0f;
        printf("%f -> 0x%08x\n", fval, *iptr);
        // output: inf -> 0x7f800000
        
        fval = 0 / 0.0f;
        printf("%f -> 0x%08x\n", fval, *iptr);
        // output: -nan -> 0xffc00000
}