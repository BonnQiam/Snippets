#include <stdio.h>

#define MAX(x,y) ((x>y)?(x):(y))
#define SWAP1(x,y) {x=x+y;y=x-y;x=x-y;}
#define SWAP2(x,y) {x=x^y;y=x^y;x=x^y;}

#define SWAP(a, b, size)    \
    unsigned int __size = (size);    \
    char *__a = (a), *__b = (b);    \
    do    \
    {    \
        char __tmp = *__a;    \
        *__a++ = *__b;    \
        *__b++ = __tmp;    \
    } while (--__size > 0);

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("Max number is:%d\n",MAX(a,b));
    printf("Before swap: x=%d,y=%d\n",a,b);
    SWAP1(a,b);
    printf("After first swap: x=%d,y=%d\n",a,b);
    SWAP2(a,b);
    printf("After second swap: x=%d,y=%d\n",a,b);
//    SWAP(a,b);
//    printf("After third swap: x=%d,y=%d\n",a,b)
    return 0;
}