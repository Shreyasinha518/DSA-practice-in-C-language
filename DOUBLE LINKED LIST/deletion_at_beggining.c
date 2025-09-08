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
void delete_at_begginig(struct node**head){
    struct node* temp;
    if(*head==NULL){
        printf("THE DOUBLY LINKED LIST IS EMPTY");
    }else{
        temp=*head;
        *head=temp->next;
        (*head)->prev=NULL;
            return (temp);
    }

}
int main(){
    struct node*head=NULL;
    struct node*temp=NULL;
    int n,data;
    printf("ENTER NUMBER OF NODES");
        scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("ENTER DATA",i+1);
        scanf("%d",&data);
        struct node*newnode=create(data);
        if(head==NULL){
            head=temp=newnode;
        }else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
    }
    printf("ORIGINAL DOUBLY LINKED LIST IS:");
    display(head);
    delete_at_begginig(&head);
    printf("MODIFIED LIST AFTER DELETION:");
    display(head);
    return 0;
}