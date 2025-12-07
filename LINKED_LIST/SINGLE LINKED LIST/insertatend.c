#include<stdio.h>
#include<stdlib.h>
struct Node {    //constructed a node
    int data;
    struct Node *next;

};
struct Node* create_a_node(int data){   //created a new node
    struct Node* newnode;
    newnode=(struct Node*) malloc (sizeof(struct Node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
};
void insert_at_end( struct Node ** head,int data){

    struct Node*newnode;
    newnode=create_a_node(data);
    
    struct Node*temp=*head;

    newnode->next=NULL;
    while(temp->next!=0){
        temp=temp->next;
    }
        
     temp->next=newnode;


}
void display(struct Node *head){
    struct Node* temp=head;
    printf("LINKED LIST:");
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;

    }
    

    printf("NULL \n");

}

int main(){
    struct Node*newnode=NULL;
    struct Node*head=NULL;
    struct Node*temp=NULL;
    int i=0,data,n;
    printf("enter the no.of nodes:");
    scanf("%d",&n);
    while (i<n){
        printf("enter the datas:%d",i+1);
        scanf("%d",&data);
        newnode=create_a_node(data);
        if(head==NULL){
            head=newnode;
            temp=head;

        }
        else{
            temp->next=newnode;
            temp=temp->next;

        }
        i++;


    }
    printf("original list:");
    display(head);
    printf("enter the data to be inserted:");
    scanf("%d",&data);
    insert_at_end(&head,data);
    printf("modified list is:");
    display(head);
    return 0;

    
    

}
