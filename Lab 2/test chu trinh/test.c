#include <stdio.h>

#define max 50
typedef struct
{
    int n, A[max][max];
} Graph;

typedef struct
{
    int size, data[max];
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
    G->n = n;
    int i, j;
    for (i = 1; i <= G->n; i++)
        for (j = 1; j <= G->n; j++)
            G->A[i][j] = 0;
}

void add_edge(Graph *G, int u, int v)
{
    G->A[u][v] = 1;
    G->A[v][u] = 1;
}

int adjacent(Graph *G, int u, int v) { return G->A[u][v]; }

List neighbors(Graph *G, int x)
{
    List L;
    makenullList(&L);
    int i;
    for (i = 1; i <= G->n; i++)
        if (adjacent(G, x, i))
            pushList(&L, i);
    return L;
}

typedef struct
{
    int data[max], size;
} Stack;

void makenullStack(Stack *S) { S->size = 0; }

void push(Stack *S, int x)
{
    S->data[S->size] = x;
    S->size++;
}

int top(Stack *S) { return S->data[S->size - 1]; }

void pop(Stack *S)
{
    S->size--;
}

int empty(Stack *S) { return S->size == 0; }

int mark[max];
int cycle;

void dfs(Graph *G, int x, int parent)
{
    mark[x] = 2;
    int i;

    List L = neighbors(G, x);
    for (i = 0; i < L.size; i++)
    {
        int y = elementAt(&L, i);

        if (y == parent)
            continue;

        if (mark[y] == 2)
        {
            cycle = 1;
            return;
        }

        if (mark[y] == 0)
            dfs(G, y, x);
    }

    mark[x] = 1;
}

int contain_cycle(Graph *G)
{
    int i;
    for (i = 1; i <= G->n; i++)
        mark[i] = 0;
    cycle = 0;
    for (i = 1; i <= G->n; i++)
        if (mark[i] == 0)
            dfs(G, i, 0);
    return cycle;
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

    if (contain_cycle(&G))
    {
        printf("Yes");
    }
    else
        printf("No");
}