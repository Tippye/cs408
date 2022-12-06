//
// Created by 渠继旺 on 2022/11/28.
//
#include "2.1邻接矩阵.cpp"
#include "queue"

#define MAX_VERTEX_NUM 100
#define INFINITY (2^(sizeof(int)*8)-1)  //定义∞，用int最大值当作无穷

// 访问标记数组 [true,false,false]
bool visited[MAX_VERTEX_NUM];
int d[MAX_VERTEX_NUM];
int path[MAX_VERTEX_NUM];

// 这里偷懒直接用了C++内置的队列，所以下面队列的操作与第三章的有点不同
std::queue<int> Q;

// 初始化辅助队列
void InitQueue(std::queue<int> queue1);

// 访问结点
void visit(MGraph graph, int i);

// 寻找第一个相邻结点
int FirstNeighbor(MGraph graph, int i);

// 寻找下一个相邻结点
int NextNeighbor(MGraph graph, int i, int w);

// 广度优先搜索寻找最短路径
void BFS_MIN_Distance(MGraph graph, int u);

void BFS_MIN_Distance(MGraph graph, int u) {
    InitQueue(Q);
    for (int i = 0; i < graph.vexnum; ++i) {
        d[i] = INFINITY;
        path[i] = -1;
    }
    d[u] = 0;
    visited[u] = true;
    Q.push(u);
    while (!Q.empty()) {
        Q.pop();
        for (int w = FirstNeighbor(graph, u); w >= 0; w = NextNeighbor(graph, u, w)) {
            if (!visited[w]) {
                d[w] = d[u] + 1;
                path[w] = u;
                visited[w] = true;
                Q.push(w);
            }
        }
    }
}

int NextNeighbor(MGraph graph, int i, int w) {
    for (int j = w; j < graph.vexnum; ++j) {
        if (graph.Edge[i][j] != 0)
            return j;
    }
    return -1;
}

int FirstNeighbor(MGraph graph, int i) {
    for (int j = 0; j < graph.vexnum; ++j) {
        if (graph.Edge[i][j] != 0)
            return j;
    }
    return -1;
}

void visit(MGraph graph, int i) {
    printf("%d", graph.Vex[i]);
}

void InitQueue(std::queue<int> queue1) {
    while (!queue1.empty())
        queue1.pop();
}