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
    return newnode;
};
void display(struct node*head){
    struct node*temp=head;
    while(temp!=NULL){
        printf("%d<->",temp->data);
        temp=temp->next;

    }
    printf("NULL/n");
}
void insert_at_end(struct node**tail,struct node**head,int data){
    struct node*newnode=create(data);
    if(*head==NULL){
        *head=*tail=newnode;
    }else{
    (*tail)->next=newnode;
    newnode->prev=*tail;
    *tail=newnode;
    }
    return;

    
}
int main(){
    struct node*head=NULL;
    
    struct node*tail=NULL;
    int n,data;
    printf("ENTER ANUMBER OF NODES:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("ENTER THE DATA:",i+1);
        scanf("%d",&data);
        struct node*newnode=create(data);
        if(head==NULL){
            head=tail=newnode;
        }else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=tail->next;

        }

    }
    printf("ORIGINAL LIST:");
    display(head);
    printf("ENTER DATA TO BE INSERTED:");
    scanf("%d",&data);

    insert_at_end(&tail,&head,data);
    printf("MODIFIED LIST;");
    display(head);
    return 0;


}
