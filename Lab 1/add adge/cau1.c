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

void add_edge(Graph *G, int e, int u, int v)
{
    G->A[u][e] = 1;
    G->A[v][e] = 1;
}

int adjacent(Graph *G, int u, int v)
{
    return G->A[u][v] == 1;
}
int degree(Graph *G, int x)
{
    int i, deg = 0;
    for (i = 1; i <= G->n; i++)
        if (adjacent(G, x, i))
            deg++;
    return deg;
}

int main()
{
    Graph G;
    add_edge(&G, 1, 2, 3);
    printf("%d %d\n", G.A[2][1], G.A[4][1]);
}