//
// 主要函数是BFSTraverse和BFS，图是使用邻接矩阵表示的图
//
// 其他的都是一些需要用到的工具方法，比如FirstNeighbor，实际使用中可能在Graph类中实现
//
// 队列这里偷懒直接用了C++的队列，逻辑和第三章队列的差不多（为了统一还加上了初始化队列方法）
//
// Created by 渠继旺 on 2022/11/25.
//
#include "2.1邻接矩阵.cpp"
#include "queue"

#define MAX_VERTEX_NUM 100

// 访问标记数组 [true,false,false]
bool visited[MAX_VERTEX_NUM];

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

// 广度优先搜索(遍历非连通图)
void BFSTraverse(MGraph G);

// 广度优先搜索
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
    // 1. 访问结点
    visit(G, v);
    // 2. 把visited数组中对应位置改为true表示已经访问过
    visited[v] = true;
    // 3. 把结点放到队列中
    Q.push(v);
    // 4. 循环队列，类似树的层序遍历，每次出队一个结点就把该结点的子结点(相邻结点)入队
    while (!Q.empty()) {
        v = Q.front();
        Q.pop();
        // 5. 先让w为该结点的第一个相邻结点，然后每次循环都变成下一个相邻结点。如果已经是最后一个结点，NextNeighbor会返回-1
        for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
            // 6. visited对应位置为true的表示已经访问过，这里只访问未访问过的
            //    因为是广度优先，所以再写一遍visit，不能递归调用BFS，那样会变成深度优先
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