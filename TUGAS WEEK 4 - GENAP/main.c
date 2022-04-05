#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10

//MEMBUAT TIPE DATA BARU BERNAMA dataMahasiswa BERTIPE STRUCT
typedef struct{
    int nim;
    float ipk;
    char nama[50];
    char alamat[50];
}dataMahasiswa;

//FUNGSI UNTUK MENJALANKAN PROSES INPUT DATA
int insert(dataMahasiswa p[MAX],int num, int jumlahData){

    for(int i = jumlahData-num;i<jumlahData;i++){
        printf("\nMasukkan Data Mahasiswa\n");
        printf("- Masukkan NIM         : ");
        scanf("%d", &p[i].nim);
        printf("- Masukkan Nama        : ");
        scanf(" %[^\n]", &p[i].nama); getchar();
        printf("- Masukkan Alamat/Kota : ");
        scanf(" %[^\n]", &p[i].alamat); getchar();
        printf("- Masukkan IPK         : ");
        scanf("%f", &p[i].ipk);
    }

    return p;
}

//PROSEDUR UNTUK MENCARI NIM YANG AKAN DIUBAH DATANYA
void search(dataMahasiswa p[MAX], int cari, int n){
    int middle;
    int first, last;
    last = n -1;
	first = 0;

	while (first <= last){
        middle = (first+last)/2;
		if (p[middle].nim < cari){
			first = middle + 1;
		}
		else if (p[middle].nim > cari){
			last = middle - 1;
		}
		else{
			insert(p,1,middle+1);
			break;
		}

		if (first > last){
            printf("\nDATA TIDAK DITEMUKAN, MOHON INPUT NIM SESUAI DENGAN YANG ADA PADA TABEL!\n\n");
        }
	}

}

//PROSEDUR UNTUK MENJALANKAN FUNGSI CETAK SEMUA NILAI
void cetak(dataMahasiswa p[MAX], int numKosong){


        printf("\n                   DATA MAHASISWA                       \n");
        printf("----------------------------------------------------------\n");
        printf("|    NIM    |         NAMA         |    ALAMAT    | IPK  |\n");
        printf("----------------------------------------------------------\n");

    for(int i=0;i<MAX-numKosong;i++){

        printf("| %-9d | %-20s | %-12s | %.2f |\n", p[i].nim , p[i].nama , p[i].alamat , p[i].ipk);
        printf("----------------------------------------------------------\n");

    }
}

//PROSEDUR YANG HANYA MENCETAK DATA MAHASISWA YANG MEMILIKI IPK DI BAWAH 3.00
void cetakBerdasarakanIPK(dataMahasiswa p[MAX], int dataKosong){
    int verify=0;

        printf("\n                   DATA MAHASISWA                       \n");
        printf("----------------------------------------------------------\n");
        printf("|    NIM    |         NAMA         |    ALAMAT    | IPK  |\n");
        printf("----------------------------------------------------------\n");

    for(int i=0;i<MAX-dataKosong;i++){
        if(p[i].ipk < 3){

            printf("| %d | %-20s | %-12s | %.2f |\n", p[i].nim , p[i].nama , p[i].alamat , p[i].ipk);
            printf("----------------------------------------------------------\n");

            verify++;
        }
    }

    if(verify==0){
        printf("TIDAK ADA DATA MAHASISWA YANG MEMILIKI IPK KURANG DARI 3.00\n");
    }

    puts(" ");
}

//PROSEDUR UNTUK MENGURUTKAN DATA BERDASARKAN NIM KEMUDIAN DATA YANG TELAH DIURUTKAN AKAN DIPROSES OLEH PROSEDUR CETAK
void cetakBrdasarakanNIM(dataMahasiswa p[MAX], int dataKosong){
    dataMahasiswa temp;
    int i,j;

    for (i = 1 ; i <= MAX-dataKosong-1 ; i++)
    {
	    j = i;
            while ( j > 0 && (p[j-1].nim > p[j].nim))
            {
                //MELAKUKAN SWAP ASCENDING
                temp   = p[j];
                p[j]   = p[j-1];
                p[j-1] = temp;
                j--;
            }
    }

    cetak(p,dataKosong);
}

