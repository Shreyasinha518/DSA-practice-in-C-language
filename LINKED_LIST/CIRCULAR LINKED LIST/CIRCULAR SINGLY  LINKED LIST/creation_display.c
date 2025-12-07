#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;

};
struct node*create(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
    

}
void display(struct node*head){
    struct node*temp=head;
    while(temp->next!=head){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
    printf("NULL\n");
}
int main(){
    struct node*head=NULL;
    struct node*temp=NULL;
    int n,data;
    printf("ENTER THE NUMBER OF NODES:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter the data:",i+1);
        scanf("%d",&data);
        struct node*newnode=create(data);
        if(head==NULL){
            head=temp=newnode;
        }else{
            temp->next=newnode;
            temp=temp->next;

        }
        temp->next=head;
        }
        printf(" this shows that link is circularly connected  %d \n",temp->next->data);
        printf("THE CIRCULAR SINGLE LINKED LIST IS:");
        display(head);

    }


