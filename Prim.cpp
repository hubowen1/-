#include <stdio.h>  
#define MaxVertexNum 9  
#define INFINITY  65535                                                
 
typedef char VertexType;   //顶点是字符型
typedef int EdgeType;   //边是整型
 
typedef struct    //图的邻接矩阵存储结构
{  
 
    VertexType vexs[MaxVertexNum];  //顶点向量  
 
    EdgeType edges[MaxVertexNum][MaxVertexNum];     //邻接矩阵  
 
    int vexnum,arcnum;    //图中当前的顶点数和边数  
 
}MGraph;  
 
/* 邻接矩阵的建立*/ 
 
void CreateGraph(MGraph *G)  
{   
    int i,j,k,weight;  
    char ch1,ch2;  
 
    printf("请输入顶点数和边数(输入格式为:顶点数,边数):");  
 
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));  
 
    printf("请输入顶点名称(输入格式为:a,b,c...)：");  
 
    for(i=0;i<G->vexnum;i++)  
    {  
       getchar();
       scanf("%c",&(G->vexs[i]));  
    }  
 
    for(i=0;i<G->vexnum;i++)  
        for(j=0;j<G->vexnum;j++) 
			if(i==j)
        		G->edges[i][j]=0;
        	else 
            G->edges[i][j]=INFINITY;  
 
        printf("请输入每条边对应的两个顶点名称(输入格式为:a,b):\n");  
 
        for(k=0;k<G->arcnum;k++)  
        {  
            getchar();  
            printf("请输入第%d条边的两个顶点名称：",k+1);  
            scanf("%c,%c",&ch1,&ch2);  
            for(i=0;ch1!=G->vexs[i];i++);  
            for(j=0;ch2!=G->vexs[j];j++);  
            getchar(); 
			printf("请输入第%d条边的权值：",k+1);  
            scanf("%d",&weight);	
            G->edges[i][j]=weight; 
			G->edges[j][i]=weight;   
        }  
}   
 
void MiniSpanTree_Prim(MGraph G)
{
	int min,i,j,k;
	int adjvex[MaxVertexNum];
	int lowcost[MaxVertexNum];
	lowcost[0]=0;
	adjvex[0]=0;
	for(i=1;i<G.vexnum;i++)
	{
		lowcost[i]=G.edges[0][i];
		adjvex[i]=0;
	}
	for(i=1;i<G.vexnum;i++)
	{
		min=INFINITY;
		j=1;k=0;
		while(j<G.vexnum)
		{
			if(lowcost[j]!=0&&lowcost[j]<min)
			{
				min=lowcost[j];
				k=j;
			}
			j++;
		}
		printf("(%d,%d)",adjvex[k],k);
		lowcost[k]=0;
		for(j=1;j<G.vexnum;j++)
		{
			if(lowcost[j]!=0&&G.edges[k][j]<lowcost[j])
			{
				lowcost[j]=G.edges[k][j];
				adjvex[j]=k;
			}
		}
	}
}
int main()  
{  
    MGraph G;  
    CreateGraph(&G);
    MiniSpanTree_Prim(G); 
} 

