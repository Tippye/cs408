//
// Created by 渠继旺 on 2022/12/6.
//
#include "2.1邻接矩阵.cpp"

#define MAX_VERTEX_NUM 100
#define INFINITY (2^(sizeof(int)*8)-1)  //定义∞，用int最大值当作无穷

// 标记各顶点是否已经找到最短路径
bool final[MAX_VERTEX_NUM];
// 最短路径长度
int dist[MAX_VERTEX_NUM];
// 路径上的前驱
int path[MAX_VERTEX_NUM];

void InitDijkstra(MGraph graph, int v, bool final, int dist, int path);

void Dijkstra(MGraph graph, int v);

int Get_MIN_Node(bool final, int dist);

//void Dijkstra_MIN_Distance(MGraph graph,)

void InitDijkstra(MGraph graph, int v, bool *final, int *dist, int *path) {
    for (int i = 0; i < MAX_VERTEX_NUM; ++i) {
        // 先把所有顶点都标记为未访问(循环结束后会把起始点标记为访问)
        final[i] = false;
        // 把所有边的距离修改为初始点到第i个点的距离，这里是邻接矩阵方式，对应的值为边的权(距离), 没有边的话就记为INFINITY
        dist[i] = graph.Edge[v][i];
        // 如果与初始点没有边就把前驱结点标为-1，否则就标为0
        path[i] = dist[i] == INFINITY ? -1 : 0;
    }
    // 循环结束后把起始点标记为已访问
    final[v] = true;
    // 到初始点的距离为0
    dist[v] = 0;
    // 初始点的前驱结点记为-1
    path[v] = -1;
}

int Get_MIN_Node(bool final[], int dist[], int size) {
    int r = 0, min = dist[0];
    for (int i = r; i < size; ++i)
        if (!final[i] && dist[i] < min) {
            r = i;
            min = dist[i];
        }
    return r;
}

/**
 *
 * @param graph     图
 * @param v         初始结点
 * @param final      标记个顶点是否已经找到最短路径
 * @param dist      最短路径长度
 * @param path      路径上的前驱
 */
void Dijkstra(MGraph graph, int v, bool *final, int *dist, int *path) {
    InitDijkstra(graph, v, final, dist, path);

    // 记录访问过多少个结点了
    // 初始结点在初始化的时候就访问过了，所以直接让count等于1
    int count = 1;
    // 用count判断是否访问了所有节点
    while (count < graph.vexnum) {
        // 获取未访问的路径长度最短的结点
        int min = Get_MIN_Node(final, dist, graph.vexnum);

        for (int i = 0; i < graph.vexnum; ++i) {
            // 把与min结点相邻的未被访问的结点的路径长度更新
            if (final[i])
                continue;
            if (graph.Edge[min][i] == INFINITY)
                continue;
            // 从min结点到第i个结点，这样从初始结点到第i个结点的路径长度为dist[min] + graph.Edge[min][i]
            if (dist[min] + graph.Edge[min][i] < dist[i]) {
                dist[i] = dist[min] + graph.Edge[min][i];
                // 对应的前驱结点更新
                path[i] = min;
            }
        }

        // min结点标记为访问过，并把访问过的结点的数量+1
        final[min] = true;
        count++;
    }
};