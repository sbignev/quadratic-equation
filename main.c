#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int solutionEquation ( const double a, const double b,const double c, double *x1, double *x2)
{
    if (x1 == NULL || x2 == NULL || x1 == x2) return 0;
    if (!isfinite(a) || !isfinite(b)||!isfinite(c)) return 1;

    double d = b*b - 4*a*c;
    if (d < 0) return 2;
    if (d == 0)
    {
        *x1 = -b/(2*a);
        *x2 = *x1;
        return 3;
    }
    if (d > 0)
    {
        *x1 = (-b + sqrt(d))/(2*a);
        *x2 = (-b - sqrt(d))/(2*a);
        return 4;
    }

}

int main ()
{
    printf (" This program solves quadratic equations of the form: ax ^ 2 + bx + c = 0 ");
    printf (" Enter a, b, c ");

    double a = 0, b = 0, c = 0;
    scanf ("%lg %lg %lg", &a, &b, &c);

    double x1 = 0, x2 = 0;

    int exist = solutionEquation (a, b, c, &x1, &x2);
    switch (exist)
    {
        case 0:
            printf (" memory allocation error");
            break;
        case 1:
            printf (" incorrect data entered");
            break;
        case 2:
            printf (" the equation has no roots ");
            break;
        case 3:
            printf ("  the equation has 1 root: x1 = %lg", x1);
            break;
        case 4:
            printf (" the equation has 2 root: x1 = %lg, x2 = %lg", x1, x2);
            break;
        default: printf (" Error ");
    }

    return 1;
}
