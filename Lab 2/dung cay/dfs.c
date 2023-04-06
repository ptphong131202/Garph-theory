#include <stdio.h>

#define max 50

int parents[max], mark[max];

typedef struct
{
    int n;
    int A[max][max];
} Graph;

void init_graph(Graph *G, int n)
{
    G->n = n;
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; i <= G->n; i++)
            G->A[i][j] = 0;
}

void add_edge(Graph *G, int u, int v)
{
    G->A[u][v] = u;
    G->A[v][u] = v;
}

typedef struct
{
    int u, parent;

} element_type;

typedef struct
{
    element_type data[max];
    int size;
} Stack;

void makenullStack(Stack *S)
{
    S->size = 0;
}

int empty(Stack *S)
{
    return S->size == 0;
}

element_type top(Stack *S)
{
    return S->data[S->size];
}

void push(Stack *S, element_type x)
{
    S->data[S->size] = x;
    S->size++;
}

void pop(Stack *S)
{
    S->size--;
}

void dfs(Graph *G, int x)
{
    Stack S;
    makenullStack(&S);
    push(&S, (element_type){x, 0});

    while (!empty(&S))
    {
        element_type current = top(&S);
        int u = current.u;
        int parent = current.parent;
        pop(&S);

        if (parent)
        {
            parents[u] = parent;
        }

        if (mark[u])
        {
            mark[u] = 1;
            int i;
            for (i = 1; i <= G->n; i++)
                if (G->A[u][i])
                    push(&S, (element_type){i, u});
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

    for (i = 1; i <= G.n; i++)
    {
        parents[i] = 0;
        mark[i] = 0;
    }

    dfs(&G, 1);
    for (i = 1; i <= G.n; i++)
        printf("%d %d\n", i, parents[i]);
}