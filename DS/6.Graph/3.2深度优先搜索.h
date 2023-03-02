// 主要函数是DFSTraverse和DFS，图是使用邻接矩阵表示的图
//
// 其他的都是一些需要用到的工具方法，比如FirstNeighbor，实际使用中可能在Graph类中实现
//
// Created by 渠继旺 on 2022/11/27.
//
#include <cstdio>
#include "2.1邻接矩阵.cpp"

#define MAX_VERTEX_NUM 100

// 访问标记数组 [true,false,false]
bool visited[MAX_VERTEX_NUM];

// 访问结点
void visit(MGraph graph, int i);

// 寻找第一个相邻结点
int FirstNeighbor(MGraph graph, int i);

// 寻找下一个相邻结点
int NextNeighbor(MGraph graph, int i, int w);

// 深度优先搜索(遍历非连通图)
void DFSTraverse(MGraph G);

// 深度优先搜索
void DFS(MGraph g, int v);

// 深度优先遍历
void DFSTraverse(MGraph G) {
    // 1. 同BFS，只是不用初始化队列
    for (int v = 0; v < G.vexnum; ++v)
        visited[v] = false;

    for (int v = 0; v < G.vexnum; ++v) {
        if (!visited[v])
            DFS(G, v);
    }
}

void DFS(MGraph G, int v) {
    // 1. 访问结点
    visit(G, v);
    // 2. 把visited数组中对应位置改为true表示已经访问过
    visited[v] = true;
    // 3. 循环结点的相邻结点并再次调用DFS，如果是没有未访问的相邻结点会不能继续调用DFS，也就会结束递归
    for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
        if (!visited[w])
            DFS(G, v);
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
