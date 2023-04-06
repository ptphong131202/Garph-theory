#include <stdio.h>

#define max 50

typedef struct
{
    int u, v;
} edge;

typedef struct
{
    int n, m;
    edge A[max];
} Graph;

typedef struct
{
    int data[max];
    int size;
} List;

void makenullList(List *L) { L->size = 0; }
void pushList(List *L, int x)
{
    L->data[L->size] = x;
    L->size++;
}

int elementAt(List *L, int x) { return L->data[x]; }

void init_graph(Graph *G, int n)
{
    G->m = 0;
    G->n = n;
}

void add_edge(Graph *G, int u, int v)
{
    int i;
    for (i = 0; i <= G->m; i++)
        if ((G->A[i].u == u && G->A[i].v == v) || (G->A[i].u == v && G->A[i].v == u))
            return;

    G->A[G->m].u = u;
    G->A[G->m].v = v;
    G->m++;
}

int adjacent(Graph *G, int u, int v)
{
    int i;
    for (i = 0; i <= G->m; i++)
        if ((G->A[i].u == u && G->A[i].v == v) || (G->A[i].u == v && G->A[i].v == u))
            return 1;
    return 0;
}

List neighbors(Graph *G, int x)
{
    List L;
    makenullList(&L);
    int i;
    for (i = 1; i <= G->n; i++)
        if (adjacent(G, x, i) == 1)
            pushList(&L, i);
    return L;
}

typedef struct
{
    int front, rear, data[max];
} Queue;

void makenullQueue(Queue *Q)
{
    Q->front = 0;
    Q->rear = -1;
}

void push(Queue *Q, int x)
{
    Q->rear++;
    Q->data[Q->rear] = x;
}

int top(Queue *Q)
{
    return Q->data[Q->front];
}

void pop(Queue *Q)
{
    Q->front++;
}

int empty(Queue *Q)
{
    return Q->front > Q->rear;
}

int bfs(Graph *G)
{
    Queue Q;
    makenullQueue(&Q);
    int mark[max], i;
    int count = 0;
    for (i = 1; i <= G->n; i++)
        mark[i] = 0;
    push(&Q, 1);
    count = 1;
    mark[1] = 1;
    while (!empty(&Q))
    {
        int x = top(&Q);
        pop(&Q);

        List L = neighbors(G, x);
        for (i = 0; i < L.size; i++)
        {
            int y = elementAt(&L, i);
            if (mark[y] == 0)
            {
                count++;
                mark[y] = 1;
                push(&Q, y);
            }
        }
    }
    return count;
}

int main()
{
    freopen("dothi.txt", "r", stdin);
    Graph G;
    int n, m, i, u, v;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    if (bfs(&G) == G.n)
    {
        printf("DUOC");
    }
    else
        printf("KHONG");
}