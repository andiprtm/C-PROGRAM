#include <stdio.h>
#include <math.h>

int main()
{
    //VARIABEL
    int n,pangkat;

    //INPUT
    printf("PEMANGKATAN 2\n");
    puts("------------------------\n");
    printf("NILAI : ");
    scanf("%d",&n);

    //LOOP FOR
    puts("\nHASIL");
    for(int i=1; i<=n; i++){
           pangkat=pow(2,i);
           printf("2^%d = %d\n",i,pangkat);

    }
}
