#include <stdio.h>
#define MAX_Length 20
// cau truc cung
typedef struct
{
    /* data */
    int u, v; // u = dinh 1, v = dinh 2
} edge;

// cau truc 1 do thi
typedef struct
{
    /* data */
    int n, m;              // n = so dinh, m = so canh
    edge data[MAX_Length]; // e = tap hop cac canh
} graph;

// cau truc mot danh sach
typedef struct
{
    int data[MAX_Length]; // danh sach du lieu
    int size;             // do dai danh sach
} list;

// ham khoi tao danh sach rong
void makeNull(list *L)
{
    L->size = 0; // vi tri cuoi cung  = 0
}
// lay phan tu o vi tri x trong danh sach
int elementAt(list *L, int x)
{
    return L->data[x];
}

// them phan tu vao danh sach
void pushList(list *L, int x)
{
    L->data[L->size] = x; // phan tu sau phan tu cuoi trong danh sach  = x
    L->size++;            // tang do dai danh sach len 1 don vi
}

// khoi tao do thi G
void initGraph(graph *G, int n)
{
    G->n = n; // so dinh  = n
    G->m = 0; // so cung  = 0
    printf("Do thi G duoc khoi tao voi so dinh n = %d va so canh m = %d\n", G->n, G->m);
}

// them cung vao do thi
void addEdge(graph *G, int u, int v)
{
    int i;
    for (i = 0; i < G->m; i++) // duyet qua tung cung
    {
        // neu dau = u cuoi = v or dau = v cuoi = u
        if ((G->data[i].u == u && G->data[i].v == v) || (G->data[i].u == v && G->data[i].v == u))
        {
            printf("Canh da co trong do thi!\n"); // da co
            return;                               // khong lam gi het
        }
    }
    // nguoc lai
    G->data[G->m].u = u; // them dinh u
    G->data[G->m].v = v; // them dinh v
    G->m++;              // tang so cung len
    printf("Do thi da them vao canh %d %d\n", G->data[G->m - 1].u, G->data[G->m - 1].v);
}

// tim anh em ke
int adjacent(graph *G, int u, int v)
{
    int i;
    for (i = 0; i <= G->m; i++) // duyet qua tung cung
    {
        // neu dau = u cuoi = v or dau = v cuoi = u
        if ((G->data[i].u == u && G->data[i].v == v) || (G->data[i].v == u && G->data[i].u == v))
        {
            return 1; // tra ve 1
        }
    }
    return 0; // nguoc lai tra ve 0
}

// tim bac cua mot dinh x
void degree(graph *G, int x)
{
    int i, count = 0;           // khoi tao count = 0
    for (i = 0; i <= G->m; i++) // duye qua tung cung
    {
        if (adjacent(G, x, i)) // neu ke
        {
            count++; // tang count
        }
    }
    printf("Bac cua canh %d la: %d\n", x, count);
}

// danh sach hang xom
list neighbors(graph *G, int x)
{
    list listVertex; // khoi tao mot danh sach
    makeNull(&listVertex);
    int i;
    for (i = 1; i <= G->n; i++) // duyet qua tung cung
    {
        if (adjacent(G, x, i) == 1) // neu ke
        {
            pushList(&listVertex, i); // them dinh vao danh sach
        }
    }
    return listVertex; // tra ve danh sach ke
}

#define max_lengh 100
// cau truc stack
typedef struct
{
    int data[max_lengh]; // mang du lieu
    int size;            // chieu dai mang
} Stack;

// khoi tao stack
void makenullStack(Stack *S)
{
    S->size = 0; // chieu dai stack = 0
}

// them phan tu vao stack
void push(Stack *S, int x)
{
    S->data[S->size] = x; // them vao vi tri cuoi danh sach mang
    S->size++;            // tang chieu dai len 1 don vi
}

// lay gia tri tai dinh
int top(Stack *S)
{
    return S->data[S->size - 1];
}

// xoa phan tu tai dinh
void pop(Stack *S)
{
    S->size--; // giam chieu dai stack
}

