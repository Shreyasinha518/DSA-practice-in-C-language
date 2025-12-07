#include <stdio.h>
#include <stdlib.h>

// 1. Define the structure for a tree node
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// 2. Function to create a new tree node
Node *createNode(int data)
{
    // Allocate memory for the new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    // Assign data and initialize children pointers
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 3. Recursive function to build the tree from user input (Pre-order method)
// Enter -1 when you want to stop creating a branch (i.e., the node is NULL).
Node *buildTree()
{
    int data;
    printf("Enter node data (or -1 for a NULL node): ");
    // Use an extra space in scanf format string to consume any leftover whitespace or newline
    if (scanf(" %d", &data) != 1)
    {
        // Handle input error
        printf("Invalid input. Please restart the program.\n");
        // Clear input buffer
        while (getchar() != '\n')
            ;
        return NULL;
    }

    // Base case: If the user enters -1, return NULL, signifying no node here.
    if (data == -1)
    {
        return NULL;
    }

    // Create the new node (Root)
    Node *root = createNode(data);

    // Recursively call for the left child
    printf("-> Entering LEFT child of %d:\n", data);
    root->left = buildTree();

    // Recursively call for the right child
    printf("-> Entering RIGHT child of %d:\n", data);
    root->right = buildTree();

    return root;
}

// 4. Pre-order Traversal (Root -> Left -> Right)
void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// 5. In-order Traversal (Left -> Root -> Right)
void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// 6. Post-order Traversal (Left -> Right -> Root)
void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

// 7. Function to free the memory (using Post-order method)
void deleteTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

int main()
{
    printf("--- Binary Tree Builder and Traversal ---\n");
    printf("Instructions: You will enter the node data one by one.\n");
    printf("Enter -1 when you want a node to have NO child (NULL).\n");
    printf("====================================================\n\n");

    // Build the tree from user input
    Node *root = buildTree();

    if (root == NULL)
    {
        printf("\nThe tree is empty. Program finished.\n");
        return 0;
    }

    printf("\n--- Tree Built Successfully! ---\n");
    printf("\n--- Traversal Menu ---\n");
    printf("1. Pre-order Traversal\n");
    printf("2. In-order Traversal\n");
    printf("3. Post-order Traversal\n");
    printf("4. Show All Traversals\n");
    printf("5. Exit\n");
   

    int choice;
    do
    {
         printf("Enter your choice: ");
        if (scanf(" %d", &choice) != 1)
        {
            printf("\nInvalid input. Please enter a number.\n");
        }

        printf("\n--- Traversal Results ---\n");

        // The requested switch-case structure for traversal output
        switch (choice)
        {
        case 1:
            printf("1. Pre-order (Root, Left, Right): ");
            preOrder(root);
            printf("\n");
            break;
        case 2:
            printf("2. In-order (Left, Root, Right): ");
            inOrder(root);
            printf("\n");
            break;
        case 3:
            printf("3. Post-order (Left, Right, Root): ");
            postOrder(root);
            printf("\n");
            break;

        case 4:
            printf("Exiting traversal menu.\n");
            break;
        default:
            printf("Invalid option. Please choose between 1 and 5.\n");
            break;
        }
    } while (choice != 5);

    // Clean up memory
    deleteTree(root);
    printf("Memory cleaned up. Program finished.\n");

    return 0;
}
