#include <stdio.h>
#include <stdlib.h>

int main()
{
    //VARIABEL UNTUK MENAMPUNG INPUT STRING
    char kalimat[100];

    //INPUT STRING
    scanf("%[^\n]", kalimat); getchar();

    //MENGHITUNG BANYAKNYA KARAKTER STRING
    int length = strlen(kalimat);

    //LOOPING TANGGA
      for(int i=0;i<length;i++){
        for(int j=0;j<i+1;j++){ //YANG MEMBUAT BENTUK SEPERTI TANGGA ADALAH KONDISI DARI J
            printf("%c ", kalimat[j]); //MENAMPILKAN KARAKTER PADA VARIABEL KALIMAT BERDASARKAN INDEX
        }puts(" ");
      }
    return 0;
}
