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
int count(struct node*head){
    struct node*temp=head;
    int c=0;
    while(temp!=NULL){
    
        temp=temp->next;
        c++;

    }
    return c;
}
void insertion_at_pos(struct node**head,int data,int pos){
    struct node*newnode=create(data);
    struct node*temp=*head;
    int ct=count(*head);
    if(pos<1||pos>ct+1){
        printf("INVALID POSITION");

    return;}
    if(pos==1){
        if(*head==NULL){
        *head=newnode;
    }else{
    (*head)->prev=newnode;
    newnode->next=*head;
    *head=newnode;
    }
    return;}

    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    newnode->prev=temp;
    newnode->next=temp->next;
    temp->next=newnode;
    newnode->next->prev=newnode;
}
    





int main(){
    struct node*head=NULL;
    struct node*temp=NULL;
    int n,data,pos;
    printf("enter the number of nodes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter data:",i+1);
        scanf("%d",&data);
        struct node*newnode=create(data);
        if(head==NULL){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
            
        
    }
}
printf("THE DOUBLY LINKED LIST IS:");
display(head);
printf("ENTER THE DATA TO BE INSERTED:\n");
scanf("%d",&data);
printf("ENTER THE POSITION:\n");
scanf("%d",&pos);
insertion_at_pos(&head,data,pos);
printf("MODIFIED LIST:");
display(head);

return 0;
}