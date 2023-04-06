#include <stdio.h>
#define MAXN 50
typedef struct
{
    int n, A[MAXN][MAXN];
} Graph;

typedef struct
{
    int data[MAXN], size;
} List;

void make_null(List *L) { L->size = 0; }

void push_back(List *L, int x)
{
    L->data[L->size] = x;
    L->size++;
}
int element_at(List *L, int i) { return L->data[i - 1]; }

void init_graph(Graph *G, int n, int m)
{
    G->n = n;
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            G->A[i][j] = 0;
}
void add_edge(Graph *G, int x, int y) { G->A[x][y] = 1; }

int adjacent(Graph *G, int x, int y) { return G->A[x][y]; }

List neighbors(Graph *G, int x)
{
    List L;
    int i, n;
    make_null(&L);
    n = G->n;
    for (i = 1; i <= n; i++)
        if (adjacent(G, x, i))
            push_back(&L, i);
    return L;
}

typedef struct
{
    int data[MAXN], size;
} Stack;

void make_null_stack(Stack *S) { S->size = 0; }

void push(Stack *S, int x)
{
    S->data[S->size] = x;
    S->size++;
}

int top(Stack *S) { return S->data[S->size - 1]; }
void pop(Stack *S) { S->size--; }
int empty(Stack *S) { return S->size == 0; }

int mark[MAXN];
int cycle;

void DFS(Graph *G, int x)
{
    mark[x] = 2;
    int j;
    List L = neighbors(G, x);
    for (j = 1; j <= L.size; j++)
    {
        int y = element_at(&L, j);
        if (mark[y] == 2)
        {
            cycle = 1;
            return;
        }
        if (mark[y] == 0)
            DFS(G, y);
    }
    mark[x] = 1;
}
int contains_cycle(Graph *G)
{
    int j;
    for (j = 1; j <= G->n; j++)
        mark[j] = 0;
    cycle = 0;
    for (j = 1; j <= G->n; j++)
        if (mark[j] == 0)
            DFS(G, j);
    return cycle;
}
int main()
{
    freopen("dothi.txt", "r", stdin);
    Graph G;
    int e, u, v, n, m;
    scanf("%d%d", &n, &m);
    init_graph(&G, n, m);
    for (e = 1; e <= m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    if (contains_cycle(&G))
        printf("NO");
    else
        printf("YES");
    return 0;
}
