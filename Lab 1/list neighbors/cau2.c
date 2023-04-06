#include <stdio.h>
#define max 50

typedef struct
{
    int n, m;
    int A[max][max];
} Graph;

void init_graph(Graph *G, int n)
{
    G->n = n;
    int i, j;
    for (i = 1; i <= G->n; i++)
        for (j = 1; j <= G->n; j++)
            G->A[i][j];
}

void add_edge(Graph *G, int u, int v)
{
    G->A[u][v] = 1;
    G->A[v][u] = 1;
}

int adjacent(Graph *G, int u, int v)
{
    return G->A[u][v] == 1;
}
int degree(Graph *G, int x)
{
    int i, deg = 0;
    for (i = 1; i <= G->n; i++)
        if (adjacent(G, x, i))
            deg++;
    return deg;
}

#define MAX_ELEMENTS 100

typedef int ElementType;

typedef struct
{
    ElementType data[MAX_ELEMENTS];
    int size;
} List;

/* Tao danh sach rong */
void make_null(List *L)
{
    L->size = 0;
}

/* Them mot phan tu vao cuoi danh sach */
void push_back(List *L, ElementType x)
{
    L->data[L->size] = x;
    L->size++;
}

/* Lay phan tu tai vi tri i, phan tu bat dau o vi tri 1 */
ElementType element_at(List *L, int i)
{
    return L->data[i - 1];
}

/* Tra ve so phan tu cua danh sach */
int count_list(List *L)
{
    return L->size;
}

List neighbors(Graph *G, int x)
{
    int i, j;
    List L;
    make_null(&L);
    for (i = 1; i <= G->n; i++)
    {
        if (i != x)
        {
            for (j = 1; j <= G->m; j++)
                if ((G->A[i][j] == 1) && (G->A[x][j] == 1))
                {
                    push_back(&L, i);
                    break;
                }
        }
    }
    return L;
}

int main()
{
    Graph G;
    init_graph(&G, 4);
    add_edge(&G, 1, 2);
    add_edge(&G, 2, 1);
    add_edge(&G, 3, 4);
    int i, j;
}