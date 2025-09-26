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
    

};
void reverse(struct node**tail){
    struct node*current;
    struct node*previous;
    struct node*nextnode;
    current=(*tail)->next;
    nextnode=current->next;
    if((*tail)==NULL){
        printf("LIST IS EMPTY");


    }else{
        while(current!=(*tail)){
            previous=current;
            current=nextnode;
            nextnode=current->next;
            current->next=previous;

        }
        nextnode->next=(*tail);
        (*tail)=nextnode;

    }
    return;
}
void display(struct node*tail){
    struct node*temp=tail;
    if (tail==NULL){
        printf("LIST IS EMPTY");
    } else {temp=tail->next;
        while(temp->next!=tail->next){
            printf("%d->",temp->data);
            temp=temp->next;
        }
    }
        printf("%d",temp->data);
    
     

    
    printf("NULL\n");
}
int main(){
    
    struct node*tail=NULL;
    int n,data;
    printf("ENTER THE NUMBER OF NODES:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter the data:",i+1);
        scanf("%d",&data);
        struct node*newnode=create(data);
       if (tail==NULL){
        tail=newnode;
        tail->next=newnode;
       }else{
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
       }
    }
        printf(" this shows that link is circularly connected  %d \n",tail->next->data);
        printf("THE CIRCULAR SINGLE LINKED LIST IS:");
        display(tail);
        reverse(&tail);
        printf("THE CIRCULAR SINGLE LINKED LIST AFTER BEING REVERSED IS:");
        display(tail);
        return 0;

    }






