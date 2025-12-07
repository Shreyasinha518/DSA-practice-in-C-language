#include<stdio.h>
#include<stdlib.h>
struct node{ //node created
    int data;
    struct node*next;
};
struct node*create_a_node(int data){ //created a new node
    struct node*newnode;
    newnode=(struct node*) malloc (sizeof(struct node ));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;


};
void insert_at_beggining(struct node**head,int data){//insert at beggonog
    struct node *newnode=create_a_node(data);
    

    newnode->next=*head;
    *head= newnode;
    return;


    

}
void display(struct node*head){ //displaying the node
    struct node*temp=head;


        printf("LINKED LIST:");
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->next;


        }
        printf("NULL\n");

    }
    int main(){ //the main function to call
        struct node*newnode=NULL;
        struct node*head=NULL;
        struct node*temp=NULL;
        int i=0;
        int n,data;
        printf("enter the number of nodes:");
        scanf("%d",&n);
        while(i<n){
            printf("enter data for node %d",i+1);
            scanf("%d",&data);
            newnode=create_a_node(data);
            if(head==NULL){ //first node link
            head =newnode;
            temp=head;
            }
            else{              //link other nodes
                temp->next=newnode;
                temp=temp->next;
                
            }

                i++;
            


            
        }
        printf("original list:");
        display(head);// call display
        printf("Enter data to be inserted: ");
        scanf("%d", &data);
        insert_at_beggining(&head, data);

        printf("Linked liat after insertion:");
        display(head);

        return 0;


    }








