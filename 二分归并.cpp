#include <stdio.h>
void Mergesort(int r[], int Left, int Right); //�ϲ����к��� 
void Merge(int r[], int Left, int Mid, int Right); //�ϲ����� 
int main()
{
	int  n; 
	printf("����������Ҫ���е����ĸ�����");
	scanf("%d", &n);
	putchar('\n'); 
	int r[n];
	printf("��һ��������Ҫ���е����飺\n");
	for(int i=0;i<n;i++)
	scanf("%d",&r[i]); 
	Mergesort(r, 0, n-1);
	for(int i=0;i<n;i++)
	{
		printf("%d\t", r[i]);
	}
	return 0;
}
void Mergesort(int r[], int Left, int Right)//����r��ʾԭ���飬Left���������ʼ�±꣬Right������Ľ���λ���±� 
{
	int Mid;
	if(Left != Right) //������鲻ֹһ��Ԫ��ʱ 
	{
		Mid = (Left+Right)/2; //��ԭʼ�����Ϊ�����֣�����
		Mergesort(r, Left, Mid); //�Ե�һ����������еݹ����� 
		Mergesort(r, Mid+1, Right); //�Եڶ�����������еݹ����� 
		Merge(r, Left, Mid, Right); //�Է��ε�������еݹ�ϲ� 
	} 
} 
void Merge(int r[], int Left, int Mid, int Right)
{
	int i=Left, j=Mid+1;
	int m=0,n=0;
	int t[Right-Left+1]; //������ʱ�������ڴ�����кõ�ԭ���� �������ʱ����Ĵ�С����ÿ�κ�������Ĵ�С������ 
	while(i <= Mid && j <= Right) // ȷ��������ÿ��������������ֵ������������ 
	{
		if(r[i] <= r[j])
		t[m++] = r[i++];  
		else
		t[m++] = r[j++];
	}
	while(i <= Mid) // ����һ���ֶ������ֵ��������ʱ������� 
	t[m++] = r[i++];
	while(j <= Right) // ���ڶ����ֶ������ֵ��������ʱ������棬ע��Щ�������ֵһ����֮ǰ�������ֵ�� 
	t[m++] = r[j++];
	// ����Ҫ�����������鷵�ظ�ԭ���� 
	m = 0; // ��m��ֵ����Ϊ0 
	for(n=Left; n<=Right; n++) // ��������Ĳ��� 
	r[n] = t[m++];
} 

