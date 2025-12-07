#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*create(int data){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;

};
void deletion_at_end(struct node**tail){
    struct node*current;
    struct node* previous;
    current=(*tail)->next;
    if(*tail==NULL){
        printf("LIST IS EMPTY");

    }else if(current->next==current){
        *tail=NULL;
        free(current);
    }else{
        while(current->next!=(*tail)->next){
            previous=current;
            current=current->next;
        }
        previous->next=(*tail)->next;
        (*tail)=previous;
        free(current);
        

    }
    return;
}


void display(struct node*tail){
    struct node*temp=tail;
    if(tail==NULL){
        printf("LIST IS EMPTY");}
        else{
            temp=tail->next;
            while(temp->next!=tail->next){
                printf("%d->",temp->data);
                temp=temp->next;
            }
        }
            printf("%d",temp->data);
        
        
            return;
    }
    int main(){
        struct node*tail=NULL;
        int n,data;
        printf("ENTER THE NUMBER OF NODES:");
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            printf("ENTER THE DATA:",i+1);
        scanf("%d",&data);
        struct node*newnode=create(data);
        if(tail==NULL){
            tail=newnode;
            tail->next=newnode;
        }
        else
        {
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;

        }
    }
    printf("ORIGINAL LSIT:\n");
    display(tail);
    deletion_at_end(&tail);
    printf("MODIFIED LSIT:\n");
    display(tail);
    return 0;
 }
        
