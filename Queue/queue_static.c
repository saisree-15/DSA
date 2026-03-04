#include <stdio.h>
#include <stdlib.h>
#define MAX 50
int front=-1,rear=-1;
int queue[MAX];
int isFull(){
    if(rear==MAX-1)
        return 1;
    else
        return 0;
}
int isEmpty(){
    if(rear==-1)
        return 1;
    else    
        return 0;
}
void ENQUEUE(int val){
    if(isEmpty()){
        rear++;
        front++;
        queue[rear]=val;
    }
    else if(isFull())
        printf("\nQueue Overflow.Cannot Be inserted");
    else
        queue[++rear]=val;
    
}
int DEQUEUE(){
    int val;
    if(isEmpty()){
        printf("\nStack Underflow.Cannot be Deleted\n");
        return -1;
    }
    else if(front==rear){
        val=queue[front];
        front=-1;
        rear=-1;
    }    
    else
        return queue[front++];
}
void Display(){
    if(isEmpty()){
        printf("Queue is Empty");
    }
    else{
        for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
        }
        printf("\n");
    }
}
int main(){
    int data,choice,v;
    while(1){
        printf("\nSelect operation to be done on queue:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter data to be inserted:");
                scanf("%d",&data);
                ENQUEUE(data);
                Display();
                break;
            case 2:
                v=DEQUEUE();
                if(v!=-1){
                printf("Deleted data is %d\n",v);
                }
                Display();
                break;
            case 3:
                Display();
                break;
            case 4:
                exit(-1);    
    }
    }
    return 0;
}
