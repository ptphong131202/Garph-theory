#include <stdio.h>

#define max 50
#define NO_EDGE 0
#define INFINITY 999999

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
            G->A[i][j] = NO_EDGE;
}

void add_edge(Graph *G, int u, int v, int w)
{
    G->A[u][v] = w;
}

int mark[max], pi[max], p[max];

void dijkstra(Graph *G)
{
    int i, j, it;
    for (i = 1; i <= G->n; i++)
    {
        mark[i] = 0;
        pi[i] = INFINITY;
    }
    pi[1] = 0;
    p[1] = -1;

    for (it = 1; it < G->n; it++)
    {
        int min_pi = INFINITY;
        for (j = 1; j <= G->n; j++)
            if (mark[j] == 0 && pi[j] < min_pi)
            {
                min_pi = pi[j];
                i = j;
            }
        mark[i] = 1;

        for (j = 1; j <= G->n; j++)
            if (mark[j] == 0 && G->A[i][j] != NO_EDGE)
                if (pi[i] + G->A[i][j] < pi[j])
                {
                    pi[j] = pi[i] + G->A[i][j];
                    p[j] = i;
                }
    }
}

int main()
{
    Graph G;
    freopen("dothi.txt", "r", stdin);
    int n, m, u, v, e, w;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (e = 1; e <= m; e++)
    {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }
    dijkstra(&G);
    if (pi[n] != INFINITY)
        printf("%d", pi[n]);
    else
        printf("-1");
    return 0;
}