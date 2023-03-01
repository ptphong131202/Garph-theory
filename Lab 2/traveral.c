#include <stdio.h>
#define MAX_Length 20

typedef struct
{
    /* data */
    int u, v; // u = dinh 1, v = dinh 2
} edge;

typedef struct
{
    /* data */
    int n, m;              // n = so dinh, m = so canh
    edge data[MAX_Length]; // e = tap hop cac canh
} graph;

typedef struct
{
    int data[MAX_Length];
    int size;
} list;

void makeNull(list *L)
{
    L->size = 0;
}
int elementAt(list *L, int x)
{
    return L->data[x];
}
void pushList(list *L, int x)
{
    L->data[L->size] = x;
    L->size++;
}

void initGraph(graph *G, int n)
{
    G->n = n;
    G->m = 0;
    printf("Do thi G duoc khoi tao voi so dinh n = %d va so canh m = %d\n", G->n, G->m);
}

void addEdge(graph *G, int u, int v)
{
    int i;
    for (i = 0; i < G->m; i++)
    {
        if ((G->data[i].u == u && G->data[i].v == v) || (G->data[i].u == v && G->data[i].v == u))
        {
            printf("Canh da co trong do thi!\n");
            return;
        }
    }
    G->data[G->m].u = u;
    G->data[G->m].v = v;
    G->m++;
    printf("Do thi da them vao canh %d %d\n", G->data[G->m - 1].u, G->data[G->m - 1].v);
}
int adjacent(graph *G, int u, int v)
{
    int i;
    for (i = 0; i <= G->m; i++)
    {
        if ((G->data[i].u == u && G->data[i].v == v) || (G->data[i].v == u && G->data[i].u == v))
        {
            return 1;
        }
    }
    return 0;
}

void degree(graph *G, int x)
{
    int i, count = 0;
    for (i = 0; i <= G->m; i++)
    {
        if (adjacent(G, x, i))
        {
            count++;
        }
    }
    printf("Bac cua canh %d la: %d\n", x, count);
}

list neighbors(graph *G, int x)
{
    list listVertex;
    makeNull(&listVertex);
    int i;
    for (i = 1; i <= G->n; i++)
    {
        if (adjacent(G, x, i) == 1)
        {
            pushList(&listVertex, i);
        }
    }
    return listVertex;
}

int mark[MAX_Length];

void traversal(graph *G, int x)
{

    if (mark[x] == 1)

        return;
    printf("%d ", x);
    mark[x] = 1;
    int j;
    list list = neighbors(G, x);
    for (j = 0; j < list.size; j++)
    {
        int y = elementAt(&list, j);
        traversal(G, y);
    }
}

void traversal2(graph *G, int x)
{
    if (mark[x] == 1)
        return;
    list L = neighbors(G, x);
    int j;
    for (j = 1; j <= G->n; j++)
        mark[j] = 0;
    int cnt = 0;
    for (j = 1; j <= L.size; j++)
    {
        int y = elementAt(&L, j);
        traversal(G, y);
    }
}
int count_connected_components(graph *G)
{
    /* Khởi tạo mark, chưa đỉnh nào được duyệt */
    int j;
    for (j = 1; j <= G->n; j++)
        mark[j] = 0;
    int cnt = 0;
    for (j = 1; j <= G->n; j++)
        /* Nếu đỉnh j chưa được duyệt, duyệt nó */
        if (mark[j] == 0)
        {
            traversal(G, j);
            cnt++;
        }
    return cnt;
}

void dfs(graph *G, int a)
{
    int i, j;
    for (i = 1; i <= G->n; i++)
        mark[i] = 0;
    traversal(G, a);
    printf("\n");
}

int main(int argc, char const *argv[])
{

    freopen("dothi.txt", "r", stdin);
    int n, m, u, v, i, j;
    scanf("%d%d", &n, &m);
    graph G;
    initGraph(&G, n);
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        addEdge(&G, u, v);
    }

    printf("----------------\n");
    for (i = 1; i <= n; i++)
    {
        printf("duyet dinh %d: \n", i);
        dfs(&G, i);
        printf("----------------\n");
    }

    return 0;
}
