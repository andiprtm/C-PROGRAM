#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct elemen *address;

struct elemen{
    int info;
    address *next;
};

typedef struct{
    address first;
    address last;

}list_interger;

void createlist(list_interger *l){
    l->first = NULL;
    l->last = NULL;
}

address createnode(int isi){
    address p = (address)malloc(sizeof(struct elemen));
    p->info = isi;
    p->next = NULL;
    return p;
}

void insertlast(list_interger *l,address p){
    if(l->first == NULL){
        l->first = p;
        l->last = p;
        p->next = l->first;
    }else{
        address q = l->last;
        l->last= p;
        q->next = p;
        p->next = l->first;
    }
}

void deletefirst(list_interger *l,address p){
    if(l->first != NULL){
        p = l->first;
        if(p->next == l->first){
            p->next = NULL;
            l->first = NULL;
        }else{
            l->last->next = l->first->next;
            address q = l->first;
            l->first = l->first->next;
            q=NULL;

        }
    }
}

void freeList(list_interger *l, address p)
{
   p = l->first;

   while(p!=NULL){
       if(l->first != NULL){
        if(p->next == l->first){
            p->next = NULL;
            l->first = NULL;
            p=NULL;
        }else{
            l->last->next = l->first->next;
            address q = l->first;
            l->first = l->first->next;
            q=NULL;
            p=l->first;

        }
    }
   }
}

void printlist(list_interger l){
    printf("Queue : ");

    if(l.first == NULL){
        printf("[ ]");
    }else{
        address current = l.first;
        while(current->next != l.first){
            printf("[%d] ",current->info);
            current = current->next;
        }
        printf("[%d]", current->info);

    }
}
int main(){
    list_interger l;
    createlist(&l);
    int isi,pil;
    address p;
    bool stop = false;

    while(!stop){
        system("cls");
        printf("----------Queue With Single Linked List Circular----------\n\n");
        printlist(l);
        printf("\n");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Clear");
        printf("\n4. Keluar");
        printf("\nMasukkan Pilihan : ");
        scanf("%d",&pil);

        if(pil == 1){
            printf("Masukkan Angka : ");
            scanf("%d",&isi);
            p = createnode(isi);
            insertlast(&l,p);
        }
        else if(pil == 2){
            deletefirst(&l,p);
        }
        else if(pil == 3){
            freeList(&l,p);
        }
        else if(pil == 4){
            stop=true;
        }
    }

    return 0;
}
