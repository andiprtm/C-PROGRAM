#include <stdio.h>
#include <stdlib.h>

int main()
{
    double r, d, phi, luas, keliling;
    char satuan[100];

    printf("-------------------MENGHITUNG LUAS LINGKARAN DAN KELILINGNYA----------------------");
    puts("\n\n");

    printf("INPUT SATUAN YANG DIGUNAKAN = ");
    scanf("%s[^\n]", satuan); getchar();

    printf("INPUT DIAMETER (JARI JARI X 2) = ");
    scanf("%lf", &d);

    puts("\n");
    printf("----------------HASILNYA ADALAHHHHHHH JENGGG JENGGG JENGGGG-----------------");
    puts("\n\n");

    phi= (double) 22 / 7;
    r = d / 2;

    printf("jari jari : %lf %s\n", r, satuan);
    luas = pow (r,2) * phi;
    printf("luas lingkaran : %lf %s\n", luas, satuan);
    keliling =  2 * phi * r;
    printf("keliling lingkaran : %lf %s\n", keliling, satuan);
    return 0;
}
