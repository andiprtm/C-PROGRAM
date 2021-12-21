/* C Program to sort an array in ascending order using Insertion Sort */
#include <stdio.h>
int main()
{
    int n, i, j, temp;
    int arr[64];

    //JUDUL
    printf("----------INSERTION SORT----------\n\n");

    //INPUT BANYAKNYA BILANGAN YANG INGIN DIURUTKAN
    printf("Masukkan Jumlah Angka : ");
    scanf("%d", &n);

    puts(" ");

    //INPUT ANGKA YANG INGIN DIURUTKAN
    printf("---------MASUKKAN %d ANGKA---------\n\n", n);
    for (i = 0; i < n; i++)
    {
        printf("Masukkan Angka Ke-%d : ",i+1);
        scanf("%d", &arr[i]);
    }

    //PROSES MENGURUTKAN
    for (i = 1 ; i <= n-1 ; i++)
    {
	    j = i;
            while ( j > 0 && arr[j-1] > arr[j])
            {
                //MELAKUKAN SWAP ANGKA JIKA TIDAK URUT
                temp     = arr[j];
                arr[j]   = arr[j-1];
                arr[j-1] = temp;
                j--;
            }
    }

    puts(" ");

    printf("---------SETELAH DIURUTKAN---------\n");

    puts(" ");

    for (i = 0; i <= n - 1; i++)
    {
        printf("%d, ", arr[i]);
    }
    return 0;
}