// kiem tra rong
int empty(Stack *S)
{
    return S->size == 0; // neu chieu dai = 0 thi tra ve 0 nguoc lai tra ve 1
}

// ham duyet sau dfs
void dfs(graph *G)
{
    Stack L;
    int mark[max_lengh]; // phan tu dinh vi
    makenullStack(&L);   // khoi tao stack
    int j;
    for (j = 1; j <= G->n; j++) // duyet qua tung dinh
        mark[j] = 0;            // gan mark = 0
    push(&L, 1);                // kay dinh 1 vao stack
    printf("Duyet DFS:");
    while (!empty(&L)) // trong khi stack khong rong
    {
        int x = top(&L);                // lay gia tri phan tu dau
        pop(&L);                        // xoa phan tu dau
        if (mark[x] != 0)               // neu mark = 1
            continue;                   // khong lam gi ca
        printf(" %d", x);               // hien thi x ra
        mark[x] = 1;                    // gan mark = 1 da duyet
        list list = neighbors(G, x);    // lay danh sach anh em ke cua x
        for (j = 0; j < list.size; j++) // duyet qua tung anh em ke cua nos
        {
            int y = elementAt(&list, j); // lay phan tu ke
            push(&L, y);                 // them vao stack
        }
    }
    printf("\n");
}

// duyet tu dinh x
void dfs1(graph *G, int x)
{
    Stack L;
    int mark[max_lengh]; // khoi tao bien mark
    makenullStack(&L);   // khoi tao 1 stack
    int j;
    for (j = 1; j <= G->n; j++) // duyet qua tung dinh
        mark[j] = 0;            // gan moi dinh la chua duyet
    push(&L, x);                // lay phan tu x them vao stack
    printf("Duyet DFS:");
    while (!empty(&L)) // neu stack khong rong
    {
        int x = top(&L);                // lay phan tu dau
        pop(&L);                        // xoa phan tu dau
        if (mark[x] != 0)               // neu da duyet
            continue;                   // khong duyet dinh nay nua
        printf(" %d", x);               // hien thi no ra
        mark[x] = 1;                    // gan cho no da duyet
        list list = neighbors(G, x);    // tao 1 danh sach anh em ke voi x
        for (j = 0; j < list.size; j++) // duyet qua tung anh em
        {
            int y = elementAt(&list, j); // lay gia tri cua anh em
            push(&L, y);                 // them vao stack
        }
    }
    printf("\n");
}

// duyet chieu sau theo beo phan lien thong
void dfs2(graph *G, int x, int a[max_lengh])
{
    Stack L;
    int mark[max_lengh];
    makenullStack(&L); // khoi ta stack
    int j;
    for (j = 1; j <= G->n; j++) // duyet qua tung dinh
        mark[j] = 0;            // gan chu duyet
    push(&L, x);                // them x vao stack
    printf("Duyet DFS:");
    while (!empty(&L)) // neu khong rong
    {
        int x = top(&L);  // lay dau
        pop(&L);          // xoa dau
        if (mark[x] != 0) // da duyet
            continue;
        printf(" %d", x);               // in x
        mark[x] = 1;                    // gan da duyet
        list list = neighbors(G, x);    // tao danh sach anh em ke
        for (j = 0; j < list.size; j++) // duyet tung dua
        {
            int y = elementAt(&list, j); // lay gia tri cua moi dua
            push(&L, y);                 // them vao stack
            a[x] = 1;                    // gan la da duyet
        }
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{

    freopen("dothi.txt", "r", stdin);
    int n, m, u, v, i, j;
    scanf("%d%d", &n, &m);
    graph G;
    initGraph(&G, n);
    printf("---------------\n");
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        addEdge(&G, u, v);
    }

    printf("----------------\n");
    for (i = 1; i <= G.n; i++)
    {
        dfs1(&G, i);
    }
    int a[max_lengh];
    printf("----------------\n");
    for (i = 1; i <= G.n; i++)
        a[i] = 0;
    for (j = 1; j <= G.n; j++)
    {
        if (a[j] == 0)
            dfs2(&G, j, a);
    }

    return 0;
}
