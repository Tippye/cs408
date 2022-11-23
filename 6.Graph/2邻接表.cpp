//
// Created by 渠继旺 on 2022/11/23.
//
#define MaxVertexnum 100
#define VertextType int
#define InfoType int

// 边/弧
typedef struct ArcNode {
    int adjvex;             //该弧指向的顶点的位置
    struct ArcNode *next;   //下一条弧的指针
//    InfoType info;          //网的边权值,如果需要权值可以解开此行
} ArcNode;

// 顶点
typedef struct VNode {
    VertextType data;       //顶点表的结点
    ArcNode *first;          //顶点信息
} VNode, AdjList[MaxVertexnum];

// 用邻接表存储的图
typedef struct {
    AdjList vertices;       //邻接表
    int vexnum, arcnum;     //图的顶点数和弧数
} ALGraph;                  //ALGraph是以邻接表存储的图类型