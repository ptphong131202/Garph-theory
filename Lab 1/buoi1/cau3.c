/* Giả sử đồ thị vô hướng, không chứa khuyên.
Viết hàm add_edge(Graph* G, int e, int x, int y) để thêm cung e = (x, y) vào đồ thị G.*/

#include <stdio.h>
#define max 50
typedef struct
{
    int n, m;
    int A[max][max];
} Graph;

void init_graph(Graph *G, int n)
{
    G->m = 0;
    G->n = n;
    int i, j;
    for (i = 0; i < G->n; i++)
        for (j = 0; j < G->n; j++)
            G->A[i][j] = 0;
}

void add_edge(Graph *G, int e, int u, int v)
{
    G->A[u][e] = 1;
    G->A[v][e] = 1;
}

int main()
{
    Graph G;

    add_edge(&G, 1, 2, 3);
    printf("%d %d\n", G.A[2][1], G.A[4][1]);
}