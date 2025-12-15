//Write a program to implement insertion, deletion and traversal  of an AVL tree.




#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};


int max(int a, int b) {
    return (a > b) ? a : b;
}


int getHeight(struct Node* n) {
    if (n == NULL)
        return 0;
    return n->height;
}


struct Node* createNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; 
}


struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    // Return new root
    return x;
}


struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    
    y->left = x;
    x->right = T2;

    
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    
    return y;
}


int getBalance(struct Node* n) {
    if (n == NULL)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}


struct Node* insert(struct Node* node, int key) {
    // Normal BST insertion
    if (node == NULL)
        return createNode(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node; // Duplicate keys not allowed

    
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    
    int balance = getBalance(node);

    

    
    if (balance > 1 && key < node->left->data)
        return rightRotate(node);

   
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);

    
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}


struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}


struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        
        if ((root->left == NULL) || (root->right == NULL)) {
            struct Node* temp = root->left ? root->left : root->right;

            if (temp == NULL) { // No child
                temp = root;
                root = NULL;
            } else // One child
                *root = *temp; 

            free(temp);
        } else {
            
            struct Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    
    if (root == NULL)
        return root;

   
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    
    int balance = getBalance(root);

    
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

   
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}


void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}


void display(struct Node* root) {
    if (root == NULL) {
        printf("\nThe tree is empty!\n");
        return;
    }
    printf("\n--- Tree Traversals ---\n");
    printf("Inorder   : ");
    inorder(root);
    printf("\nPreorder  : ");
    preorder(root);
    printf("\nPostorder : ");
    postorder(root);
    printf("\n");
}


int main() {
    struct Node* root = NULL;
    int choice, value;
     	printf("\n AVL Tree Menu \n");
        printf("1. Insert a Node\n");
        printf("2. Delete a Node\n");
        printf("3. Display Traversals\n");
        printf("4. Exit\n");
        
    while (1) {
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d inserted successfully.\n", value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("%d deleted (if present) successfully.\n", value);
                break;
            case 3:
                display(root);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

