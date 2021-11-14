#include <stdio.h>
#include <stdlib.h>

void main ()
{
    //VARIABEL
    int t, b;

    //INPUT BULAN DAN TAHUN
    system("cls");
    printf("SILAHKAN ISIKAN BULAN DAN TAHUN\n\n");
    printf("BULAN = ");
    scanf("%d", &b);
    printf("TAHUN = ");
    scanf("%d", &t);
    puts("\n");

    //SELEKSI BULAN DAN TAHUN
    //BULAN DAN TAHUN YANG DI INPUTKAN SESUAI
    if(b>=1 && b<=12 && t>=1){
        //BULAN YANG BERJUMLAH 31 HARI
        if(b==1 || b==3 || b==5 || b==7 || b==8 || b==10 || b== 12)
            printf("Pada Tahun %d Bulan %d mempunyai hari sebanyak 31 hari\n", t, b);
        //BULAN YANG BERJUMLAH 30 HARI
        if(b==4 || b==6 || b==9 || b==11)
            printf("Pada Tahun %d Bulan %d mempunyai hari sebanyak 30 hari\n", t, b);
        //BULAN KE 2 YANG MEMPUNYAI 2 KEMUNGKINAN JUMLAH HARI
        if(b==2){
                //JUMLAH HARI PADA TAHUN KABISAT
                if(t%4==0){
                    printf("Pada Tahun %d Bulan %d mempunyai hari sebanyak 29 hari\n", t, b);
                    printf("FYI Tahun %d adalah tahun kabisat\n", t);
                }
                // JUMLAH HARI PADA TAHUN NON-KABISAT
                else{
                    printf("Pada Tahun %d Bulan %d mempunyai hari sebanyak 28 hari\n", t, b);
                }
        }
    }
    //BULAN ATAU TAHUN YANG DIINPUTKAN SALAH
    else {
        printf("mohon maaf bulan atau tahun yang anda masukkan tidak terdaftar\n");
    }
}
