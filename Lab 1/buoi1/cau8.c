#include <stdio.h>
#define max 50

typedef struct
{
    int n;
    int A[max][max];
} Graph;

void init_graph(Graph *G, int n)
{
    G->n = n;
    int i, j;
    for (i = 1; i <= G->n; i++)
        for (j = 1; j <= G->n; j++)
            G->A[i][j];
}

void add_edge(Graph *G, int u, int v)
{
    G->A[u][v] = 1;
    G->A[v][u] = 1;
}

int main()
{
    freopen("dothi.txt", "r", stdin);
    int n, m, i, u, v;
    scanf("%d%d", &n, &m);
    Graph G;
    init_graph(&G, n);
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    int j;
    for (i = 1; i <= G.n; i++)
    {
        for (j = 1; j <= G.n; j++)
            printf("%d ", G.A[i][j]);
        printf("\n");
    }
}