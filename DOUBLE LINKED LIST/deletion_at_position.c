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
int count(struct node*head){
    struct node*temp=head;
    int c=0;
    while(temp!=NULL){
        temp=temp->next;
        c++;


    }
    return c;
}
void deletion_at_postion(struct node**head,int pos){
    struct node*temp;
    int ct=count(*head);
    if(pos<0||pos>ct){
        printf("INVALID POSITION");
        return;

    }else{
        temp=*head;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;

        }
        
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);

    }
    return;



}
int main(){
    struct node*head=NULL;
    struct node*temp=NULL;
    int n,data;
    int pos;
    printf("ENTER THE NUMBER OF NODES");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter data:",i+1);
        scanf("%d",&data);
        struct node*newnode=create(data);
        if(head==NULL){
            temp=head=newnode;
        }else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=temp->next;

            
        }

        }
        printf("ORIGINAL LIST IS :");
        display(head);
        printf("enter the position");
        scanf("%d",&pos);
        deletion_at_postion(&head,pos);
        printf("MODIFIED LIST IS:");
        display(head);
        return 0;
    }
