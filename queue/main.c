#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

typedef struct{
    int data[MAX];
    int head;
    int tail;
}queue;

queue q;

void creatQueue (){
    q.head=q.tail=-1;
}

int isEmpty(){
    if(q.tail==-1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(){
    if(q.tail==MAX-1){
        return 1;
    }else{
        return 0;
    }
}

void enqueue(int data){
    if(isEmpty()==1){
        q.head=q.tail=0;
        q.data[q.tail]=data;
    }else if(isFull()==0){
        q.tail++;
        q.data[q.tail]=data;
    }
}

int dequeue(){
    int e = q.data[q.head];

    for(int i=q.head;i<=q.tail;i++){
        q.data[i]=q.data[i+1];
    }

    q.tail--;

    if(isEmpty()){
        q.head=q.tail=-1;
    }

    return e;
}

void clear(){
    q.head=q.tail=-1;
    printf("CLEAR");
}

void tampil(){
    printf("Data dalam queue : \n");

    if(!isEmpty()){
        for(int i=q.head;i<=q.tail;i++){
            printf("[%d]",q.data[i]);
        }
    }else{
        printf("[ ]");
    }

    printf("\nHead : %d",q.head);
    printf("\nTail : %d",q.tail);

}

int main()
{
    int pil;
    int data;

    bool stop = false;
    creatQueue();

    while(!stop){
        system("cls");
        tampil();
        printf("\n\n");
        printf("===========================\n");
        printf("=      PROGRAM QUEUE      =\n");
        printf("===========================\n");
        printf("= 1. ENQUEUE              =\n");
        printf("= 2. DEQUEUE              =\n");
        printf("= 3. CLEAR                =\n");
        printf("= 4. EXIT                 =\n");
        printf("===========================\n");
        printf("Masukkan pilihan :");
        scanf("%d",&pil);

        if(pil==1){
			printf("Masukkan Data : ");
			scanf("%d",&data);
			enqueue(data);
		}else if(pil==2){
			dequeue();
		}else if(pil==3){
			clear();
		}else{
			stop=true;
		}
    }
    return 0;
}


