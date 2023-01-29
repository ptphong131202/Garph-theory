#include <stdio.h>

#define max 500 // số cung tối đa

// cấu trúc của một cung
typedef struct
{
    int u, v; // đỉnh đầu và đỉnh cuối
} Edge;

// cấu trúc của đồ thị
typedef struct
{
    int n, m;        // n là số đỉnh, m là só cung
    Edge edges[max]; // lưu các cung vào mảng
} Graph;

// khởi tạo graph
void initGraph(Graph *G, int n) // n là số đỉnh
{
    G->n = n; // gán số đỉnh
    G->m = 0; // gán số cung = 0
}

// thêm cung vào mảng
void addEdge(Graph *G, int u, int v)
{
    // Đưa cung u,v vào edges
    G->edges[G->m].u = u;
    G->edges[G->m].v = v;
    // tăng số cung lên 1
    G->m++;
}

// kiểm tra u có kề với v hay không
int adjacent(Graph *G, int u, int v)
{
    int e;
    // duyệt qua tùng cung
    for (e = 0; e < G->m; e++)
        if (G->edges[e].u == u && G->edges[e].v == v || G->edges[e].u == v && G->edges[e].v == u)
            return 1;
    return 0;
}

// bậc của đỉnh u
int degree(Graph *G, int u)
{
    int e, degU = 0;
    // duyệt qua tùng cung
    for (e = 0; e < G->m; e++)
    {
        if (G->edges[e].u == u)
            degU++;
        if (G->edges[e].v == u)
            degU++;
    }
    return degU;
}
// Hàm main()
int main()
{
    Graph G;
    int n, m, e, u, v;
    // Mở file dothi.txt để đọc dữ liệu
    FILE *file = fopen("dothi.txt", "r");
    // Đọc số đỉnh và số cung & khởi tạo đồ thị
    fscanf(file, "%d%d", &n, &m);
    initGraph(&G, n);
    // Đọc m cung
    for (e = 0; e < m; e++)
    {
        fscanf(file, "%d%d", &u, &v);
        addEdge(&G, u, v);
    }
    // Đóng file
    fclose(file);
    return 0;
}