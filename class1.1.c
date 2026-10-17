#include <stdio.h>

int main() 
{
    int a = 5;
    float b = 3.14;
    double c = 2.71828;
    char d = 'a';
    printf("%c", d);
    scanf("%d%f%f", &a, &b, &c);
    printf("a = %d, b = %f, c = %lf\n", a, b, c);
    printf("%d %d %d\n", &a, &b, &c);
    return 0;
}