#include <stdio.h>
#include <stdlib.h>

int main()
{
    double A=5,B=7,C=14;
    double hasil;

    hasil = A - B / C;
    printf ("hasil = %.2lf\n", hasil);
    hasil = B + C * A;
    printf ("hasil = %.2lf\n", hasil);
    hasil = 3 * B / B;
    printf ("hasil = %.2lf\n", hasil);
    hasil = C + B * A * C;
    printf ("hasil = %.2lf\n", hasil);
    hasil = C / 2 * (A + B);
    printf ("hasil = %.2lf\n", hasil);
    hasil = (A+B) * (C / 2);
    printf ("hasil = %.2lf\n", hasil);

    return 0;
}
