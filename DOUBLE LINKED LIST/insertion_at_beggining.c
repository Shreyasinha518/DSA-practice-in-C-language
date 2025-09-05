#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
    struct node*prev;

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
void insert_at_beg(struct node**head,int data){
    struct node*temp;
    struct node* newnode=create(data);
    if(*head==NULL){
        *head=newnode;
    }else{
    (*head)->prev=newnode;
    newnode->next=*head;
    *head=newnode;
    }
    return;


}
int main(){
    struct node*head=NULL;
    struct node*temp=NULL;
    int n,data;
    printf("ENTER ANUMBER OF NODES:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("ENTER THE DATA:",i+1);
        scanf("%d",&data);
        struct node*newnode=create(data);
        if(head==NULL){
            head=temp=newnode;
        }else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=temp->next;

        }

    }
    printf("ORIGINAL LIST:");
    display(head);
    printf("ENTER DATA TO BE INSERTED:");
    scanf("%d",&data);

    insert_at_beg(&head,data);
    printf("MODIFIED LIST;");
    display(head);
    return 0;


}
