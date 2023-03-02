// 主要函数是DFSTraverse和DFS，图是使用邻接矩阵表示的图
//
// 其他的都是一些需要用到的工具方法，比如FirstNeighbor，实际使用中可能在Graph类中实现
//
// Created by 渠继旺 on 2022/11/27.
//
#include <cstdio>
#include "2.2邻接表.cpp"

#define MAX_VERTEX_NUM 100

// 访问标记数组 [true,false,false]
bool visited[MAX_VERTEX_NUM];

// 访问结点
void visit(ALGraph graph, int i);

// 寻找第一个相邻结点
ArcNode *FirstNeighbor(ALGraph graph, int i);

// 寻找下一个相邻结点
ArcNode *NextNeighbor(ArcNode *n);

// 深度优先搜索(遍历非连通图)
void DFSTraverse(ALGraph G);

// 深度优先搜索
void DFS(ALGraph g, int v);

// 深度优先遍历
void DFSTraverse(ALGraph G) {
    // 1. 同BFS，只是不用初始化队列
    for (int v = 0; v < G.vexnum; ++v)
        visited[v] = false;

    for (int v = 0; v < G.vexnum; ++v) {
        if (!visited[v])
            DFS(G, v);
    }
}

void DFS(ALGraph G, int v) {
    // 1. 访问结点
    visit(G, v);
    // 2. 把visited数组中对应位置改为true表示已经访问过
    visited[v] = true;
    ArcNode *w = FirstNeighbor(G, v);
    // 3. 循环结点的相邻结点并再次调用DFS，如果是没有未访问的相邻结点会不能继续调用DFS，也就会结束递归
    while (w) {
        if (!visited[w->adjvex])
            DFS(G, w->adjvex);
        w = NextNeighbor(w);
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
