#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Struktur untuk queue
struct Queue {
    int items[MAX];
    int front;
    int rear;
};

typedef struct Queue Queue;

// Inisialisasi queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Mengecek apakah queue kosong
int isEmpty(Queue *q) {
    return (q->rear == -1);
}

// Mengecek apakah queue penuh
int isFull(Queue *q) {
    return (q->rear == MAX - 1);
}

// Menambahkan elemen ke dalam queue
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue penuh\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Menghapus elemen dari queue
int dequeue(Queue *q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue kosong\n");
        return -1;
    }
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

// Struktur untuk graph
struct Graph {
    int numVertices;
    int **adjMatrix;
    int *visited;
};

typedef struct Graph Graph;

// Membuat graph
Graph *createGraph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjMatrix = (int **)malloc(vertices * sizeof(int *));
    graph->visited = (int *)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int *)malloc(vertices * sizeof(int));
        graph->visited[i] = 0;
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

// Menambahkan edge ke graph
void addEdge(Graph *graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

// Melakukan BFS
void bfs(Graph *graph, int startVertex) {
    Queue q;
    initQueue(&q);

    graph->visited[startVertex] = 1;
    enqueue(&q, startVertex);

    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("Visited %d\n", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !graph->visited[i]) {
                graph->visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
}

int main() {
    Graph *graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    bfs(graph, 0);

    return 0;
}
