#ifndef __PRIM_AND_KRUSKAL_H__
#define __PRIM_AND_KRUSKAL_H__

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 100  //最大结点个数
#define INFINITY 65535 //用来表示无穷大的数据
typedef int ElemType;//自定义用户数据类型
typedef float EdageType;//自定义边的数据类型
//定义图的数据结构
/*
typedef struct
{
	int number;//顶点编号
	ElemType data;//其他数据信息
}VertexType;//节点类型
*/
typedef struct
{
	//VertexType vexs[MAX_VERTEX];//存放顶点信息
	int vertex;//指定结点个数
	int arcnum;//指定弧的个数
	EdageType edages[MAX_VERTEX][MAX_VERTEX];//存储边的大小信息
}Graphics;

/*普利姆算法用来求最小生成树*/
/*算法思想：
1.在把生成树看成一个集合（开始集合为空，到各个结点的距离当然未知）
2.结点与集合之间的权值可以看成结点到集合距离
3.将第一个结点加入集合，并初始化集合与其他结点的距离
4.搜索集合与结点最小的权值（距离），并把这点加入集合
5.更新集合与结点之间的距离
6.不断重复4和5步，直到所有的结点都加入了集合
*/
Graphics Func_Input(){
    Graphics G;
	int i,j,tempWeight;//权值
	//提示输入边的个数
	printf("VertexNumber:");
	scanf("%d",&G.vertex);
	//提示输入弧的个数
	printf("EdagesNumber:");
	scanf("%d",&G.arcnum);
	for(i = 0;i < G.vertex;i++)
		for(j = 0;j < G.vertex;j++)
		{
			scanf("%d",&tempWeight);
			G.edages[i][j] = (tempWeight == -1)?INFINITY : tempWeight;
		}
	return G;
}
void Prim_MiniGenerateTree(Graphics G){
	int min,i,j,k;
	int adjvex[MAX_VERTEX];//保存相关顶点下标
	int lowcost[MAX_VERTEX];//保存相关顶点间边的权值

	lowcost[0] = 0;//V0作为最小生成树的根开始遍历，权值为0
	adjvex[0] = 0;//V0第一个加入

	//初始化操作
	for(i = 1; i < G.vertex;++i)
	{
		lowcost[i] = G.edages[0][i];//将邻接矩阵第0行所有权值先加入数组
		adjvex[i] = 0;//初始化全部先为V0的下标
	}
	//真正构造最小生成树的过程
	for(i = 1; i < G.vertex;++i)
	{
		min = INFINITY;//初始化最小权值为INFINITY
		j = 1;
		k = 0;
		//遍历全部顶点
		while(j < G.vertex)
		{
			//找出lowcost数组已存储的最小权值
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;//将发现的最小权值的下标存入k，以待使用
			}
			j++;
		}
		//打印当前顶点边中权值最小的边
		printf("边(%d,%d)\n", adjvex[k],k);
		//将当前顶点的权值设置为0，表示此顶点已经完成任务，进行下一个顶点的遍历
		lowcost[k] = 0;
		//邻接矩阵k行逐个遍历全部顶点
		for(j = 1;j < G.vertex;j++){
			if (lowcost[j] != 0 && G.edages[k][j] < lowcost[j])
			{
				lowcost[j] = G.edages[k][j];
				adjvex[j] = k;
			}
		}
	}
}
#endif
