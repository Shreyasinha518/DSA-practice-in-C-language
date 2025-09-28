#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the stack
#define MAX_SIZE 5


void push(int stack[], int *top) {
    int item;

    printf("\n--- PUSH OPERATION ---\n");
    
   
    if (*top == MAX_SIZE - 1) {
        printf("ERROR: STACK OVERFLOW. Cannot push element (Max Size: %d).\n", MAX_SIZE);
        return;
    }

    printf("Enter the integer element to be inserted: ");
    scanf("%d",&item);
    
    (*top)++;
    stack[*top] = item;
    
}


void pop(int stack[], int *top_ptr) {
    printf("\n--- POP OPERATION ---\n");
    
    
    if (*top_ptr == -1) {
        printf("ERROR: STACK UNDERFLOW. Stack is empty.\n");
        return;
    }

    
    int item = stack[*top_ptr];
    (*top_ptr)--;
    printf("SUCCESS: Deleted item is %d.\n", item);
}


void peek(const int stack[], const int *top_ptr) {
    printf("\n--- PEEK OPERATION ---\n");
    
    // Check for Stack Underflow
    if (*top_ptr == -1) {
        printf("ERROR: STACK UNDERFLOW. Stack is empty.\n");
        return;
    }
    
    // Peek operation
    printf("SUCCESS: Top item is %d.\n", stack[*top_ptr]);
}


void display(const int stack[], const int *top) {
    printf("\n--- STACK CONTENTS ---\n");
    
    if (*top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Elements (Top -> Bottom):\n");
        // Iterate from the current top index down to 0
        for (int i = *top; i >= 0; i--) {
            printf("| %d |\n", stack[i]);
            if (i > 0) {
                 printf("-----\n"); // Separator between elements
            }
        }
        printf("----\n");
    }
}



int main() {
    int choice;
    
    
    int myStack[MAX_SIZE];
    int top = -1; 
    
    printf("==================================\n");
    printf("      STACK OPERATIONS (Max Size: %d)\n", MAX_SIZE);
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
                // Pass the array (by address) and the address of 'top'
                push(myStack, &top); 
                break;
            case 2:
                // Pass the array (by address) and the address of 'top'
                pop(myStack, &top); 
                break;
            case 3:
                // Pass the array (by address) and the address of 'top'
                peek(myStack, &top);
                break;
            case 4:
                // Pass the array (by address) and the address of 'top'
                display(myStack, &top);
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
