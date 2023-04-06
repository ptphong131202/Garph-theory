/** Do thi ma tran dinh dinh*/
#include <stdio.h>

#define max 100 // gia tri toi da 100

// cau truc Graph
typedef struct
{
    int n, m;        // so cung va so dinh cua do thi
    int A[max][max]; // ma tran dinh dinh
} Graph;

// khoi tao Graph voi so cung n
void init_graph(Graph *G, int n)
{
    G->n = n; // so dinh cua do thi = n
    G->m = 0; //  so cung ban dau = 0
    int i, j;
    for (i = 1; i <= G->m; i++)
        for (j = 1; j <= G->m; i++)
            G->A[i][j] = 0; // gan cac gia tri trong mang = 0
}

// ham them cung vao Graph
void add_edge(Graph *G, int u, int v)
{
    // Graph vo huong
    G->A[u][v] = 1; // uv = 1
    G->A[v][u] = 1; // vu = 1
    G->m++;         // tang  m
}

int adjacent(Graph *G, int x, int y)
{
    return G->A[x][y] > 0;
}

// xac dinh bac cua mot dinh
int degree(Graph *G, int u)
{
    int v, deg = 0;
    for (v = 1; v <= G->n; v++) // duyet qua cac dinh
        deg += G->A[u][v];      // cong tat ca cac so hang u
    return deg + G->A[u][u];    // deg + khuyen
}

// ham tim hang xom
void neighbors(Graph *G, int x)
{
    int y;
    for (y = 1; y <= G->n; y++) // duyet qua tung dinh
        if (adjacent(G, x, y))  // neu la dinh ke
            printf("%d ", y);   // hien thi
    printf("\n");
}

int main()
{
    freopen("dothi2.txt", "r", stdin); // Khi nộp bài nhớ bỏ dòng này.
    Graph G;
    int n, m, u, v, w, e, i;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 1; e <= m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    /* for (i = 1; i <= G.n; i++)
        printf("Degree(%d): %d\n", i, degree(&G, i));
    printf("Danh sach dinh ke\n"); */
    /* for (i = 1; i <= G.n; i++)
    {
        printf("Dinh ke cua %d: ", i);
        neighbors(&G, i);
    } */
    int min = 999999, index;
    for (i = 1; i <= G.n; i++)
    {
        if (degree(&G, i) < min)
        {
            min = degree(&G, i);
            index = i;
        }
    }
    printf("%d %d", index, min);
}