#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node *create(int data){
    struct node*newnode;
    newnode=(struct node*) malloc (sizeof(struct node));
    if(newnode==NULL){
        printf("invalid memmory allocatio\n");
        exit(1);
    }
    newnode->data=data;
    newnode->next=NULL;
    return newnode;

};
void display(struct node*head){
    struct node*temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
    
        temp=temp->next;
    }
        


    
    printf("NULL\n");
}
void deletion_at_position(struct node**head,int pos){
    struct node*temp;
    struct node*nextnode;
    temp=*head;
    for(int i=0;i<pos-1;i++){
        temp=temp->next;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    free(nextnode);
return;
    }
    
int main(){
        struct node*head=NULL;
        struct node*temp=NULL;
        int n,data,pos;
        printf("enter the number of nodes:");
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            
            printf("enter data%d",i+1);
            scanf("%d->",&data);
            struct node*newnode=create(data);
            if(head==NULL){
                head=newnode;
                temp=head;

            }else{
                temp->next=newnode;
                temp=temp->next;
            }


        }
        printf("original list:");
        display(head);
        printf("enter the position:");
        scanf("%d",&pos);
        deletion_at_position(&head,pos);
        printf("modified list:");
        
        display(head);
        return 0;


    }




