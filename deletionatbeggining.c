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
void deletion_at_beggining(struct node**head){
    struct node*temp;
    
    if(head==NULL){
        printf("the list is empty");

    }else{
         temp=*head;
        *head=temp->next;
    
        free(temp);


    }
    return;

}
int main(){
    struct node*head=NULL;
    struct node*temp=NULL;
    int n,data;
    printf("enter number of nodes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter the data:",i+1);
        scanf("%d",&data);
        struct node*newnode=create(data);
        if(head==NULL){
            head=newnode;
            temp=head;

        }else{
            temp->next=newnode;
            temp=temp->next;

        }

        
    }
    printf("the original list:\n");
    display(head);
    deletion_at_beggining(&head);
    printf("the deleted data:\n");
    display(head);
    return 0;


}

