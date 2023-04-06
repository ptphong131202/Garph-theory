
/* Viết hàm add_edge(Graph* G, int x, int y) để thêm cung (x, y) vào đồ thị G. */

#include <stdio.h>

#define max 50

typedef struct
{
    int u, v;
} Edge;

typedef struct
{
    int n, m;
    Edge edges[max];
} Graph;

void init_graph(Graph *G, int n)
{
    G->n = n;
    G->m = 0;
}

void add_edge(Graph *G, int u, int v)
{
    G->edges[G->m].u = u;
    G->edges[G->m].v = v;
    G->m++;
}

int main()
{
    freopen("dothi.txt", "r", stdin);
    Graph G;
    int n, m, i, u, v;
    scanf("%d%d", &n, &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
        printf("%d %d\n", u, v);
    }
    return 0;
}