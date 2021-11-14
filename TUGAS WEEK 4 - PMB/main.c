#include <stdio.h>
#include <stdlib.h>

int main()
{
    //VARIABEL
    int u,r;
    double t,nr;

    //INPUT USIA
    printf("-------------------SELAMAT DATANG-------------------");
    puts("\n");
    printf("SILAHKAN MASUKKAN USIA ANDA = ");
    scanf("%d",&u);

    //SELEKSI USIA
    system("cls");
    //USIA LEBIH DARI 20 TAHUN
    if(u>20){
        //INPUT NILAI UJIAN
        printf("!!SILAHKAN MENGIKUTI UJIAN TERLEBIH DAHULU!!!\n\n");
        printf("SILAHKAN MASUKKAN NILAI UJIAN\n\n");
        printf("Nilai = ");
        scanf("%lf", &t);

            //SELEKSI NILAI UJIAN
            system ("cls");
            if(t<75 && t>=1)
                printf("ANDA DITOLAK!!!!");
            else if(t>=75 && t<=100)
                r=1;
            else
                printf("angka yang anda masukkan salah\nsilahkan masukkan nilai range 1 - 100\n\n");

    //USIA KURANG DARI ATAU SAMA DENGAN 20 TAHUN
    }else if(u>=1 && u<21){
        r=1;
    }else{
        printf("umur yang ada input = %d\n", u);
        printf("umur yang anda inputkan terlalu bar-bar\n");
    }

    //PEMROSESAN NILAI RAPOT
    switch (r){
        case 1:{
            //INPUT NILAI RAPOT
            system ("cls");
            printf("SILAHKAN MASUKKAN NILAI RAPORT\n\n");
            printf("Nilai = ");
            scanf("%lf", &nr);

            //SELEKSI RAPOT
            system("cls");
            if(nr>=65 && nr<=100){
                if(nr>=80)
                    printf ("ANDA BEBAS MEMILIH PROGRAM STUDI");
                if(nr>=70 && nr<80)
                    printf ("PRODI ANDA TEKNIK ELEKTRO");
                if(nr>=65 && nr<70)
                    printf ("PRODI ANDA DIGITAL BISNIS");
                }
            else if(nr>=1 && nr<65){
                printf("ANDA DITOLAK!!!!");
                }
            else{
                printf("angka yang anda masukkan salah\nsilahkan masukkan nilai range 1 - 100\n\n");
                }

                puts(" ");

        }

    }

}
