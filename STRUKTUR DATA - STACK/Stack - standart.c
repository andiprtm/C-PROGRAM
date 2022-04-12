#include <stdio.h>
#include <stdlib.h>
#define MAX 4

//MEMBUAT TIPE DATA BARU BERTIPE STRUCT DENGAN ANGGOTA NAMA DAN UMUR
//DALAM STACK DIBUTUHKAN
//1. DATA TOP = UNTUK MENYIMPAN INDEX ARRAY DATA INPUT TERAKHIR
// **SAAT DATA KOSONG MAKA TIDAK ARRAY YANG DIPAKAI MAKA SAAT KOSONG TOP AKAN BERNILAI -1
//2. ISFULL = SEBUAH FUNGSI YANG MENGEMBALIKAN RETURN 1 (BENAR) JIKA ARRAY SUDAH FULL DAN 0 (SALAH) JIKA MASIH ADA SISA ARRAY
//3. ISEMPTY = SEBUAH FUNGSI YANG MEMNERIKAN RETURN 0 (SALAH) JIKA TOP != -1 DAN 1 (BENAR) JIKA TOP = -1
//4. PEEK = SEBUAH FUNGSI BERTIPE STRUCT YANG AKAN MENGEMBALIKAN DATA[TOP] BERUPA STRUCT KE PEMANGGILAN
//5. POP = FUNGSI BERTIPE STRUCT YANG AKAN MENGAMBIL SATU PERSATU DATA MULAI DARI ATAS
//** SETIAP DATU PENGAMBILAN POP MAKA TOP AKAN DI -1, KARENA POP MENGAMBIL DARI ATAS OTOMATIS TOP AKAN TURUN 1 DATA.
//6. PUSH = SEBUAH PROSEDUR YANG AKAN MEMBANTU MENGINPUTKAN DATA KE STACK
//** SETIAP PUSH BERARTI TOP AKAN DITAMBAH 1

typedef struct {
    char nama[50];
    int usia;
}KTP;

KTP stack[MAX];
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

KTP peek(){
    KTP temp;

    temp = stack[TOP];
    return temp;
}

KTP pop(){
    KTP temp;

    if(isEmpty()){
        printf("MAAF BELUM ADA DATA");
    }else{
        temp=stack[TOP];
        TOP--;
        return temp;
    }
}

void push(KTP data){

    if(!isFull()){
        TOP++;
        stack[TOP]=data;
    }else{
        printf("MAAF DATA PENUH\n\n");
    }
}

int main()
{
    KTP data[MAX];
    KTP temp;

    //PUSH DATA KTP 1
    data[0]= (KTP) {"ANDI DIVANGGA",18};
    push(data[0]);

    //PUSH DATA KTP 2
    data[1]= (KTP) {"IRVAN SURYA",19};
    push(data[1]);

    //PUSH DATA KTP 3
    data[2]= (KTP) {"KAHIL AKBAR",20};
    push(data[2]);

    //PEEK
    temp=peek();
    printf("== DATA KTP TERAKHIR DIINPUTKAN ==\n");
    printf("Nama : %s\n", temp.nama);
    printf("umur : %d\n\n", temp.usia);

    //POP 1
    temp=pop();
    printf("== DATA KTP ke 3 ==\n");
    printf("Nama : %s\n", temp.nama);
    printf("umumr : %d\n\n", temp.usia);

    //POP 2
    temp=pop();
    printf("== DATA KTP ke 2 ==\n");
    printf("Nama : %s\n", temp.nama);
    printf("umumr : %d\n\n", temp.usia);

    //POP 3
    temp=pop();
    printf("== DATA KTP ke 1 ==\n");
    printf("Nama : %s\n", temp.nama);
    printf("umumr : %d\n\n", temp.usia);

    //POP 4
    pop();

    return 0;
}
