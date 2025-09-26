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
newnode->next=NULL;
newnode->prev=NULL;
return newnode;
};
void insertion_at_end(struct node**head,struct node**tail,int data){
    struct node*newnode=create(data);
    if(*head==NULL){
            *head=*tail=newnode;
            (*head)->prev=*head;
            (*head)->next=*head;
        }
        else{
            newnode->prev=*tail;
            (*tail)->next=newnode;
            newnode->next=*head;
            (*head)->prev=newnode;
            *tail=newnode;
        }
        return;

}
void display(struct node*head,struct node*tail){
    struct node* temp;
    
    if(head==NULL){
        printf("LIST IS EMPTY");
    }else{
        temp=head;
        while(temp!=tail){
            printf("<-%d->",temp->data);
            temp=temp->next;
        }
        printf("%d->",temp->data);
    
    }
    printf("NULL\n");
}
int main(){
    struct node*head=NULL;
    struct node*tail=NULL;
    int n,data;
    printf("enter the number of node:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter data:",i+1);
        scanf("%d",&data);
        struct node*newnode=create(data);
        if(head==NULL){
            head=tail=newnode;
            head->prev=head;
            head->next=head;
        }else{
            tail->next=newnode;
            newnode->prev=tail;
            newnode->next=head;
            head->prev=newnode;
            tail=newnode;

        }

    }
    printf("THE DOUBLY CIRCULAR LINKED LIST IS:");
    display(head,tail);
    
    printf("enter the data to be inserted:");
    scanf("%d",&data);
    insertion_at_end(&head,&tail,data);
    printf("THE MODIFIED DOUBLY CIRCULAR LINKED LIST IS:");
    display(head,tail);
    return 0;
    

}
