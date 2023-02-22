/**
 * Do thi cung
 */

#include <stdio.h>

#define max 100 // so cung toi da cua do thi cung

// cau truc mot cung Edge
typedef struct
{
    int x, y; // Diem dau va diem cuoi cua mot cung
} Edge;

// cau truc 1 Graph
typedef struct
{
    int n, m;        // so dinh va so cung cua do thi
    Edge edges[max]; // mang chua cac cung
} Graph;

// ham khoi tao do thi rong
void multiGraph(Graph *G)
{
    G->n = 0; // gan khong co dinh
    G->m = 0; // gan khong co cung
}

// ham khoi tao 1 cung co dinh
void init_Graph(Graph *G, int n)
{
    G->n = n; // so dinh  = n
    G->m = 0; // so cung  = 0
}

// ham them cung cho do thi
void add_adge(Graph *G, int x, int y)
{
    G->edges[G->m].x = x; // gan gia tri dinh dau  = x
    G->edges[G->m].y = y; // gan gia tri dimh cuoi  = y
    G->m++;               // tang so cung len 1 don vi
}

// ham kiem tra anh em ke
int adjacent(Graph *G, int x, int y)
{
    int e;
    for (e = 0; e < G->m; e++)                                                                        // duyet qua tung cung
        if ((G->edges[e].x == x && G->edges[e].y == y) || (G->edges[e].y == x && G->edges[e].x == y)) // dinh dau = x va dinh cuoi  =y or nguoc lai
            return 1;                                                                                 // tra ve 1
    return 0;                                                                                         // nguoc lai thi tra ve 0
}

// xac dinh bac cua mot dinh
int degree(Graph *G, int x)
{
    int e, deg = 0;
    for (e = 0; e < G->m; e++)
    { // duyet tung cung
        if (G->edges[e].x == x)
            deg++; // neu x = dau tang bac
        if (G->edges[e].y == x)
            deg++; // neu x = cuoi tang bac
    }
    return deg;
}

// ham hang xom cua mot dinh
void neighbours(Graph *G, int u)
{
    int v;
    for (v = 1; v <= G->n; v++) // duyet tung dinh
    {
        if (adjacent(G, u, v)) // neu ke
            printf("%d ", v);  // neu ke in ra
    }
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
    /* init_Graph(&G, 4);
    add_adge(&G, 1, 2);
    add_adge(&G, 2, 3);
    add_adge(&G, 3, 4);
    add_adge(&G, 4, 1);
    add_adge(&G, 2, 4); */

    freopen("dothi1.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    init_Graph(&G, n);
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        add_adge(&G, u, v);
    }

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