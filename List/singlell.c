#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
}*Head=NULL;
struct node* CreateNode(){
    struct node *new=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&new->data);
    new->next=NULL;
    return new;
} 
void Insert_Beg(){
    struct node *new=CreateNode();
    if(Head==NULL)
        Head=new;
    else{
        new->next=Head;
        Head=new;
    }    
}
void Delete_Beg(){
    struct node *temp=Head;
    if(Head==NULL)
        printf("Cannot Delete");
    else if(Head->next=NULL){
        printf("\nOnly one node exists,deleted %d",Head->data);
        Head=NULL;
        }
    else{
        printf("\nNode with %d deleted",Head->data);
        Head=Head->next;    
    }
    free(temp);
}
void Traversal(){
    struct node *temp=Head;
    if(Head==NULL)
        printf("\nList is Empty");  
    else{
        while(temp!=NULL){
            printf("%d-->",temp->data);
            temp=temp->next;
        } 
    }
}
void Insert_End(){
    struct node *new=CreateNode();
    struct node *temp=Head;
    if(Head==NULL)
        Head=new;
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new;
    }    

}
void Delete_End(){
    struct node *temp=Head;
    if(Head==NULL)
        printf("List is Empty.Cannot Delete");
    else if(Head->next==NULL){
        printf("Deleted data is %d",Head->data);
        free(temp);
    }
    else{
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        printf("\nDeleted data is %d\n",temp->next->data);
        struct node *temp1=temp->next;
        temp->next=NULL;
        free(temp1);
    }    
}
int CountNodes(){
    int count=0;
    struct node *temp=Head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}
void Insert_At_Position(){
    int k,i;
    printf("Enter position:");
    scanf("%d",&k); 
    int count=CountNodes();
    if(k<=0||k>count+1)
        printf("Invalid position,cannot insert");
    else if(Head==NULL||k==count+1)
        Insert_End(); 
    else if(k==1)
        Insert_Beg();       
    else{
        struct node *new=CreateNode();
        struct node *temp=Head; 
        for(int i=1;i<k-1;i++){
             temp=temp->next;
        }   
        new->next=temp->next;
        temp->next=new;
    }
}
void Delete_At_Position(){
    struct node *temp=Head;
    int k,i;
    printf("Enter position:");
    scanf("%d",&k);
    int count=CountNodes();
    if(k==1){
        Delete_Beg();
    }
    else if(k<=0||k>count){ 
        printf("Invalid position");
    }
    else{
        for(i=1;i<k-1;i++){
            temp=temp->next;
        }
        struct node *temp1=temp->next;
        temp->next=temp1->next;
        printf("Node with %d deleted\n",temp1->data);
        free(temp1);
    }   
}
int main(){
    int choice;
    while(1){
        printf("\n1.Insert Beginning\n2.Delete Beginning\n3.Display\n4.Insert at the End\n5.Delete at the End\n6.Insert at position\n7.Delete at Position\n8.Exit\nSelect operation to be done on the list:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                Insert_Beg();
                Traversal();
                break;
            case 2:
                Delete_Beg();
                Traversal();
                break;
            case 3:
                Traversal();
                break;
            case 4:
                Insert_End();
                Traversal();
                break;
            case 5:
                Delete_End();
                Traversal();
                break;
            case 6:
                Insert_At_Position();
                Traversal();
                break;
            case 7:
                Delete_At_Position();
                Traversal();
                break;
           case 8:
                exit(1);

        }
    }
    return 0;
}
