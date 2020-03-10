#include<stdio.h>

int main(){
	int T[100];
	int x,y;
	int i=0;
	scanf("%d",&x);
	int temp=x;
	while(x--){
		scanf("%d",&T[i++]);
	}
	int z;
	scanf("%d",&z);
	for(int j=0;j<temp;j++){
		if(z==T[j]){
			printf("j=%d",j+1);
			break;
		}
		if(j==temp-1&&z!=T[j]){
			printf("j=0");
		}
	}

} 
