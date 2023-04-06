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

typedef struct
{
    int data[max];
    int size;
} stack;

void makenullStack(stack *s)
{
    s->size = 0;
}

int top(stack *s)
{
    return s->data[s->size - 1];
}

void pop(stack *s)
{
    s->size--;
}

void push(stack *s, int x)
{
    s->data[s->size] = x;
    s->size++;
}

int empty(stack *s)
{
    return s->size == 0;
}

void dfs(Graph *G, int x, int a[max])
{
    stack L;
    makenullStack(&L);
    int mark[max];
    int i;
    for (i = 1; i <= G->n; i++)
        mark[i] = 0;
    push(&L, x);
    while (!empty(&L))
    {
        int x = top(&L);
        pop(&L);
        if (mark[x] != 0)
            continue;
        printf("%d\n", x);
        mark[x] = 1;
        List list = neighbors(G, x);
        for (i = 0; i < list.size; i++)
        {
            int y = elementAt(&list, i);
            push(&L, y);
            a[x] = 1;
        }
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

    int a[max];
    for (i = 1; i <= G.n; i++)
        a[i] = 0;
    for (i = 1; i <= G.n; i++)
        if (a[i] == 0)
            dfs(&G, i, a);
}