/**
 * Do thi danh sach ke
 */

#include <stdio.h>

#define max 100 // so cung toi da cua do thi

typedef int Element; // khai bao phan tu kieu int

// danh sach cung
typedef struct
{
    Element data[max]; // danh sach cac cung
    int size;          // do dai cua danh sach
} List;

// cau truc do thi Graph G
typedef struct
{
    int n;         // so dinh cua do thi
    List adj[max]; // danh sach dinh ke
} Graph;

// ham khoi tao danh sach rong
void makenullList(List *L)
{
    L->size = 0; // do dai danh sach = 0
}

// ham them vao danh sach
void push(List *L, Element x)
{
    L->data[L->size] = x; // cho phan tu cuoi danh sach  = x
    L->size++;            // tang do dai danh sach len mot don vi
}

// lay gia tri phan tu tai vi tri x
Element element_at(List *L, int x)
{
    return L->data[x - 1];
}

// lay do daia cua danh sach
int countList(List *L)
{
    return L->size;
}

// ham khoi tao do thi
void init_Graph(Graph *G, int n)
{
    G->n = n; // gan gia tri cho dinh = n
    int v;
    for (v = 1; v < G->n; v++)
        makenullList(&G->adj[v]);
}

// ham them cung cho do thi
void add_edge(Graph *G, int u, int v)
{
    push(&G->adj[u], v);
    push(&G->adj[v], u);
}

int adjacent(Graph *pG, int u, int v)
{
    int j;
    for (j = 1; j <= pG->adj[u].size; j++)
        if (element_at(&pG->adj[u], j) == v)
            return 1; // v n?m trong dánh sách adj[u]
    return 0;         // v không có trong danh sách adj[u]
}

void neighbours(Graph *G, int u)
{
    int v;
    for (v = 1; v <= G->n; v++)
        if (adjacent(G, u, v) != 0)
            printf("%d ", v);
    printf("\n");
}

// ham tinh bac cua 1 dinh
int degree(Graph *G, int x)
{
    return G->adj[x].size;
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
    add_edge(&G, 1, 2);
    add_edge(&G, 2, 3);
    add_edge(&G, 3, 4);
    add_edge(&G, 4, 1);
    add_edge(&G, 2, 4);

    /*  freopen("dothi1.txt", "r", stdin);
     scanf("%d%d", &n, &m);
     init_Graph(&G, n);
     for (i = 1; i <= m; i++)
     {
         scanf("%d%d", &u, &v);
         add_adge(&G, u, v);
     }
  */
    printf("---------------------------------\n");

    for (i = 1; i <= G.n; i++)
    {
        printf("Degree(%d): %d", i, degree(&G, i));
        printf("\n");
    }
    printf("---------------------------------");
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