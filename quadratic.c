#include <stdio.h>
#include <math.h>
int main(void)
{
    double a, b, c;
    printf("请输入一元二次方程 ax^2 + bx + c = 0 的系数 a, b, c：");
    scanf("%lf %lf %lf", &a, &b, &c);

    printf("\n方程：%.2f x^2 + %.2f x + %.2f = 0\n\n", a, b, c);

    if (a == 0)
    {
        printf("a = 0，方程不是一元二次方程。\n");
        if (b == 0)
        {
            if (c == 0)
                printf("方程恒成立，任意实数都是解。\n");
            else
                printf("方程无解（0 = 非零数，矛盾）。\n");
        }
        else
        {
            printf("退化为一元一次方程：%.2f x + %.2f = 0\n", b, c);
            printf("解得：x = %.2f\n", -c / b);
        }
    }
    else
    {
        double delta = b * b - 4 * a * c;
        printf("判别式 Δ = b^2 - 4ac = %.2f\n\n", delta);

        if (delta > 0)
        {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            printf("Δ > 0，方程有两个不相等的实数根：\n");
            printf("x1 = %.2f\n", x1);
            printf("x2 = %.2f\n", x2);
        }
        else if (delta == 0)
        {
            double x = -b / (2 * a);
            printf("Δ = 0，方程有两个相等的实数根：\n");
            printf("x1 = x2 = %.2f\n", x);
        }
        else
        {
            double real = -b / (2 * a);
            double imag = sqrt(-delta) / (2 * a);
            printf("Δ < 0，方程没有实数根，有两个共轭复数根：\n");
            printf("x1 = %.2f + %.2fi\n", real, imag);
            printf("x2 = %.2f - %.2fi\n", real, imag);
        }
    }

    return 0;
}