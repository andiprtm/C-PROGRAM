#include <stdio.h>

int main()
{
    //VARIABEL
    int n,x;

    //INPUT
    printf("MASUKKAN NILAI TANGGA\n");
    puts("------------------------\n");
    printf("PANJANG TANGGA : ");
    scanf("%d",&n);
    printf("1. ANGKA\n2. BINTANG\nPILIHAN : ");
    scanf("%d",&x);

    //LOOP FOR
    puts("\nTANGGA");
    for(int i=1; i<=n; i++){ //FOR 1
        for(int j=1 ;j<=i;j++){//FOR 2
            if(x==1){
            printf("%d ",j);
            }else{
                printf("* ");
            }
        } printf("\n");
    }
}
