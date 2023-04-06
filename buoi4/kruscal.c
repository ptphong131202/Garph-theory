#include <stdio.h>
#define max 50

typedef struct
{
    int u, v, w;
} edge;

typedef struct
{
    int n, m;
    edge A[max];
} Graph;

void init_graph(Graph *G, int n)
{
    G->n = n;
    G->m = 0;
}

void add_edge(Graph *G, int u, int v, int w)
{
    G->A[G->m].u = u;
    G->A[G->m].v = v;
    G->A[G->m].w = w;
    G->m++;
}

int parent[max];

int findRoot(int u)
{
    if (parent[u] == u)
        return u;
    return findRoot(parent[u]);
}

int kruscal(Graph *G, Graph *T)
{
    int i, j, e, u;
    edge temp;
    // sap xep gia tri tang dan
    for (i = 0; i < G->m; i++)
        for (j = i + 1; j < G->m; j++)
        {
            if (G->A[i].w > G->A[j].w)
            {
                temp = G->A[i];
                G->A[i] = G->A[j];
                G->A[j] = temp;
            }
        }

    // khoi tao cay T
    init_graph(T, G->n);

    // khoi tao bo quan ly bo phan lien thong
    for (u = 1; u <= G->n; u++)
        parent[u] = u;
    int sum_w = 0;

    for (e = 0; e < G->m; e++)
    {
        int u = G->A[e].u;
        int v = G->A[e].v;
        int w = G->A[e].w;
        int root_u = findRoot(u);
        int root_v = findRoot(v);
        if (root_u != root_v)
        {
            // them cung vao cay
            if (u < v)
                add_edge(T, u, v, w);
            else
                add_edge(T, v, u, w);
            // gop 2 bo phan lien thong
            parent[root_v] = root_u;
            sum_w += w;
        }
    }
    return sum_w;
}

int main()
{
    Graph G, T;
    int n, m, u, v, w, e;
    freopen("dothi.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (e = 1; e <= m; e++)
    {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }
    int sum_w = kruscal(&G, &T);
    printf("Tong trong so cua cay T la: %d\n", sum_w);
    for (e = 0; e < T.m; e++)
        printf("(%d, %d): %d\n", T.A[e].u, T.A[e].u,
               T.A[e].w);
    return 0;
}
