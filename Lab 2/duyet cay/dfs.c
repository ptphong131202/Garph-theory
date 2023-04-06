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
    for (i = 0; i <= G->m; i++)
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

typedef struct
{
    int data[max], size;
} Stack;

void makenullStack(Stack *S)
{
    S->size = 0;
}

void push(Stack *S, int x)
{
    S->data[S->size] = x;
    S->size++;
}

int top(Stack *S)
{
    return S->data[S->size - 1];
}

void pop(Stack *S)
{
    S->size--;
}

int empty(Stack *S)
{
    return S->size == 0;
}

void dfs(Graph *G, int x, int a[max])
{
    Stack S;
    makenullStack(&S);
    int mark[max], i;

    for (i = 1; i <= G->n; i++)
        mark[i] = 0;

    push(&S, x);

    while (!empty(&S))
    {
        int x = top(&S);
        pop(&S);

        if (mark[x] != 0)
            continue;

        printf("%d\n", x);
        mark[x] = 1;

        List L = neighbors(G, x);
        for (i = 0; i < L.size; i++)
        {
            int y = elementAt(&L, i);
            push(&S, y);
        }
        a[x] = 1;
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