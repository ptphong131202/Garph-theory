#include <stdio.h>

#define max 50

typedef struct
{
    int u, v;
} edge;

typedef struct
{
    int n, m;
    edge data[max];
} Graph;

typedef struct
{
    int data[max], size;
} List;

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

void init_graph(Graph *G, int n)
{
    G->n = n;
    G->m = 0;
}

void add_edge(Graph *G, int u, int v)
{
    int i;
    for (i = 0; i < G->m; i++)
        if ((G->data[i].u == u && G->data[i].v == v) || (G->data[i].u == v && G->data[i].v == u))
            return;

    G->data[G->m].u = u;
    G->data[G->m].v = v;
    G->m++;
}

int adjacent(Graph *G, int u, int v)
{
    int i;
    for (i = 0; i < G->m; i++)
        if ((G->data[i].u == u && G->data[i].v == v) || (G->data[i].u == v && G->data[i].v == u))
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

int mark[max];

void traversal(Graph *G, int x)
{
    if (mark[x] == 1)
        return;

    printf("%d\n", x);
    mark[x] = 1;

    int i;
    List L = neighbors(G, x);
    for (i = 0; i < L.size; i++)
    {
        int y = elementAt(&L, i);
        traversal(G, y);
    }
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

    for (i = 1; i <= G.n; i++)
        mark[i] = 0;
    traversal(&G, 1);
    for (i = 1; i <= G.n; i++)
        if (mark[i] == 0)
            traversal(&G, i);
}