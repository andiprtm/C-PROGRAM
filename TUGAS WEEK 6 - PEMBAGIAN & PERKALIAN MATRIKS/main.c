#include <stdio.h>

int main()
{
    //VARIABEL MATRIKS INPUT
    int matriks1[10][10], matriks2[10][10];
    //VARIABEL MATRIKS INVERS
    int hasil[10][10];
    //VARIABEL HASIL AKHIR DARI OPERASI MATRIKS
    int hasilAkhir[10][10];
    //VARIABEL MATRIKS ADJOIN
    int matriks2inv[10][10];
    //VARIABEL UNTUK OPERASI DETERMINAN
    int a,b,c;
    //VARIABEL UNTUK FOR
    int i, j, k;
    //VARIABEL UNTUK SWITCH
    int m;
    //VARIABEL UNTUK MENYIMPAN HASIL PERKALIAN MATRIKS
    int jumlah = 0;
    //VARIBAEL UNTUK 1 / DETERMINAN
    int proses1;

    //INPUT PILIHAN OPERASI
    printf("PERKALIAN DAN PEMBAGIAN MATRIKS ORDO 2X2\n");
    printf("1. PEMBAGIAN\n2. PERKALIAN\n");
    printf("-> ");
    scanf("%d",&m);

    puts("\n---------------------------------------------\n");

    //INPUT MATRIKS 1
    printf("MASUKKAN ELEMENT MATRIKS 1: \n");
    for(i = 0; i < 2; i++){
      for(j = 0; j < 2; j++){
        scanf("%d", &matriks1[i][j]);
      }
    }

    //INPUT MATRIKS 2
    printf("MASUKKAN ELEMENT MATRIKS 2: \n");
    for(i = 0; i < 2; i++){
      for(j = 0; j < 2; j++){
        scanf("%d", &matriks2[i][j]);
      }
    }

switch (m){
    //CASE PEMBAGIAN
    case 1:
    //DETERMINAN MATRIKS
    a = matriks2[0][0] * matriks2[1][1];
    b = matriks2[0][1] * matriks2[1][0];
    c = a - b;

    //DETERMINAN != 0
    if(c==0){
        printf("NDAK BISA BOS, COBA LAGI!!!");
    }else{

    // 1/DETERMINAN
    proses1 = 1 / c;

    // ADJOIN MATRIKS 2
    matriks2inv[1][1]=matriks2[0][0];
    matriks2inv[1][0]=matriks2[1][0]*-1;
    matriks2inv[0][1]=matriks2[0][1]*-1;
    matriks2inv[0][0]=matriks2[1][1];

    //INVERS MATRIKS
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            hasil[i][j]= proses1 * matriks2inv[i][j];
        }
    }

    puts("\n---------------------------------------\n");

    printf("HASIL MATRIKS 1 / MATRIKS 2 : \n");
    for(i = 0; i < 2; i++){
      for(j = 0; j < 2; j++){
        for(k = 0; k < 2; k++){
          jumlah = jumlah + hasil[i][k] * matriks1[k][j];
        }
        hasilAkhir[i][j] = jumlah;
        jumlah = 0;
      }
    }
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            printf("%d\t", hasilAkhir[i][j]);
        }printf("\n");
}
}break;
    //CASE PERKALIAN
    case 2:
    puts("\n---------------------------------------\n");

    printf("HASIL MATRIKS 1 X MATRIKS 2 : \n");
    for(i = 0; i < 2; i++){
      for(j = 0; j < 2; j++){
        for(k = 0; k < 2; k++){
          jumlah = jumlah + matriks1[i][k] * matriks2[k][j];
        }
            hasilAkhir[i][j] = jumlah;
            printf("%d\t", hasilAkhir[i][j]);
            jumlah = 0;
      }printf("\n");
    }break;
}
  return 0;
}
