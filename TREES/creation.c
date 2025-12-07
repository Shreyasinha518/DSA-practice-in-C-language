#include <stdio.h>
#include <stdlib.h>

// Define the space increment for better visual separation
#define COUNT 5 

// Structure for a tree node
struct node {
    int data;
    struct node* right;
    struct node* left;
};

// ... (createNode function remains the same) ...
struct node *createNode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1); 
    }
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// ... (createTree function remains the same) ...
struct node *createTree() {
    int data;
    
    printf("Enter node data (-1 for no node/NULL): ");
    
    // Clear the input buffer before reading an int to prevent issues
    // with leftover newlines from previous inputs if an error occurred.
    // However, the original code is simple enough to proceed without this.
    if (scanf("%d", &data) != 1) {
        // Consume the rest of the line to prevent infinite loop
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return NULL;
    }
    
    if (data == -1) {
        return NULL;
    }
    
    struct node* root = createNode(data);
    
    printf("Enter left child of %d:\n", data);
    root->left = createTree();
    
    printf("Enter right child of %d:\n", data);
    root->right = createTree();
    
    return root;
}

// ... (freeTree function remains the same) ...
void freeTree(struct node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// --- CORRECTED DISPLAY FUNCTION ---
// New function to print the tree in a top-down, indented manner
void displayTree(struct node* root, int level) {
    if (root == NULL) {
        // Optional: print a placeholder for a NULL child
        // printf("\n"); // This makes spacing harder to manage
        return;
    }

    // 1. Print the current node with indentation
    // Indent by 'level' number of tabs/spaces
    for (int i = 0; i < level; i++) {
        printf("    "); // 4 spaces for a clean indent
    }
    
    // Print the node data. Use a visual indicator for non-root nodes.
    if (level > 0) {
        printf("-- ");
    }
    
    printf("%d\n", root->data);

    // 2. Recursively print the left subtree (increases level/indent)
    displayTree(root->left, level + 1);

    // 3. Recursively print the right subtree (increases level/indent)
    displayTree(root->right, level + 1);
}
// --- MAIN FUNCTION ---
int main() {
    struct node* root = NULL;
    int choice;
    
    printf("--- Binary Tree Menu ---\n");
    printf("Note: Use -1 to denote a NULL child during creation.\n");
    printf("Starting Tree Creation:\n");
    
    // Initial tree creation
    root = createTree();
    printf("--- Binary Tree Creation Complete ---\n");
    
    if (root == NULL) {
        printf("Tree is empty. Exiting.\n");
        return 0;
    }

    do {
        printf("\n--- TREE OPTIONS ---\n");
        printf("1. Display Tree Structure\n");
        printf("2. Exit and Free Memory\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            choice = 0; // Set to invalid choice
            // Clear input buffer for safe re-entry
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        switch (choice) {
            case 1:
                // Use the new, more descriptive header
                printf("\n--- VISUAL TREE STRUCTURE (Rotated 90 deg counter-clockwise) ---\n");
                // The root is passed with an initial space of 0
                displayTree(root, 0); 
                printf("\n------------------------------------------------------------------\n");
                break;
            case 2:
                printf("Exiting program. Freeing memory...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 2);

    // Clean up memory before exiting
    freeTree(root);
    
    return 0;
}
