#include <stdio.h>
#define max 50
typedef struct
{
    int n;
    int data[max][max];
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

int sort(List *L)
{
    return L->size;
}
void init_Graph(Graph *G, int n)
{
    G->n = n;
    int i, j;
    for (i = 1; i <= G->n; i++)
        for (j = 1; j <= G->n; j++)
            G->data[i][j] = 0;
}

void add_Edge(Graph *G, int u, int v)
{
    G->data[u][v] = 1;
    G->data[v][u] = 1;
}

int adjacent(Graph *G, int u, int v)
{
    return G->data[u][v] > 0;
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

int parent[max];

void bfs(Graph *G)
{
    Queue Q;
    makenullQueue(&Q);
    int mark[max], i;
    parent[1] = 0;

    for (i = 1; i <= G->n; i++)
        mark[i] = 0;
    for (i = 1; i <= G->n; i++)
    {
        if (mark[i] == 0)
            push(&Q, i);

        while (!empty(&Q))
        {
            int x = top(&Q);
            pop(&Q);
            mark[x] = 1;
            List L = neighbors(G, x);
            for (i = 0; i < L.size; i++)
            {
                int y = elementAt(&L, i);
                if (mark[y] == 0)
                {
                    mark[y] = 1;
                    push(&Q, y);
                    parent[y] = x;
                }
            }
        }
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

    bfs(&G);
    for (i = 1; i <= G.n; i++)
        printf("%d %d\n", i, parent[i]);
}