#include <stdio.h>
#include <stdlib.h>

//FUNGSI DISKON
int diskon(int a,int b){
    int n;
    if(b>5 && b<=10){//DISKON 10%
        n=a*10/100;
        n=a-n;
    }else if(b>10){//DISKON 15%
        n=a*15/100;
        n=a-n;
    }else{//TIDAK DISKON
        n=a;
    }
    return n;
}

int main()
{
    //VARIABEL PENGULANGAN
    int ulang;
    do{

    //VARIABEL TOTAL PEMBELIAN SEBELUM DISKON
    int total1=0,total2=0,total3=0,total4=0,total5=0,total6=0;

    //VARIABEL SWITCH & JUMLAH UNIT PESANAN
    int pilihan,jumlah;

    //VARIABEL MENU
    char namaMenu[6][100] = {
                                "1. Nasi Goreng ................. 10k",
                                "2. Nasi Pecel .................. 15k",
                                "3. Nasi Kuning ................. 20k",
                                "4. Nasi Putih .................. 40k",
                                "5. Nasi Kemarin Sore ........... 10k",
                                "6. Nasi Setengah Matang ........ 5k",
                                            };

    puts("=================================");
    printf("*** MENU MAKANAN TUTUP TERUS ***\n");
    puts("=================================\n");

    //MENAMPILKAN MENU RESTO
    for(int i=0;i<6;i++){
        printf("%s\n",namaMenu[i]);
    }

    puts("\n=================================");
    printf("SILAHKAN DI PILIH MENUNYA\n");
    puts("=================================\n");

   do{
    int total=0;

    //MEMILIH NOMOR MENU
    printf("NOMOR MENU :");
    scanf("%d", &pilihan);
    if(pilihan<0 || pilihan>6){
        printf("=======ERROR=======");
        pilihan = 0;
    }
    switch (pilihan)
    {
    case 1:
        printf("JUMLAH PESANAN : ");
        scanf("%d", &jumlah); //MEMASUKKAN JUMLAH PESANAN
        total=total + jumlah * 10;

        total1=diskon(total,jumlah);
    break;
    case 2:
        printf("JUMLAH PESANAN : ");
        scanf("%d", &jumlah); //MEMASUKKAN JUMLAH PESANAN
        total=total + jumlah * 15;

        total2=diskon(total,jumlah);
    break;
    case 3:
        printf("JUMLAH PESANAN : ");
        scanf("%d", &jumlah); //MEMASUKKAN JUMLAH PESANAN
        total=total + jumlah * 20;

        total3=diskon(total,jumlah);
    break;
    case 4:
        printf("JUMLAH PESANAN : ");
        scanf("%d", &jumlah); //MEMASUKKAN JUMLAH PESANAN
        total=total + jumlah * 40;

        total4=diskon(total,jumlah);
    break;
    case 5:
        printf("JUMLAH PESANAN : ");
        scanf("%d", &jumlah); //MEMASUKKAN JUMLAH PESANAN
        total=total + jumlah * 10;

        total5=diskon(total,jumlah);
    break;
    case 6:
        printf("JUMLAH PESANAN : ");
        scanf("%d", &jumlah); //MEMASUKKAN JUMLAH PESANAN
        total=total + jumlah * 5;

        total6=diskon(total,jumlah);
    break;

    }
   }while(pilihan!=0);


    //TOTAL SEMUA PESANAN SETELAH DISKON
    puts("\n=================================");
    printf("TOTAL BELANJA : %d k\n",total1+total2+total3+total4+total5+total6);
    puts("=================================\n");

    //TAMPILAN MENU ULANGI
    printf("1. MENGULANGI\n2. KELUAR\n-> ");
    scanf("%d", &ulang);

}while(ulang==1);


    return 0;
}
