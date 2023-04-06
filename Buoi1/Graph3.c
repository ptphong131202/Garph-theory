/** Do thi danh sach  dinh ke */
#include <stdio.h>

#define max 100 // gia tri toi da  = 100

typedef int Element; // khia bao pha tu kieu int;

// cau truc cua mot danh sach dinh
typedef struct
{
    Element data[max]; // danh sach cac dinh
    int size;          // kich thuoc cua danh sach
} List;

// cau truc Graph
typedef struct
{
    int n;         // so dinh
    List adj[max]; // danh sach cac dinh ke
} Graph;

// ham khoi tao list rong
void makenullList(List *L)
{
    L->size = 0; // do dai danh sach  = 0
}

// ham them phan tu vao danh sach
void push(List *L, Element x)
{
    L->data[L->size] = x;
    L->size++;
}

// ham lay gia tri tai phan tu x
Element elementAt(List *L, int x)
{
    return L->data[x - 1];
}

// ham khoi tao Graph
void init_graph(Graph *G, int n)
{
    G->n = n; // so dinh cua do thi = n
    int i;
    for (i = 1; i <= n; i++)
        makenullList(&G->adj[i]); // khoi tao danh sach canh rong
}

void add_edge(Graph *G, int u, int v)
{
    push(&G->adj[u], v);
    push(&G->adj[v], u);
}

int adjacent(Graph *G, int u, int v)
{
    int i;
    for (i = 1; i <= G->adj[u].size; i++)  // duyet qua danh sach dinh
        if (elementAt(&G->adj[u], i) == v) // neu trong danh sach u co dinh v
            return 1;                      // tra ve 1
    return 0;                              // else tra ve 0
}

// ham tinh bac cua 1 dinh
int degree(Graph *G, int x)
{
    return G->adj[x].size; // tra ve danh chieu dai danh sach dinh ke cua x
}

// ham tim dinh hang xom
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
    FILE *f = fopen("dothi.txt", "r"); // doc file
    fscanf(f, "%d%d", &n, &m);
    init_graph(&G, n);
    for (i = 1; i <= m; i++)
    {
        fscanf(f, "%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    for (i = 1; i <= G.n; i++)
        printf("Degree(%d): %d\n", i, degree(&G, i));
    printf("Danh sach dinh ke\n");
    for (i = 1; i <= G.n; i++)
    {
        printf("Dinh ke voi %d: ", i);
        neighbors(&G, i);
    }
}