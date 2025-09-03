#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*prev;
    struct node*next;

};
struct node*create(int data){
    struct node* newnode;
    newnode=(struct node*) malloc(sizeof(struct node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
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
int main(){
    struct node*head=NULL;
    struct node*temp=NULL;
    int n,data;
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
return 0;
}
