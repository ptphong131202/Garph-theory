#include <stdio.h>
typedef struct
{
    int n;
    int A[100][100];
} Graph;
typedef struct
{
    int data[100];
    int n;
} List;
void makenullList(List *L)
{
    L->n = 0;
}
void push_back(List *L, int x)
{
    L->data[L->n] = x;
    L->n++;
}
int Element(List *L, int i)
{
    return L->data[i - 1];
}
int sort_List(List *L)
{
    return L->n;
}
typedef struct
{
    int data[100];
    int front, rear;
} Queue;
void makenull_Queue(Queue *Q)
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
void init_graph(Graph *G, int n)
{
    int i, j;
    G->n = n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            G->A[i][j] = 0;
}
void add_edge(Graph *G, int x, int y)
{
    G->A[x][y] = 1;
    G->A[y][x] = 1;
}
int adjacent(Graph *G, int x, int y)
{
    return G->A[x][y];
}
List neighbors(Graph *G, int x)
{
    List L;
    int i, n;
    makenullList(&L);
    n = G->n;
    for (i = 1; i <= n; i++)
        if (adjacent(G, x, i))
            push_back(&L, i);
    return L;
}
int parent[100];
void BFS(Graph *G)
{
    Queue Q;
    parent[1] = 0;
    int mark[100];
    makenull_Queue(&Q);
    int i, j;
    for (j = 1; j <= G->n; j++)
        mark[j] = 0;
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
            for (j = 1; j <= L.n; j++)
            {
                int y = Element(&L, j);
                if (mark[y] == 0)
                {
                    mark[y] = 1;
                    parent[y] = x;
                    push(&Q, y);
                }
            }
        }
    }
}
int main()
{
    freopen("dothi.txt", "r", stdin);
    Graph G;
    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (e = 0; e < m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    BFS(&G);
    int i;
    for (i = 1; i <= n; i++)
        printf("%d %d\n", i, parent[i]);
}
