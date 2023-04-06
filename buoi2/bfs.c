#include <stdio.h>
/** do thi cung */
#define max 100

// cau truc cung
typedef struct
{
    int u, v; // dim dau va  diem cuoi cua do thi
} edge;

// cau cu Graph
typedef struct
{
    int n, m;       // so dinh va so cung cua do thi
    edge data[max]; // danh sach cac canh cua do thi
} Graph;

// cau truc 1 list
typedef struct
{
    int data[max]; // mang danh sach canh
    int size;      // do dai danh sach
} List;

// khoi tao rong danh sach
void makenullList(List *L)
{
    L->size = 0; // do dai danh sach = 0
}

// tra ve gia tri tai vi tri x
int elementAt(List *L, int x)
{
    return L->data[x - 1];
}

// them phan tu vao danh sach
void pushList(List *L, int x)
{
    L->data[L->size] = x; // vi tri cuoi = x
    L->size++;            // tang vi tri cuoi len mot don vi
}

// khoi tao do thi
void init_Graph(Graph *G, int n)
{
    G->n = n; // so dinh = n
    G->m = 0; // so canh = 0
}

// them cung vao do thi
void add_edge(Graph *G, int u, int v)
{
    int i;
    // kiem tra qua tung cung
    for (i = 0; i < G->m; i++)
    {
        // neu da co canh trong do thi -> khong lam gi ca
        if ((G->data[i].u == u && G->data[i].v == v) ||
            (G->data[i].u == v && G->data[i].v == u))
            return;
    }

    G->data[G->m].u = u;
    G->data[G->m].v = v;
    G->m++;
}

// kiem tra canh ke
int adjacent(Graph *G, int u, int v)
{
    int i;
    for (i = 0; i < G->m; i++)
        if ((G->data[i].u == u && G->data[i].v == v) ||
            (G->data[i].u == v && G->data[i].v == u))
            return 1;
    return 0;
}

// ham tinh bac cua 1 dinh
int degree(Graph *G, int u)
{
    int i, deg = 0;
    for (i = 0; i < G->m; i++)
        if (adjacent(G, u, i))
            deg++;
    return deg;
}

List neighbors(Graph *G, int x)
{
    List L;
    makenullList(&L);
    int i;
    for (i = 1; i <= G->n; i++)
        if (adjacent(G, x, i))
            pushList(&L, i);
    return L;
}

// cau truc 1
typedef struct
{
    int data[max];   // mang dinh
    int front, rear; // vi tri dau cuoi tren mang
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

void bfs(Graph *G)
{
    Queue L;
    int mark[max];
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
        List list = neighbors(G, x);
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

int main()
{
    freopen("dothi.txt", "r", stdin);
    int n, m, u, v, i;
    scanf("%d%d", &n, &m);
    Graph G;
    init_Graph(&G, n);
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    bfs(&G);
    return 0;
}