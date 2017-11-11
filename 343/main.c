#include<stdio.h>
#include<stdlib.h>

int *memo = NULL;
int max(int a, int b, int c)
{
    int res = a>b?a:b;
    res = c>res?c:res;
    return(res);
}
int __integerBreak(int n)
{
    if (n<=1)
    {
        return(1);
    }
    if (memo[n] != -1)
        return  memo[n];
    
    int res = -1;
    for(int i=1; i<n; i++)
    {
        res = max(res, i*__integerBreak(n-i), i*(n-i));
    }

    memo[n]=res;

    return(res);
}

int integerBreak(int n)
{
    memo = malloc((n+1)*sizeof(int));
    for(int i=0; i<n+1; i++)
    {
        memo[i]=-1;
    }

    return(__integerBreak(n));
}

int main(int argc, char **argv)
{
    int n = 0;
    printf("n:");
    scanf("%d", &n);

    printf("%d\n", integerBreak(n));
}


