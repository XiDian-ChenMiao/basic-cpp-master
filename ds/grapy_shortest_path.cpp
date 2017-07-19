#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 4//表示最大节点个数
#define INFINITY 65535//用65535表示无穷大
//图的定义部分
typedef int VertexType;//顶点类型用户自定义
typedef int EdgeType;//边上的权值类型应由用户定义

typedef struct
{
         VertexType vexs[MAXVEX];//顶点表
         EdgeType arc[MAXVEX][MAXVEX];//邻接矩阵，可看做边表
         int numVertexes,numEdges;//图中当前的顶点数和边数
}MGraph;
//建立无向图的邻接矩阵表示
void CreateMGraph(MGraph *G)
{
     int i,j,k,w;
     printf("输入顶点数和边数:");
     scanf("%d%d",&G->numVertexes,&G->numEdges);
     //读入顶点信息，建立顶点表
     /*
     for(i = 0;i < G->numVertexes;i++)
           scanf("%d",&G->vexs[i]);
           */
     //对邻接矩阵进行初始化
     for(i = 0;i < G->numVertexes;i++)
           for(j = 0;j < G->numVertexes;j++)
                 G->arc[i][j] = INFINITY;
     //输入numEdges条边，建立邻接矩阵
     for(k = 0;k < G->numEdges;k++)
     {
           printf("输入边(Vi,Vj)上的下标i,下标j和w:");
           scanf("%d%d%d",&i,&j,&w);//输入边的起始和终止索引，以及权值
           G->arc[i][j] = w;
           G->arc[j][i] = G->arc[i][j];//无向图的邻接矩阵是对称的矩阵
     }
}
//P[v]的值为前驱顶点下标，D[v]表示V0到V的最短路径长度和
void ShortestPath_Dijkstra(MGraph G,int v0,int P[],int D[])
{
     int v,w,k,min;
     int final[MAXVEX];//final[w] = 1表示求得顶点V0到Vw的最短路径
     //初始化数据
     for(v = 0;v < G.numVertexes;v++)
     {
           final[v] = 0;//全部顶点初始化为未知最短路径状态
           D[v] = G.arc[v0][v];//将与v0点连线的顶点加上权值
           P[v] = 0;//初始化路径数组P为0
     }
     D[v0] = 0;//v0至v0路径为0
     final[v0] = 1;//v0至v0不需要路径
     //开始主循环，每次求得v0到某个顶点v的最短路径
     for(v = 1;v < G.numVertexes;v++)
     {
           min = INFINITY;//当前所知离v0顶点最近的距离
           for(w = 0;w < G.numVertexes;w++)//寻找离v0最近的顶点
           {
                 if(!final[w] && D[w] < min)
                 {
                              k = w;
                              min = D[w];//w顶点离v0顶点更近
                 }
           }
           final[k] = 1;//将目前找到的最近的顶点置1
           for(w = 0;w < G.numVertexes;w++)//修正当前最短路径及距离
           {
                 //如果经过v顶点的路径比现在这条路径的长度短的话
                 if(!final[w] && (min + G.arc[k][w] < D[w]))
                 {
                              //说明找到了更短的路径，修改D[w]和P[w]
                              D[w] = min + G.arc[k][w];//修改当前路径长度
                              P[w] = k;
                 }
           }
     }
}
//打印最短路径信息
void Show_shortestPath(MGraph G,int start,int end,int P[],int D[])
{
     printf("最短路径为:%d<--",end);//打印目的结点
     int End = P[end];
     while(End != start)
     {
               printf("%d<--",End);
               End = P[End];
     }
     printf("%d.长度为:%d.\n",start,D[end]);
}
int main()
{
    MGraph G;
    int P[MAXVEX],D[MAXVEX];
    CreateMGraph(&G);
    //调用Dijkstra算法来求v0顶点到其他顶点的最短路径
    ShortestPath_Dijkstra(G,0,P,D);
    Show_shortestPath(G,0,3,P,D);
    system("pause");
    return 0;
}
 
