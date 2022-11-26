//
// Created by 渠继旺 on 2022/11/25.
//
#include "2.1邻接矩阵.cpp"
#include "queue"

#define MAX_VERTEX_NUM 100

// 访问标记数组 [true,false,false]
bool visited[MAX_VERTEX_NUM];

std::queue<int> Q;

// 初始化辅助队列
void InitQueue(std::queue<int> queue1);

// 访问结点
void visit(MGraph graph, int i);

int FirstNeighbor(MGraph graph, int i);

int NextNeighbor(MGraph graph, int i, int w);

void BFS(MGraph g, int v);

// 广度优先遍历
void BFSTraverse(MGraph G) {
    for (int v = 0; v < G.vexnum; ++v)
        visited[v] = false;

    InitQueue(Q);

    for (int v = 0; v < G.vexnum; ++v) {
        if (!visited[v])
            BFS(G, v);
    }
}

void BFS(MGraph G, int v) {
    visit(G, v);
    visited[v] = true;
    Q.push(v);
    while (!Q.empty()) {
        v = Q.front();
        Q.pop();
        for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
            if (!visited[w]) {
                visit(G, w);
                visited[w] = true;
                w = Q.front();
                Q.pop();
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