#include <stdio.h>
#define max 50
#define no_edge 0
#define INFINITY 999999

typedef struct
{
    int u, v, w;
} edge;

typedef struct
{
    int n, m;
    edge edges[max];
} Graph;

void init_graph(Graph *G, int n)
{
    G->n = n;
    G->m = 0;
}

void add_edge(Graph *G, int u, int v, int w)
{
    G->edges[G->m].u = u;
    G->edges[G->m].v = v;
    G->edges[G->m].w = w;
    G->m++;
}

int pi[max];
int p[max];

void bellmem(Graph *G, int x)
{
    int i, j, it;
    for (i = 1; i <= G->n; i++)
        pi[i] = INFINITY;

    pi[x] = 0;
    p[x] = -1;

    for (it = 1; it < G->n; it++)
    {
        for (j = 0; j < G->m; j++)
        {
            int u = G->edges[j].u;
            int v = G->edges[j].v;
            int w = G->edges[j].w;

            if (pi[u] + w < pi[v])
            {
                pi[v] = pi[u] + w;
                p[v] = u;
            }
        }
    }
}

int main()
{
    freopen("dothi.txt", "r", stdin); // Khi nộp bài nhớ bỏ dòng này.
    Graph G;
    int n, m, u, v, w, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 0; e < m; e++)
    {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }

    bellmem(&G, 1);
    printf("%d", pi[n]);
    return 0;
}