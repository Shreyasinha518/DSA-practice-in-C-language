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
int count(struct node*tail){
    struct node*temp=tail;
    int c=0;
            temp=tail->next;
            while(temp->next!=tail->next){
                
                temp=temp->next;
                c++;
}
return c;
}

void deletion_at_position(struct node**tail,int pos){
    struct node*currentnode;
    struct node*nextnode;
    int ct=count(*tail);
    if(pos<1||pos>ct){
        printf("INVALID POSITION");
    }else{
        currentnode=(*tail)->next;
        for(int i=0;i<pos-1;i++){
            currentnode=currentnode->next;
        }
        nextnode=currentnode->next;
        currentnode->next=nextnode->next;
        free(nextnode);


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
        int n,data,pos;
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
        printf("ORIGINAL LIST\n");
        display(tail);
        
        
        printf("ENTER THE POSITION:\n");
        scanf("%d",&pos);
        deletion_at_position(&tail,pos);
        display(tail);
        return 0;





        

    }
        
    