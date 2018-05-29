#include<iostream>
using namespace std;

#define MaxVertexNum 100
typedef char vertexType;
typedef int edgeType;

// 邻接矩阵
typedef struct MGragh{
  vertexType Vex[MaxVertexNum]; // 定点表
  edgeType Edge[MaxVertexNum][MaxVertexNum]; // 邻接矩阵
  int vexnum, arcnum; // 顶点数和弧度数
}MGragh;

// 邻接表

// 边表结点
struct arcNode{
  int adjex;
  arcNode *next;
  // InfoType info; // 边权值
};

// 顶点表
typedef struct VNode {
  vertexType data;
  arcNode *first;
}VNode, AdjList[MaxVertexNum];

// 将上面两个结构合起来就是邻接表了
typedef struct ALGraph{
  AdjList vertices; // 长度为一百的顶点表
  int vexnum, arcnum; // 定点数和弧度数
}ALGraph;

// Node  newNode ( G )：建立一个新结点，V=V∪{v}
// void   delNode ( G,  v )：删除结点v以及与v关联的所有边
// void   setSucc ( G, v1, v2 ):E=E∪（v1,v2） ,V=V
// void   delSucc ( G, v1, v2 )：删除边（v1,v2）,V不变
// ListOfNode   succ ( G, v )：求出v的所有直接后继结点
// LisyOfNode  pred ( G, v)：求出v的所有直接前导结点
// int  isEdge ( G, v1, v2 )：判断（v1,v2）∈E
// Node   firstAdjVex( G , v ):  顶点v 的第一个邻接顶点
// Node   nextAdjVex( G, v, w):顶点v 的某个邻接点w的下一个邻接顶点。



int main () {
  MGragh Gragh_1;  // 邻接矩阵
  ALGraph Gragh_2; // 邻接表

  Gragh_1.vexnum = 6;
  Gragh_1.arcnum = 9;
  Gragh_1.Vex[1] = '1';
  Gragh_1.Vex[2] = '2';
  Gragh_1.Vex[3] = '3';
  Gragh_1.Vex[4] = '4';
  Gragh_1.Vex[5] = '5';
  Gragh_1.Vex[6] = '6';
  Gragh_1.Edge[1][2] = 1;
  Gragh_1.Edge[1][4] = 1;
  Gragh_1.Edge[1][6] = 1;
  Gragh_1.Edge[2][3] = 1;
  Gragh_1.Edge[2][4] = 1;
  Gragh_1.Edge[2][5] = 1;
  Gragh_1.Edge[3][5] = 1;
  Gragh_1.Edge[4][5] = 1;
  Gragh_1.Edge[4][6] = 1;



  return 0;
}