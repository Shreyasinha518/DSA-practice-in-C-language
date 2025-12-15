#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};


struct Node* newNode(char data) {
    struct Node* node = malloc(sizeof *node);  
    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}


struct Stack {
    struct Node* arr[100];
    int top;
};

void initStack(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, struct Node* node) {
    if (s->top == 99) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->arr[++s->top] = node;
}

struct Node* pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->arr[s->top--];
}


struct Node* buildExpressionTree(char postfix[]) {
    struct Stack s;
    initStack(&s);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (ch == ' ') continue; 

        if (isalnum(ch)) {  
            push(&s, newNode(ch));
        } else { 
            struct Node* node = newNode(ch);
            node->right = pop(&s);
            node->left = pop(&s);
            push(&s, node);
        }
    }

    return pop(&s);
}

void inorder(struct Node* root) {
    if (!root) return;
    if (root->left || root->right) printf("(");
    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right);
    if (root->left || root->right) printf(")");
}

void preorder(struct Node* root) {
    if (!root) return;
    printf("%c", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c", root->data);
}


int main() {
    char postfix[100];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    struct Node* root = buildExpressionTree(postfix);

    printf("\nInorder (infix): ");
    inorder(root);

    printf("\nPreorder (prefix): ");
    preorder(root);

    printf("\nPostorder (postfix): ");
    postorder(root);

    return 0;
}
