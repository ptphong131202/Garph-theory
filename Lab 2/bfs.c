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

typedef struct
{
    int data[MAX_Length];
    int front, rear;
} Queue;

void makenullQueue(Queue *Q)
{
    Q->front = 0;
    Q->rear = -1;
}

void push(Queue *Q, int x)
{
    Q->rear++;
    Q->data[Q->rear] = x;
}

int top(Queue *Q)
{
    return Q->data[Q->front];
}

void pop(Queue *Q)
{
    Q->front++;
}

int empty(Queue *Q)
{
    return Q->front > Q->rear;
}

void bfs(graph *G)
{
    Queue L;
    int mark[MAX_Length];
    makenullQueue(&L);

    int j;
    for (j = 1; j <= G->n; j++)
        mark[j] = 0;
    push(&L, 1);
    printf("duyet 1\n");
    mark[1] = 1;
    while (!empty(&L))
    {
        int x = top(&L);
        pop(&L);
        list list = neighbors(G, x);
        for (j = 0; j < list.size; j++)
        {
            int y = elementAt(&list, j);
            if (mark[y] == 0)
            {
                printf("Duyet %d\n", y);
                mark[y] = 1;
                push(&L, y);
            }
        }
    }
}

void bfs1(graph *G, int a)
{
    Queue L;
    int mark[MAX_Length];
    makenullQueue(&L);

    int j;
    for (j = 1; j <= G->n; j++)
        mark[j] = 0;
    push(&L, a);
    printf("\nDuyet bat dau tu dinh: ");
    printf("%d", a);
    mark[a] = 1;

    while (!empty(&L))
    {
        int x = top(&L);
        pop(&L);
        list list = neighbors(G, x);

        for (j = 0; j < list.size; j++)
        {
            int y = elementAt(&list, j);
            if (mark[y] == 0)
            {
                printf(" %d", y);
                mark[y] = 1;
                if (mark[y] != 0)
                    push(&L, y);
            }
        }
    }
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

    // bfs(&G);
    printf("\n-------------------- \n");
    for (i = 1; i <= G.n; i++)
    {
        bfs1(&G, i);
    }

    return 0;
}
