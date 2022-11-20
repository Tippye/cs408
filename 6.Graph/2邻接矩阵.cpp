//
// Created by 渠继旺 on 2022/11/20.
//
#define MaxVertex 100

typedef struct {
    char Vex[MaxVertex];                // 顶点表
    int Edge[MaxVertex][MaxVertex];     // 邻接矩阵，边表
    int vexnum, arcnum;                 // 图的当前顶点数，弧数
} MGraph;