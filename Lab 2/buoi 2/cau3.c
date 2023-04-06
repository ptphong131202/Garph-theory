#include <stdio.h>
#define max 50

typedef struct
{
    int u, v;
} edge;

typedef struct
{
    int n, m;
    edge edges[max];
} Graph;

typedef struct
{
    int size;
    int data[max];
} List;

void init_graph(Graph *G, int n)
{
    G->m = 0;
    G->n = n;
}

void add_edge(Graph *G, int u, int v)
{
    int i;
    for (i = 1; i <= G->m; i++)
        if ((G->edges[i].u == u && G->edges[i].v == v) || (G->edges[i].u == v && G->edges[i].v == u))
            return;

    G->edges[G->m].u = u;
    G->edges[G->m].v = v;
    G->m++;
}

int adjacent(Graph *G, int u, int v)
{
    int i;
    for (i = 0; i <= G->m; i++)
        if ((G->edges[i].u == u && G->edges[i].v == v) || (G->edges[i].u == v && G->edges[i].v == u))
            return 1;
    return 0;
}

void makenullList(List *L)
{
    L->size = 0;
}

int elementAt(List *L, int x)
{
    return L->data[x];
}

void pushList(List *L, int x)
{
    L->data[L->size] = x;
    L->size++;
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

int mark[max];

void traversal(Graph *G, int x)
{
    if (mark[x] == 1)
        return;
    printf("%d\n", x);
    mark[x] = 1;
    List L = neighbors(G, x);
    int i;
    for (i = 0; i < L.size; i++)
    {
        int y = elementAt(&L, i);
        traversal(G, y);
    }
}

/* void dfs(Graph *G, int x)
{
    int i;
    for (i = 1; i <= G->n; i++)
        mark[i] == 0;
    traversal(G, x);
    for (i = 1; i <= G->n; i++)
        if (mark[i] == 0)
            traversal(G, i);
} */

void dfs(Graph *G, int a)
{
    int i;
    for (i = 1; i <= G->n; i++)
        mark[i] = 0;
    traversal(G, a);
    for (i = 1; i <= G->n; i++)
        if (mark[i] == 0)
            traversal(G, i);
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

    dfs(&G, 1);
}