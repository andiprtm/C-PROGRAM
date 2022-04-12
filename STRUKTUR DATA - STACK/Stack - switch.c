#include <stdio.h>
#include <stdlib.h>
#define MAX 4

typedef struct {
    char nama[50];
    int umur;
}person;

person stack[MAX];
int TOP = -1;

int isFull(){
    if(TOP<MAX-2){
        return 0;
    }else{
        return 1;
    }
}

int isEmpty() {
    if(TOP!=-1){
        return 0;
    }else{
        return 1;
    }
}

person peek(){
    person temp;

    temp = stack[TOP];
    return temp;
}

person pop(){
    person temp;

    temp=stack[TOP];
    TOP--;

    return temp;
}

void push(person p){
    TOP++;
    stack[TOP]=p;
    printf("data berhasil di push ke index %d",TOP);
}

int main()
{
    person p[MAX];
    person temp;
    int pilihan = 1;
    int jumlahData = 0;

    while (pilihan){
        puts("\n\n== DAFTAR MENU PROGRAM ==");
        printf("\n1. INPUT DATA\n");
        printf("2. PEEK DATA\n");
        printf("3. POP DATA\n");
        printf("4. BANYAK DATA SEKARANG\n");
        printf("0. EXIT\n");
        puts(" ");
        printf("MASUKKAN ANGKA PILIHAN ==> ");
        scanf("%d",&pilihan);

        switch(pilihan){
        case 0:
            pilihan =0;
            break;
        case 1:
            if(isFull()){
                printf("\nMAAF DATA PENUH, MOHON POP DATA");
            }else{
                printf("\nDATA KTP KE-%d\n", TOP+2);
                printf("MASUKKAN NAMA : ");
                scanf(" %[^\n]",&p[jumlahData].nama); getchar();
                printf("MASUKKAN UMUR : ");
                scanf("%d",&p[jumlahData].umur);

                push(p[jumlahData]);
                jumlahData++;
            }
            break;
        case 2:
            if(isEmpty()){
                printf("\nMASUKKAN DATA TERLEBIH DAHULU!");
            }else{
                temp = peek();
                printf("\nDATA KTP KE-%d\n", TOP+1);
                printf("NAMA : %s\n",temp.nama);
                printf("UMUR : %d",temp.umur);
            }
            break;
        case 3:
            if(isEmpty()){
                printf("\nMASUKKAN DATA TERLEBIH DAHULU!");
            }else{
                temp = pop();
                printf("\nDATA KTP KE-%d\n", TOP+2);
                printf("NAMAMU ADALAH %s\n",temp.nama);
                printf("UMURMU ADALAH %d",temp.umur);
            }
            break;
        case 4:
            printf("\nJUMLAH DATA SEKARANG : %d",TOP+1);
            break;
        default :
            system("cls");
            printf("MOHON MASUKKAN NOMOR SESUAI DENGAN YANG ADA PADA MENU!!");
        }
    }

    return 0;
}
