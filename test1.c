#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int feq(float a, float b){
        return fabs(a-b) < __FLT_EPSILON__;
}

void float_precison_case_1(){
        float a = 0.1;
        float b = 0.2;
        float c = a + b;
        printf("c = %.8f\n", c);
        if ( c == 0.3 ){
                printf("Never enter this branch!\n");
        }
        else{
                printf("Why 0.1 + 0.2 != 0.3?\n");        
        }
}

void float_limit_case1()
{
        double uid = atof("12345677777778888899999");
        printf("user ID = %.01f\n", uid);
}

void float_format()
{
        float total = 100;
        float failed = 29;
        float failed_percent = failed / total; 
        printf("Total : %.0f, Failed : %.0f , Failed percent = %.9f\n", total, failed, failed_percent);
}

int main()
{
        float_precison_case_1();
        float_limit_case1();
        float_format();
}