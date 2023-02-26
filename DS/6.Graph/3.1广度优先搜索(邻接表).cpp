//
// 主要函数是BFSTraverse和BFS，图是使用邻接矩阵表示的图
//
// 其他的都是一些需要用到的工具方法，比如FirstNeighbor，实际使用中可能在Graph类中实现
//
// 队列这里偷懒直接用了C++的队列，逻辑和第三章队列的差不多（为了统一还加上了初始化队列方法）
//
// Created by 渠继旺 on 2022/11/27.
//
#include "2.2邻接表.cpp"
#include "queue"

#define MAX_VERTEX_NUM 100

// 访问标记数组 [true,false,false]
bool visited[MAX_VERTEX_NUM];

// 这里偷懒直接用了C++内置的队列，所以下面队列的操作与第三章的有点不同
std::queue<int> Q;

// 初始化辅助队列
void InitQueue(std::queue<int> queue1);

// 访问结点
void visit(ALGraph graph, int i);

// 寻找第一个相邻结点
ArcNode *FirstNeighbor(ALGraph graph, int i);

// 寻找下一个相邻结点
ArcNode * NextNeighbor(ArcNode *n);

// 广度优先搜索(遍历非连通图)
void BFSTraverse(ALGraph G);

// 广度优先搜索
void BFS(ALGraph g, int v);

// 广度优先遍历
void BFSTraverse(ALGraph G) {
    for (int v = 0; v < G.vexnum; ++v)
        visited[v] = false;

    InitQueue(Q);

    for (int v = 0; v < G.vexnum; ++v) {
        if (!visited[v])
            BFS(G, v);
    }
}

void BFS(ALGraph G, int v) {
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
        // 5. 让w成为头结点，类似链表的循环访问w的相邻结点
        ArcNode *w = FirstNeighbor(G, v);
        while (w)
            if (!visited[w->adjvex]) {
                visit(G, w->adjvex);
                visited[w->adjvex] = true;
                Q.push(w->adjvex);
                w = NextNeighbor(w);
            }

    }
}


ArcNode *NextNeighbor(ArcNode *n) {
    return n->next;
}

ArcNode *FirstNeighbor(ALGraph graph, int i) {
    return graph.vertices[i].first;
}

void visit(ALGraph graph, int i) {
    printf("%d", graph.vertices[i].data);
}

void InitQueue(std::queue<int> queue1) {
    while (!queue1.empty())
        queue1.pop();
}