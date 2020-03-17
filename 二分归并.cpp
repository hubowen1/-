#include <stdio.h>
void Mergesort(int r[], int Left, int Right); //合并排列函数 
void Merge(int r[], int Left, int Mid, int Right); //合并函数 
int main()
{
	int  n; 
	printf("请输入你想要排列的数的个数：");
	scanf("%d", &n);
	putchar('\n'); 
	int r[n];
	printf("请一次输入你要排列的数组：\n");
	for(int i=0;i<n;i++)
	scanf("%d",&r[i]); 
	Mergesort(r, 0, n-1);
	for(int i=0;i<n;i++)
	{
		printf("%d\t", r[i]);
	}
	return 0;
}
void Mergesort(int r[], int Left, int Right)//其中r表示原数组，Left是数组的起始下标，Right是数组的结束位置下标 
{
	int Mid;
	if(Left != Right) //如果数组不止一个元素时 
	{
		Mid = (Left+Right)/2; //将原始数组分为两部分，分治
		Mergesort(r, Left, Mid); //对第一部分数组进行递归排序 
		Mergesort(r, Mid+1, Right); //对第二部分数组进行递归排序 
		Merge(r, Left, Mid, Right); //对分治的数组进行递归合并 
	} 
} 
void Merge(int r[], int Left, int Mid, int Right)
{
	int i=Left, j=Mid+1;
	int m=0,n=0;
	int t[Right-Left+1]; //创建临时数组用于存放排列好的原数组 ，这个临时数组的大小是由每次函数输入的大小决定的 
	while(i <= Mid && j <= Right) // 确保不超出每个部分数组的最大值，并进行排序 
	{
		if(r[i] <= r[j])
		t[m++] = r[i++];  
		else
		t[m++] = r[j++];
	}
	while(i <= Mid) // 将第一部分多余的数值放置于临时数组后面 
	t[m++] = r[i++];
	while(j <= Right) // 将第二部分多余的数值放置于临时数组后面，注这些多余的数值一定比之前排序的数值大 
	t[m++] = r[j++];
	// 下面要讲排序后的数组返回给原数组 
	m = 0; // 将m的值返回为0 
	for(n=Left; n<=Right; n++) // 返回排序的部分 
	r[n] = t[m++];
} 

