#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*prev;
    struct node*next;

};
struct node*create(int data){
    
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
};
void display(struct node*head){
    struct node*temp=head;
    while(temp!=NULL){
        printf("%d<->",temp->data);
        temp=temp->next;

    }
    printf("NULL/n");
}
void deletion_at_end(struct node**head,struct node**tail){
    struct node*temp;
    if(*head==NULL){
        printf("List is empty");

    }else{
        temp=*tail;
        (*tail)->prev->next=NULL;
        *tail=(*tail)->prev;
        free(temp);

    }
    return;
}int main(){
    struct node*head=NULL;
    struct node*tail=NULL;
    int n,data;
    printf("ENTER NUMBER OF NODES");
        scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("ENTER DATA",i+1);
        scanf("%d",&data);
        struct node*newnode=create(data);
        if(head==NULL){
            head=tail=newnode;
        }else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
    }
    printf("ORIGINAL DOUBLY LINKED LIST IS:");
    display(head);
    deletion_at_end(&head,&tail);
    printf("MODIFIED LIST AFTER DELETION:");
    display(head);
    return 0;
}
