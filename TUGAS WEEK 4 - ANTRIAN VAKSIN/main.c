#include <stdio.h>
#include <stdlib.h>

int main()
{
    //VARIABEL
    int n;

    //INPUT NOMOR URUT
    printf("SELAMAT DATANG \nSilahkan masukkan nomor urut anda\nuntuk mengetahui jadwal vaksin anda\n\n");
    printf("NOMOR URUT = ");
    scanf("%d",&n);

    //SELEKSI NOMOR URUT
    system("cls");
    if (n>=1 && n<=200){
        if(n<=50)
            printf("Nomor urut %d dilaksanakan vaksin hari ini\nDimulai pada pukul 08.00 WIB",n);
        if(n>50 && n<=100)
            printf("Nomor urut %d dilaksanakan vaksin hari ini\nDimulai pada pukul 09.00 WIB",n);
        if(n>100 && n<=150)
            printf("Nomor urut %d dilaksanakan vaksin hari ini\nDimulai pada pukul 10.00 WIB",n);
        if(n>150 && n<=200)
            printf("Nomor urut %d dilaksanakan vaksin hari ini\nDimulai pada pukul 11.00 WIB",n);

    }else if (n>200 && n<=1000){

            printf("Nomor urut %d dilaksanakan vaksin BESOK",n);

    }else if (n>1000){

            printf("Nomor urut %d melebihi dari stock vaksin yang tersedia\nsilahkan kembali esok hari dan mengambil nomor antrian",n);

    }else {
        printf("nomor antrian %d tidak diketahui",n);
    }

    puts(" ");

}
