/* Giả sử đồ thị vô hướng, không chứa khuyên, không chứa đa cung
Viết hàm int deg(Graph* G, int x) để tính bậc của đỉnh x.*/

#include <stdio.h>

#define max 50
typedef struct
{
    int A[max][max];
    int n;
} Graph;

void init_graph(Graph *G, int n)
{
    G->n = n;
    int i, j;
    for (i = 0; i < G->n; i++)
        for (j = 0; j < G->n; j++)
            G->A[i][j] = 0;
}

void add_edge(Graph *G, int u, int v)
{
    G->A[u][v] = 1;
    G->A[v][u] = 1;
}

int degree(Graph *G, int x)
{
    int i, deg = 0;
    for (i = 1; i <= G->n; i++)
        deg += G->A[x][i];
    return deg;
}

int main()
{
    freopen("dothi.txt", "r", stdin);
    int n, m, i, u, v;
    Graph G;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    for (i = 1; i <= n; i++)
        printf("Degree(%d): %d\n", i, degree(&G, i));
}