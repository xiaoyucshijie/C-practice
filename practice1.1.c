#include <stdio.h>
int main()
{
    int f1=1,f2=1,f3;
    printf("%d %d ",f1,f2);
    for(int i=3; i<=40; i++)
    {
        f3=f1+f2;
        printf("%d ",f3);
        f1=f2;
        f2=f3;
    }
    return 0;
}