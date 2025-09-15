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
};
void display(struct node*head){
    struct node*temp;
    temp=head;
    while(temp!=NULL){
        printf("%d<-->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");

}
void reverse(struct node**head,struct node**tail){
    struct node*currentnode;
    struct node* nextnode;
    currentnode=*head;
    while(currentnode!=NULL){
        nextnode=currentnode->next;
        currentnode->next=currentnode ->prev;
        currentnode->prev=nextnode;
        currentnode=nextnode;

    }
    currentnode=*head;
    *head=*tail;
    *tail=currentnode;
    return;



}
int main(){
    struct node*head=NULL;
    struct node*tail=NULL;
    int n,data;
    printf("enter the number of nodes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter data:",i+1);
        scanf("%d",&data);
        struct node*newnode=create(data);
        if(head==NULL){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
            
        
    }
}
printf("THE DOUBLY LINKED LIST IS:");
display(head);
reverse(&head,&tail);
printf("THE REVERSED DOUBLY LINKED LIST:");
display(head);
return 0;
}
