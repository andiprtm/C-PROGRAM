#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    //double sisikaki,alas;
    char satuan[100];
    double sisikaki,alas,tinggi,luas,setAlas;

    printf("-------------------MENGHITUNG LUAS SEGITIGA SAMA KAKI----------------------");
    puts("\n\n");

    printf("INPUT SATUAN YANG DIGUNAKAN = ");
    scanf("%s[^\n]", satuan); getchar();

    printf("INPUT SISI KAKI (SISI KANAN DAN SISI KIRI) = ");
    scanf("%lf", &sisikaki);

    printf("INPUT SISI ALAS = ");
    scanf("%lf", &alas);

    puts("\n");
    printf("----------------HASILNYA ADALAHHHHHHH JENGGG JENGGG JENGGGG-----------------");
    puts("\n\n");

    setAlas = alas / 2;
    tinggi = pow(sisikaki,2) - pow(setAlas,2);
    tinggi = sqrt (tinggi);
    luas = setAlas * tinggi;
    printf("SISI KAKI ADALAH = %lf %s \n", sisikaki, satuan);
    printf("SISI ALAS ADALAH = %lf %s\n", alas, satuan);
    printf("LUAS SEGITIGA SAMA KAKI = %.4lf %s\n", luas, satuan);

    puts("\n\n/////////////////////////////////////////////////////////////////////////////");
    puts("\n");
    return 0;
}
