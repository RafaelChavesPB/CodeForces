#include <stdio.h>
int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a < b && b < c)
    {
        printf("0\n");
    }
    else if ((a < b && a < c) || (c > a && c > b))
    {
        printf("1\n");
    }
    else if (a > b && b > c)
    {
        printf("3\n");
    }
    else
    {
        printf("2\n");
    }
}