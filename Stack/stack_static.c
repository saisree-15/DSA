#include <stdio.h>
#include <stdlib.h>
#define MAX 50
int top=-1,STACK[MAX];
int isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;    
}
int isFull(){
    if(top==MAX-1)
        return 1;
    else
        return 0;    
}
void PUSH(int val){
    if(isFull())
        printf("\nStack Overflow.Cannot Insert");
    else{
        STACK[++top]=val;
    }
}
int POP(){
    if(isEmpty()){
        return -1;
    }
    else{
        int data=STACK[top];
        top--;
        return data;
    }
}
void Traversal(){
    if(isEmpty())
        printf("\nStack is Empty");
    else{
        int i;
        for(i=top;i>=0;i--){
            printf("%d ",STACK[i]);
        }
    }
}
int main(){
    int value,v,choice;
    while(1){
    printf("\nSelect the operation to be done on Stack:\n1.Push\n2.Pop\n3.Print\n4.Exit\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter data to be inserted:");
            scanf("%d",&value);
            PUSH(value);
            Traversal();
            break;
        case 2:
            v=POP();
            if(v==-1)
                printf("\nStack Underflow.Cannot Delete");
            else{
                printf("\nDeleted Data is:%d\n",v);
                Traversal();
            }
            break;
        case 3:
            Traversal();
            break;
        case 4:
            exit(-1);
    }
    }
    return 0;
}
