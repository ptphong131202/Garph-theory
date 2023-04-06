#include <stdio.h>
#define max 50

typedef struct
{
    int u, v;
} edge;

typedef struct
{
    int n, m;
    edge Edges[max];
} Graph;

typedef struct
{
    int size, data[max];
} List;

void makenullList(List *L)
{
    L->size = 0;
}

void pushList(List *L, int x)
{
    L->data[L->size] = x;
    L->size++;
}

int elementAt(List *L, int x)
{
    return L->data[x];
}

void init_Graph(Graph *G, int n)
{
    G->m = 0;
    G->n = n;
}

void add_Edge(Graph *G, int u, int v)
{
    int i;
    for (i = 0; i <= G->m; i++)
        if ((G->Edges[i].u == u && G->Edges[i].v == v) || (G->Edges[i].u == v && G->Edges[i].v == u))
            return;

    G->Edges[G->m].u = u;
    G->Edges[G->m].v = v;
    G->m++;
}

int adjacent(Graph *G, int u, int v)
{
    int i;
    for (i = 0; i <= G->m; i++)
        if ((G->Edges[i].u == u && G->Edges[i].v == v) || (G->Edges[i].u == v && G->Edges[i].v == u))
            return 1;
    return 0;
}

List neighbors(Graph *G, int u)
{
    List L;
    makenullList(&L);
    int v;
    for (v = 1; v <= G->n; v++)
        if (adjacent(G, u, v) == 1)
            pushList(&L, v);
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

void bfs(Graph *G, int x, int a[max])
{
    Queue Q;
    makenullQueue(&Q);
    int mark[max], i;

    for (i = 1; i <= G->n; i++)
        mark[i] = 0;

    push(&Q, x);
    printf("%d\n", x);
    mark[x] = 1;

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
                printf("%d\n", y);
                mark[y] = 1;
                push(&Q, y);
            }
        }
        a[x] = 1;
    }
}

int main()
{
    freopen("dothi.txt", "r", stdin);
    int n, m, i, u, v;
    Graph G;
    scanf("%d%d", &n, &m);
    init_Graph(&G, n);
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        add_Edge(&G, u, v);
    }

    int a[max];
    for (i = 1; i <= n; i++)
        a[i] = 0;
    for (i = 1; i <= n; i++)
        if (a[i] == 0)
            bfs(&G, i, a);
}