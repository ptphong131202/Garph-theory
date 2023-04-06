/* Giả sử đồ thị vô hướng, có đa cung và có chứa khuyên. Để biểu diễn khuyên e = (x, x), ta gán A[x][e] = 2.

Viết hàm add_edge(Graph* G, int e, int x, int y) để thêm cung e = (x, y) vào đồ thị G. */
#include <stdio.h>
#define max 100
typedef struct
{
    int n, m;
    int A[max][max];
} Graph;

void init_graph(Graph *G, int n)
{
    G->n = n;
    G->m = 0;
    int i, j;
    for (i = 0; i < G->n; i++)
        for (j = 0; j < G->n; j++)
            G->A[i][j] = 0;
}

void add_edge(Graph *G, int x, int y)
{
    if (x == y)
    {
        G->A[x][y] = 2;
    }
    else
    {
        G->A[x][y] = 1;
        G->A[y][x] = 1;
    }
}

int main()
{
    freopen("dothi.txt", "r", stdin);
    Graph G;
    int n, m, i, u, v;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    for (i = 1; i <= G.n; i++)
    {
        for (u = 1; u <= G.n; u++)
            printf("%d ", G.A[i][u]);
        printf("\n");
    }
}