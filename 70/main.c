#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#if 0
long  climbing_stairs(int n)
{
    if (n==0 || n == 1)
    {
        return(1);
    }
    return (climbing_stairs(n-1)+climbing_stairs(n-2));
}
#elif 0
long  climbing_stairs(int n, long *memo)
{ 
    //printf("n = %d", n);

    if (n==0 || n == 1)
    {
        return(1);
    }

    if (memo[n] == -1)
    {
        memo[n]=climbing_stairs(n-1, memo)+climbing_stairs(n-2, memo);
    }

    return (memo[n]);
}
#else
long climbing_stairs(int n)
{
    long  *memo = malloc((n+1)*sizeof(long));
    memo[0]=memo[1]=1;

    for(int i=2; i<= n; i++)
    {
        memo[i]=memo[i-1]+memo[i-2];
    }
    return(memo[n]);
}
#endif



int main(int argc, char **argv)
{
    int n = 0;
    printf("n:");
    scanf("%d", &n);
    long *memo = NULL;
    memo = malloc((n+1)*sizeof(long));
    for (int i=0; i<n+1; i++)
    {
        memo[i]=-1;
    }

    clock_t start = clock();    
   // long  way = climbing_stairs(n, memo);
    long  way = climbing_stairs(n);
    
    clock_t end   = clock();

    printf("n = %d way = %ld use %f \n", n, way,  (end - start)*1.0/CLOCKS_PER_SEC);
}
