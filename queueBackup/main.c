#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//membuat tipe data baru bertipe struct node dengan alias theNode
typedef struct node *theNode;

//isi dari struct node
struct node{
    int value;
    theNode *next;
};

//membuat tipe data baru bertipe struct dengan alias queue_list yang membunyai anggota theNode front dan rear
typedef struct{

    theNode front;
    theNode rear;

}queue_list;

//list queue pertama kali dibuat set NULL
void create_list(queue_list *l){
    l->front = NULL;
    l->rear = NULL;
}

//membuat node baru dengan value get from isi dan set addres is NULL
theNode create_node(int isi){
    theNode n = (theNode)malloc(sizeof(struct node));
    n->value = isi;
    n->next = NULL;
    return n;
}

//enqueue
void enqueue(queue_list *l,theNode n){
    if(l->front == NULL){ //ketika tidak ada data
        l->front = n; //n adalah head
        l->rear = n; // dan n adalah tail
        n->next = NULL; // karena bukan circular maka n->next = null
    }else{ // ketika ada data minimal satu
        theNode q = l->rear; //karena insert last maka kita tampung tail terlebih dahulu
        l->rear= n; // ubah n menjadi tail
        q->next = n; // hubungkan tail yang lama ke tail yang baru
        n->next = NULL; // karena bukan circular maka n->next = null
    }
}

void dequeue(queue_list *l){ //dequeue atau delete first
    if(l->front != NULL){ // dequeue hanya berjalan ketika minimal satu data dalam list
        theNode q = l->front; // head disimpan di variabel q
        l->front = l->front->next; // head dipindah ke data setelah head
        free(q); //q atau head lama di hapus
    }
}

void clear(queue_list *l){ //melakukan dequeue hingga habis
    while(l->front != NULL){
        theNode q = l->front;
        l->front = l->front->next;
        free(q);
    }
}

void print_list(queue_list *l){
    printf("Queue : ");

    if(l->front == NULL){
        printf("[ ]"); //yang dicetak ketika tidak ada data sama sekali
    }else{
        theNode current = l->front; // head disimpan di variabel current. ini seperti duplikasi list
        while(current != NULL){ // tranversal hingga tail dengan kondisi current/node/data saat ini tidak null atau ada datanya
            printf("[%d] ",current->value); // cetak value node saat ini berada
            current = current->next; // tranversal ke node/data selanjutnya
        }
        printf("\n\nThe Head : %d\n",l->front->value);
        printf("The Tail : %d",l->rear->value);
    }
}

void find_myqueue(queue_list l, int the_value){
    int count_the_node = 0;
    theNode current = l.front;

    if(the_value != NULL){
        //printf("\nTidak ada antrian yang dicari");
        while(current != NULL){
            count_the_node++;
            if(current->value == the_value){
                printf("\nNomor antrian %d terdapat pada urutan %d",the_value,count_the_node);
                the_value=0;
            }
            current = current->next;
        }
        if(the_value!=0){
                printf("\nNomor antrian %d tidak terdapat pada list, silahkan mengantri terlebih dahulu!",the_value);
            }
    }

}

int main(){
    //deklarasi l untuk head dan tail
    queue_list l;
    //inisialisasi l dengan memanggil fungsi create_list dengan argumen &l
    create_list(&l);
    // deklarasi variabel isi dan pilihan
    int isi,pilihan_menu, pilihan_batasan, find_value, batasan, count_the_node;
    find_value=0;
    count_the_node = 0;
    // deklarasi n untuk data/node
    theNode n;
    // deklarasi dan inisialisasi stop untuk looping menu queue
    bool stop = false;

    printf("----------Apakah anda ingin membatasi antrian?----------");
    printf("\n1. ya");
    printf("\n2. tidak");
    printf("\nMasukkan nomor pilihan : ");
    scanf("%d",&pilihan_batasan);
    if(pilihan_batasan==1){
        system("cls");
        printf("Masukkan batasan antrian yang anda inginkan : ");
        scanf("%d",&batasan);
    }

    while(!stop){
        system("cls");
        printf("----------Queue With Single Linked List Circular----------\n\n");

        if(pilihan_batasan == 1){
            printf("Antrian terbatas!, hanya tersedia %d antrian\n\n",batasan);
        }

        print_list(&l);
        find_myqueue(l,find_value);
        find_value=0;
        printf("\n");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Clear");
        printf("\n4. Find Queue");
        printf("\n5. Exit");
        printf("\nMasukkan Pilihan : ");
        scanf("%d",&pilihan_menu);

        if(pilihan_menu == 1 ){
            if((count_the_node<batasan) || (pilihan_batasan!=1)){
                printf("Masukkan Angka : ");
                scanf("%d",&isi);
                n = create_node(isi);
                enqueue(&l,n);
                count_the_node++;
            }else{
                printf("\nAntrian penuh mohon ditunggu");
            }

        }else if(pilihan_menu == 2){
            dequeue(&l);
            if(l.front != NULL){
                count_the_node--;
            }
        }else if(pilihan_menu == 3){
            clear(&l);
        }else if(pilihan_menu == 4){
            printf("Masukkan no urut antrian anda: ");
            scanf("%d",&find_value);
        }else if(pilihan_menu == 5){
            stop=true;
        }
    }

    return 0;
}