//PROSEDUR UNTUK MENGUBAH DATA
void ubahDataMahasiswa(dataMahasiswa p[MAX], int dataKosong, int jumlahDataSekarang){
    system("cls");

    printf("----------------------------------------------------------\n");
    printf("|         SELAMAT DATANG PADA HALAMAN UBAH DATA          |\n");
    printf("----------------------------------------------------------\n");

    cetakBrdasarakanNIM(p,dataKosong);

    int input;

    printf("MASUKKAN NIM TARGET ==> ");
    scanf("%d",&input);

    search(p,input,jumlahDataSekarang);

}

//PROSEDUR PERINGATAN DATA OVERLOAD
void warningDataOverload(){
    printf("-----------------------------------------------------------\n");
    printf("|   TIDAK DAPAT MENAMBAH DATA KARENA MELEBIHI KAPASITAS!  |\n");
    printf("-----------------------------------------------------------\n");
}

int main() {

    printf("----------------------------------------------------------\n");
    printf("|           SELAMAT DATANG PADA PROGRAM STRUCT           |\n");
    printf("----------------------------------------------------------\n");

    dataMahasiswa p[MAX];

    p[0] = (dataMahasiswa){120321004,4.00,"DAVID LEO","SURABAYA"};
    p[1] = (dataMahasiswa){120321002,4.00,"HANIF AHSANI","NGANJUK"};

    int jumlahDataSekarang = 2;
    int gate = 1;
    int input;

    while(gate){

        int dataKosong = MAX;

        puts("=================== DAFTAR MENU PROGRAM ==================");
        printf("1. tampilkan semua data\n");
        printf("2. input 1 data mahasiswa\n");
        printf("3. input 3 data mahasiswa\n");
        printf("4. cetak data mahasiswa dengan ipk kurang dari 3.0\n");
        printf("5. cetak data berdasarkan urutan NIM\n");
        printf("6. edit data mahasiswa\n");
        printf("7. CLEAR SCREEN\n");
        printf("0. EXIT\n");
        puts(" ");
        printf("MASUKKAN ANGKA PILIHAN ==> ");
        scanf("%d",&input);

        switch(input){
        case 0 :
            gate = 0;
            break;
        case 1 :
            dataKosong-=jumlahDataSekarang;
            if(jumlahDataSekarang<MAX){
                cetak(p,dataKosong);
            }else{
                warningDataOverload();
                gate=0;
                break;
            }
            break;
        case 2 :
            jumlahDataSekarang= 1 + jumlahDataSekarang;
            dataKosong-=jumlahDataSekarang;
            if(jumlahDataSekarang<MAX){
                cetak(insert(p,1,jumlahDataSekarang),dataKosong);
                puts("*data berhasil diinputkan\n");
            }else{
                warningDataOverload();
                gate=0;
                break;
            }
            break;
        case 3 :
            jumlahDataSekarang=3 + jumlahDataSekarang;
            dataKosong-=jumlahDataSekarang;
            if(jumlahDataSekarang<MAX){
                cetak(insert(p,3,jumlahDataSekarang),dataKosong);
                puts("*data berhasil diinputkan\n");
            }else{
                warningDataOverload();
                gate=0;
                break;
            }
            break;
        case 4 :
            dataKosong-=jumlahDataSekarang;
            if(jumlahDataSekarang<MAX){
                cetakBerdasarakanIPK(p,dataKosong);
            }else{
                warningDataOverload();
                gate=0;
                break;
            }
            break;
        case 5 :
            dataKosong-=jumlahDataSekarang;
            if(jumlahDataSekarang<MAX){
                cetakBrdasarakanNIM(p,dataKosong);
            }else{
                warningDataOverload();
                gate=0;
                break;
            }
            break;
        case 6 :
            dataKosong-=jumlahDataSekarang;
            if(jumlahDataSekarang<MAX){
                ubahDataMahasiswa(p,dataKosong,jumlahDataSekarang);
                puts("*data berhasil diinputkan\n");
            }else{
                warningDataOverload();
                gate=0;
                break;
            }
            break;
        case 7 :
            system("cls");
            break;
        default :
            system("cls");
            printf("MENU TIDAK DITEMUKAN, MOHON INPUT ANGKA SESUAI DENGAN YANG TERSEDIA PADA MENU!!!\n\n");
            main();
            break;
        }
    }

    return 0;
}
