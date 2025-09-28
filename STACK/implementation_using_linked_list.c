#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*link;

};
struct node *create(int data){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->link=NULL;
    return newnode;


};
void push(struct node**top,int data){
    struct node*newnode=create(data);
    newnode->link=*top;
    *top=newnode;
    return;

}
void pop(struct node**top){
    struct node*temp=*top;
    if(*top==NULL){
        printf("STACK UNDERFLOW");
        
    }else{
         temp=*top;
        *top=temp->link;
        printf("The popped element is %d.",temp->data);
    
        free(temp);


        }
    
return;

}
void peek(struct node**top){
    struct node*temp=*top;
    if(*top==NULL){
        printf("STACK UNDERFLOW");
        
    }else{
        
      printf("The peeked element is %d .",temp->data);
    
      

        }
    
return;

}
void display(struct node*top){
    struct node*temp=top;
    if(top==NULL){
        printf("UNDERFLOW STACK");

    }else{
        while(temp!=NULL){
            printf("|%d|\n",temp->data);
            printf("-----\n");
            temp=temp->link;
        
            
        }
    }
        printf("----\n");
        }

    int main(){
    struct node* top= NULL;
    struct node* temp = NULL;
   
    int data;
    int choice;
    printf("==================================\n");
    
    printf("==================================\n");
    printf("1: Push (Insert element)\n");
    printf("2: Pop (Delete top element)\n");
    printf("3: Peek (View top element)\n");
    printf("4: Display (View all elements)\n");
    printf("5: Exit\n");
    printf("----------------------------------\n");

    
      
    do {
        printf("\nEnter choice (1-5): ");
        scanf("%d",&choice);
        
        

        switch (choice) {
            case 1:
                printf("enter the element to be inerted: ");
                scanf("%d",&data);
                push(&top,data);
                break;
            case 2:
                
                pop( &top); 
                break;
            case 3:
                
                peek( &top);
                break;
            case 4:
               
                display(top);
                break;
            case 5:
                printf("\nExiting program. Goodbye!\n");
                break;
            default:
                printf("\nINVALID CHOICE. Please select a number from 1 to 5.\n");
        }
    } while (choice != 5);

    return 0;
}


