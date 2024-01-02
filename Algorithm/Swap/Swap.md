#Snippet 

> 将两个变量的值进行交换是很常见的操作，下面提供两种实现方式

# Swap_v1

`swap_v1.c`:用 `#define` 宏定义将 `a`,`b`交换，不使用中间变量，两种方法实现`swap(x,y)`;

```c
#include <stdio.h>
#define MAX(x,y) ((x>y)?(x):(y))
#define SWAP1(x,y) {x=x+y;y=x-y;x=x-y;}
#define SWAP2(x,y) {x=x^y;y=x^y;x=x^y;}

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("Max number is:%d\n",MAX(a,b));
    printf("交换前：x=%d,y=%d\n",a,b);
    SWAP1(a,b);
    printf("交换后：x=%d,y=%d\n",a,b);
    SWAP2(a,b);
    printf("再次交换后：x=%d,y=%d\n",a,b);
    return 0;
}

/*
输出结果为：
2 4
Max number is:4
交换前：x=2,y=4
交换后：x=4,y=2
再次交换后：x=2,y=4
*/
```

PS. 有人指出不建议使用异或运算实现 swap，具体可参看链接：[C 关于使用异或运算交换两数的值](https://www.runoob.com/w3cnote/c-swap-data.html)

# Swap_v2

> 参考：https://www.zhihu.com/question/533549823

```c
// 使用 `do { /*...*/ } while(0)` 将多行语句包裹成单个语句
// a, b 要转换为 char * 类型
#define SWAP(a, b, size)    \
    unsigned int __size = (size);    \
    char *__a = (a), *__b = (b);    \
    do    \
    {    \
        char __tmp = *__a;    \
        *__a++ = *__b;    \
        *__b++ = __tmp;    \
    } while (--__size > 0);
```