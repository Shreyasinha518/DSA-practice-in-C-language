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
void reverse(struct node**head){
    struct node*currentnode;
    struct node*prevnode;
    struct node* nextnode;
    prevnode=NULL;
    currentnode=nextnode=*head;


    while(nextnode!=NULL){
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;

    }
    *head=prevnode;

        return;
    }
    int main(){
        struct node*head=NULL;
        struct node*temp=NULL;
        int n,data;
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
        reverse(&head);
        printf("modified list:");
        
        display(head);
        return 0;


    }




