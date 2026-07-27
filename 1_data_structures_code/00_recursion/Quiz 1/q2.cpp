#include <stdio.h>

void foo (int n, int sum)
{
    int k = 0, j = 0;
    if (n == 0) return;
    k = n % 10;
    j = n/10;
    sum = sum + k;
    foo (j, sum);
    printf("%d", k);
}

/*
foo(0, 14)

k = 2, j = 0, sum = 14
k = 0, j = 0, sum = 12
foo(2, 12)

k = 0, j = 2, sum = 12
k = 0, j = 0, sum = 12
foo(20, 12)

k = 4, j = 20, sum = 12 
k = 0, j = 0, sum = 8
foo(204, 8)

k = 8, j = 204, sum = 8
k = 0, j = 0, sum = 0
foo(2048, 0)
*/

int main ()
{
    int a = 2048, sum = 0;
    foo (a, sum); // 2048
    printf("%d\n", sum); // 0
}