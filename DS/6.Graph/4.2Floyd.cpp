//
// Created by 渠继旺 on 2022/12/9.
//
#include "2.1邻接矩阵.cpp"

#include "queue"

// Floyd算法
void Floyd(MGraph graph, int A[MaxVertex][MaxVertex], int path[MaxVertex][MaxVertex]);

// 使用Floyd算法获取start到end的路径
std::queue<int> Get_Floyd_Path(MGraph graph, int start, int end);

void Floyd(MGraph graph, int A[MaxVertex][MaxVertex], int path[MaxVertex][MaxVertex]) {
    // 图的结点数量
    int n = graph.vexnum;
    // 初始化A和path两个矩阵
    // A矩阵用来存放最短路径长度，默认可以直接用邻接矩阵的边集矩阵
    // path矩阵用来存放最短路径需要经过的点，-1表示不需要经过其他点
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = graph.Edge[i][j];
            path[i][j] = -1;
        }
    }

    // i表示经过的点，对应笔记中若允许在Vi中转
    for (int i = 0; i < n; ++i) {
        //这里面的两个循环表示允许Vi中转时，更新更短的路径

        // j表示起点
        for (int j = 0; j < n; ++j) {
            // k表示终点
            for (int k = 0; k < n; ++k) {
                // 如果起点到经过的点的距离+经过的点到终点的距离 < 起点到终点的距离，就把经过的点记录到path矩阵，起点到终点的距离改为经过j点的距离
                if (A[j][i] + A[i][k] < A[j][k]) {
                    A[j][k] = A[j][i] + A[i][k];
                    path[j][k] = j;
                }
            }
        }
    }
}

std::queue<int> Get_Floyd_Path(MGraph graph, int start, int end) {
    // 用来存放两个结点之间路径的最短距离
    int A[MaxVertex][MaxVertex];
    // 用来记录最短距离需要经过的点，-1表示不需要经过其他点
    int path[MaxVertex][MaxVertex];
    // 运行Floyd算法得到A和path矩阵
    Floyd(graph, A, path);

    // 用来存放结果的队列
    std::queue<int> Q;

    // 先将起点放到队列中
    Q.push(start);
    // 然后看path中是否有经过其他的点，依次把path中经过的点入队，如果没有经过的点(path对应位置为-1)，此循环就会停止
    while (path[start][end] < 0) {
        start = path[start][end];
        Q.push(start);
    }
    // 最后把终点入队
    Q.push(end);

    return Q;
}