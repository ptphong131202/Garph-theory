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
    init_graph(&G, 4);
    add_edge(&G, 1, 2);
    add_edge(&G, 2, 1);
    add_edge(&G, 3, 4);
    int i, j;
    for (i = 1; i <= G.n; i++)
    {
        for (j = 1; j <= G.n; j++)
            printf("%d ", G.A[i][j]);
        printf("\n");
    }
}