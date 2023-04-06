/* Do thi cung */
#include <stdio.h>

#define max 100 // so gia tri toi da la 100

// cau truc 1 edge
typedef struct
{
    int x, y; // gia tri dau va cuoi cua 1 cung
} Edge;

// cau truc 1 Graph
typedef struct
{
    int n, m;        // n la so dinh, m la so cung cua graph
    Edge edges[max]; // mang chua cac cung
} Graph;

// ham khoi tao graph G
void init_Graph(Graph *G, int n)
{
    G->n = n;
    G->m = 0;
}

// ham them cung vao graph
void add_Edge(Graph *G, int x, int y)
{
    G->edges[G->m].x = x; // diem dau = x
    G->edges[G->m].y = y; // diem cuoi = y
    G->m++;               // tang so cung len 1 don vi
}

// ham kiem tra cacnh ke
int adjacent(Graph *G, int x, int y)
{
    int i;
    for (i = 0; i < G->m; i++)                             // duyet qua tung cung
        if ((G->edges[i].x == x && G->edges[i].y == y)     // neu diem dau = x va cuoi = y
            || (G->edges[i].x == y && G->edges[i].y == x)) // or
            return 1;                                      // tra ve 1
    return 0;                                              // nguoc lai trar ve 0
}

// ham xac dinh bac cua mot dinh
int degree(Graph *G, int x)
{
    int i, deg = 0;
    for (i = 0; i < G->m; i++) // duyet qua tung cung
    {
        if (G->edges[i].x == x) // neu dinh dau = x
            deg++;              // tang deg
        if (G->edges[i].y == x) // neu dinh cuoi = x
            deg++;              // tang deg
    }
    return deg;
}

// ham xac dinh hang xom cua mot dinh
void neighbors(Graph *G, int x)
{
    int y;
    for (y = 1; y <= G->n; y++) // duyet qua tung dinh
    {
        if (adjacent(G, x, y)) // neu la dinh ke
            printf("%d ", y);  // hien thi ra
    }
    printf("\n");
}

int main()
{
    Graph G;
    int n, m, i, u, v;
    FILE *f = fopen("dothi.txt", "r"); // mo file dothi.txt de doc
    fscanf(f, "%d%d", &n, &m);         // doc hai gai trri hang dau tien la so dinh va so cpung cua do thi
    init_Graph(&G, n);                 // khoi tao graph
    for (i = 1; i <= m; i++)
    {
        fscanf(f, "%d%d", &u, &v);
        add_Edge(&G, u, v);
    }

    for (i = 1; i <= G.n; i++)
        printf("Degree(%d): %d\n", i, degree(&G, i));

    printf("----------------------------------------------\n");
    printf("Danh sach dinh ke\n");
    for (i = 1; i <= G.n; i++)
    {
        printf("Canh ke cua %d: ", i);
        neighbors(&G, i);
    }
}