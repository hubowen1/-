#include<stdio.h>
 
typedef struct
{
	int begin;
	int end;
	int weight;
}Edge;

int Find(int* parent,int f)
{
	while(parent[f]>0)
		f=parent[f];
	return f;
} 

void MiniSpanTree_Kruskal(Edge* E)
{
	int i,n,m;
	int parent[9];
	for(i=0;i<9;i++)
	{
		parent[i]=0;
	}
	for(i=0;i<15;i++)
	{
		n=Find(parent,E[i].begin);
		m=Find(parent,E[i].end);
		if(n!=m)
		{
			parent[n]=m;
			printf("(%d,%d) %d\n",E[i].begin,E[i].end,E[i].weight);
		}
	}
}
 

 
int main()
{
	Edge E[15];
	int i;
	
	E[0].begin=4;E[0].end=7;E[0].weight=7;
	
	E[1].begin=2;E[1].end=8;E[1].weight=8;
	
	E[2].begin=0;E[2].end=1;E[2].weight=10;
	
	E[3].begin=0;E[3].end=5;E[3].weight=11;
	
	E[4].begin=1;E[4].end=8;E[4].weight=12;
	
	E[5].begin=3;E[5].end=7;E[5].weight=16;
	
	E[6].begin=1;E[6].end=6;E[6].weight=16;
	
	E[7].begin=5;E[7].end=6;E[7].weight=17;
	
	E[8].begin=1;E[8].end=2;E[8].weight=18;
	
	E[9].begin=6;E[9].end=7;E[9].weight=19;
	
	E[10].begin=3;E[10].end=4;E[10].weight=20;
	
	E[11].begin=3;E[11].end=8;E[11].weight=21;
	
	E[12].begin=2;E[12].end=3;E[12].weight=22;
	
	E[13].begin=3;E[13].end=6;E[13].weight=24;
	
	E[14].begin=4;E[14].end=5;E[14].weight=26;
	
	MiniSpanTree_Kruskal(E);
}


