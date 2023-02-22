/**
 * Do thi dinh dinh
 */

#include <stdio.h>

#define max 100 // so cung toi da 100

// cau truc Graph G
typedef struct
{
    int n, m;        // so dinh va so cung cua do thi
    int A[max][max]; // ma tran vuong do thi
} Graph;

// khoi tao do thi rong
void makenull_Graph(Graph *G)
{
    G->n = 0; // so dinh  0
    G->m = 0; // so cung  = 0
}

// ham khoi tao do thi
void init_Graph(Graph *G, int n)
{
    G->n = n; // so dinh = n
    G->m = 0; // so cung  = 0
    int u, v;
    for (u = 1; u <= G->n; u++)     // duyet qua tung hang
        for (v = 1; v <= G->n; v++) // duyet qua tung cot
            G->A[u][v] = 0;         // cho tat ca phan tu duoc duyet qua = 0
}

// ham them cung vao do thi
void add_adge(Graph *G, int u, int v)
{
    G->A[u][v] = 1; // cac phan tu tai vi tri (u,v)= 1
    G->A[v][u] = 1; // cac phan tu phia duoi duong cheo = 1 | (u,v) = 1
    G->m++;         // tang so cung len 1 don vi
}

// kiem tra anh em ke cua mot dinh trong do thi
int adjacent(Graph *G, int x, int y)
{
    return G->A[x][y] > 0; // neu phan tu tai vi tri u v = 1 thi bac = 1
}

// xac dinh bac cua mot dinh trong do thi
int degree(Graph *G, int u)
{
    int v, deg = 0;             // cho bac  = 0
    for (v = 1; v <= G->n; v++) // duyet qua tung dinh
        deg += G->A[u][v];      //
    return deg + G->A[u][u];    // bac + khuyen neu co
}

// tim hang xom cua 1 dinh trong do thi
void neighbours(Graph *G, int u)
{
    int v;
    for (v = 1; v <= G->n; v++)     // duyet qua tung dinh
        if (adjacent(G, u, v) != 0) // neu dinh u ke voi dinh v
            printf("%d ", v);       // in v
    printf("\n");
}

int main()
{
    Graph G;
    int n, m, i, j, u, v;
    /* FILE *f = fopen("dothi.txt", "r");
    fscanf(f, "%d%d", &n, &m);
    init_Graph(&G, n);
    for (i = 1; i <= m; i++)
    {
        fscanf(f, "%d%d", &u, &v);
        add_adge(&G, u, v);
    }
 */
    init_Graph(&G, 4);
    add_adge(&G, 1, 2);
    add_adge(&G, 2, 3);
    add_adge(&G, 3, 4);
    add_adge(&G, 4, 1);
    add_adge(&G, 2, 4);

    /*  freopen("dothi1.txt", "r", stdin);
     scanf("%d%d", &n, &m);
     init_Graph(&G, n);
     for (i = 1; i <= m; i++)
     {
         scanf("%d%d", &u, &v);
         add_adge(&G, u, v);
     }
  */
    printf("\n---------------------------------");
    printf("\nBac cua cac dinh");
    for (i = 1; i <= G.n; i++)
        printf("\nDegree(%d): %d", i, degree(&G, i));
    printf("\n---------------------------------");
    printf("\nKiem tra dinh ke\n");
    for (i = 1; i <= G.n; i++)
        for (j = 1; j <= G.n; j++)
        {
            if (adjacent(&G, i, j) == 1)
            {
                printf("%d ke voi %d\n", i, j);
            }
            else
                printf("%d khong ke voi %d\n", i, j);
        }
    printf("---------------------------------");
    printf("\nKiem tra hang xom\n");
    for (i = 1; i <= G.n; i++)
    {
        printf("Neighbours %d la: ", i);
        neighbours(&G, i);
    }

    return 0;
}