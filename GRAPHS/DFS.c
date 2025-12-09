// Write a program to implement DFS.


#include <stdio.h>
#include <stdlib.h>


struct Node {
    int vertex;
    struct Node* next;
};


struct List {
    struct Node* head;
};


struct Graph {
    int numVertices;
    struct List* adjLists;
    int* visited;
};


struct StackNode {
    int data;
    struct StackNode* next;
};


struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}


struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct List*)malloc(vertices * sizeof(struct List));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i].head = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}


void addEdge(struct Graph* graph, int src, int dest) {
    
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src].head;
    graph->adjLists[src].head = newNode;

    
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest].head;
    graph->adjLists[dest].head = newNode;
}


void push(struct StackNode** top, int value) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

int isEmpty(struct StackNode* top) {
    return top == NULL;
}

int pop(struct StackNode** top) {
    if (isEmpty(*top)) return -1;

    struct StackNode* temp = *top;
    int popped = temp->data;
    *top = temp->next;
    free(temp);
    return popped;
}


void DFS(struct Graph* graph, int startVertex) {
    struct StackNode* stack = NULL;

    push(&stack, startVertex);

    while (!isEmpty(stack)) {
        int currentVertex = pop(&stack);

        if (graph->visited[currentVertex] == 0) {
            printf("%d ", currentVertex);
            graph->visited[currentVertex] = 1;
        }

        struct Node* temp = graph->adjLists[currentVertex].head;

        
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0)
                push(&stack, adjVertex);
            temp = temp->next;
        }
    }
}


void displayGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjLists[v].head;
        printf("\nAdjacency list of vertex %d:\n head ", v);
        while (temp) {
            printf("-> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}


int main() {
    int vertices, edges;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge (src dest): ");
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("\nAdjacency List Representation:");
    displayGraph(graph);

    int startVertex;
    printf("\nEnter starting vertex for DFS: ");
    scanf("%d", &startVertex);

    printf("\nDFS traversal (using stack) starting from vertex %d:\n", startVertex);
    DFS(graph, startVertex);

    return 0;
}

