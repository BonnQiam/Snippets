#include<stdio.h>

// 这种利用位运算的交换方法只适用于整型变量，不能用于浮点型变量!
// swap two integers without using a temporary variable

void swap_1(unsigned int *a, unsigned int *b)
{
    printf("Before swap: a=%d, b=%d\n", *a, *b);
    
    *a=*a^*b;                     //a=a^b=0011 0001
    *b=*a^*b;                     //b=a^b=0011 1100
    *a=*a^*b;                     //a=a^b=0000 1101

    printf("After swap: a=%d, b=%d\n", *a, *b);
}

void swap_2(unsigned int *a, unsigned int *b)
{
    printf("Before swap: a=%d, b=%d\n", *a, *b);
    
    // a^=b^=a^=b;
    *a^=*b^=*a^=*b;// equivalent swap_1

    printf("After swap: a=%d, b=%d\n", *a, *b);
}

int main( )
{
    unsigned int a=60;         //0011 1100
    unsigned int b=13;         //0000 1101

    printf("Test swap_1\n");
    swap_1(&a, &b);
    printf("Test swap_2\n");
    swap_2(&a, &b);

    return 0;
}