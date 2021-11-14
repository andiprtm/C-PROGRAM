#include <stdio.h>

int main()
{
    //VARIABEL INPUT BILANGAN
    int BILANGAN[20];
    //VARIABEL PROSES SORTING
    int temp, idx;
    //VARIABEL FOR
    int  i, j;
    //VARIABEL INPUT JUMLAH ANGKA YANG INGIN DI INPUT
    int n;

    //INPUT JUMLAH ANGKA
    printf("MASUKKAN JUMLAH BILANGAN\n-> ");
    scanf("%d", &n);
    puts("\n----------------------------\n");

    //INPUT BILANGAN KE ARRAY
    printf("MASUKKAN BILANGAN PILIHANMU : \n\n");
    for(i=0; i<n; i++){
        printf("MASUKKAN BILANGAN KE-%d: ",i+1);
        scanf("%d", &BILANGAN[i]);
    }
    puts("\n----------------------------\n");

    //MENAMPILKAN BILANGAN YANG TELAH DI INPUTKAN
    printf("SEBELUM DISORTING : ");
    for(i=0; i<n; i++){
        printf("%d ", BILANGAN[i]);
    }
    puts(" ");

    //PROSES SORTING
    //BILANGAN AKAN DIPROSES UNTUK DIURUTKAN DARI TERKECIL KE TERBESAR
    for(i=0; i<(n-1); i++)
    {
        idx=i;
        for(j=i+1; j<n; j++){
            if(BILANGAN[idx]>BILANGAN[j]){
                idx=j; //PERUBAHAN INDEX YANG DICOCOKAN
            }
        }

        //PROSES PENUKARAN
        temp=BILANGAN[i];
        BILANGAN[i]=BILANGAN[idx];
        BILANGAN[idx]=temp;
    }

    //MENAMPILKAN BILANGAN YANG TELAH DI SORTIR
    printf("\nSETELAH DISORTING : ");
    for(i=0; i<n; i++){
        printf("%d ", BILANGAN[i]);
    }
    printf("\n");
    return 0;
}
