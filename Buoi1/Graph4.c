/* Do thi mang dinh dinh */
#include <stdio.h>

#define max 100 // gia tri toi da

// cau truc Graph
typedef struct
{
    int n, m;        // so dinh va sso cung
    int A[max][max]; // ma tran dinh dinh
} Graph;

// ham khoi tao Graph
void init_Graph(Graph *G, int n)
{
    G->n = n; // gan so dinh graph = n
    int i, j;
    // tao mot ma tran dinh dinh voi voi ca phan tu mang = 0
    for (i = 1; i <= G->n; i++)
        for (j = 1; j <= G->n; j++)
            G->A[i][j] = 0;
}

// ham them cung vao graph
void add_Edge(Graph *G, int x, int y)
{
    G->A[x][y] = 1; // gan cung tao vi tri xy  = 1
}

// ham kiem tra lang gieng
int adjacent(Graph *G, int x, int y)
{
    return G->A[x][y] == 1; // neu vi tri xy trong mang = 1 thi tra ve 1
}

// ham tinhs bac cua dinh
int degree(Graph *G, int x)
{
    int i;
    int deg = 0;
    for (i = 1; i <= G->n; i++)
    {
        if (G->A[x][i] == 1)
        {
            deg++;
        }
    }
    return deg;
}

void neighbors(Graph *G, int u)
{
    int v;
    for (v = 1; v <= G->n; v++)
        if (adjacent(G, u, v))
            printf("%d ", v);
    printf("\n");
}

int main()
{
    Graph G;
    int n, m, i, u, v;
    FILE *f = fopen("dothi.txt", "r");
    fscanf(f, "%d%d", &n, &m);
    init_Graph(&G, n);
    for (i = 1; i <= m; i++)
    {
        fscanf(f, "%d%d", &u, &v);
        add_Edge(&G, u, v);
    }
    for (i = 1; i <= G.n; i++)
        printf("Degree(%d): %d\n", i, degree(&G, i));
    for (i = 1; i <= G.n; i++)
    {
        printf("Dinh ke cua %d: ", i);
        neighbors(&G, i);
    }
}