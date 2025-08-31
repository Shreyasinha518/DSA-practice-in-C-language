#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
    };
    struct node* create_node(int data){
        struct node*newnode;
        newnode=(struct node*) malloc (sizeof(struct node));
        if(newnode==NULL){
            printf("Dynamic memory allocation failed");
            exit(1);

        }
        newnode->data=data;
        newnode->next=NULL;
        return newnode;
    };
    void display(struct node* head){
        struct node* temp=head;
        
        while (temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->next;
            

        }
        printf("NULL \n");
    }



    // Helper function to count the number of nodes in the list
int count_nodes(struct node* head) {
    int count = 0;
    struct node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to insert a node at a specific position
void insert_at_position(struct node** head, int data, int pos) {
    int count = count_nodes(*head);
    
    // Check if the position is valid
    if (pos < 1 || pos > count + 1) {
        printf("Invalid position. The list has %d nodes. Please choose a position between 1 and %d.\n", count, count + 1);
        return;
    }
    
    struct node* newnode = create_node(data);
    
    
    // Case 2: Insert at any other position
    
        struct node* temp = *head;
        // Traverse to the node *before* the insertion point
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }


int main() {
    struct node* head = NULL;
    struct node* temp = NULL;
    int i, data, n, pos;

    printf("Enter the number of nodes to create initially: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    // Loop to create the initial linked list
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        struct node* newnode = create_node(data);
        
        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = temp->next;
        }
    }
    
    printf("\nOriginal list: ");
    display(head);
    
    printf("\nEnter the data to be inserted: ");
    scanf("%d", &data);
    
    printf("Enter the position to insert at: ");
    scanf("%d", &pos);
    
    insert_at_position(&head, data, pos);
    
    printf("\nModified list: ");
    display(head);
    
    return 0;
}
    