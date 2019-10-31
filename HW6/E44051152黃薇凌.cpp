#include<stdio.h>
#include<stdlib.h>

int parent[100]={0};
int rank[100]={0};
void Union(int x,int y);
void print(int x);

int main(){
	
	int n;
	int i;
	scanf("%d",&n);
	int h=n;
	

	for(i=0;i<n;++i){
		parent[i]=i;
		rank[i]=0;
	}
	// 先預設parent和rank 
	/* 	num		| 0  | 1  | 2  | 3  |
		parent  | 0  | 1  | 2  | 3  |
		rank    | -1 | -1 | -1 | -1 |  
	*/
	for(i=1;i<n;++i){
		Union(0,i);
	}
	
	printf(" Node     parent\n");
	
	for(i=0;i<n;++i){
		print(i);
		printf("\n");
	}
	
} 


void Union(int x,int y){
	//比較rank 
	if(rank[x]<=rank[y]){
		parent[y]=x;
		rank[x]=rank[x]+rank[y];
	}
	else{
		parent[x]=y;
		rank[y]=rank[y]+rank[x];
	}
	
}

void print(int x){
	printf("  %d       ",x);
	if(parent[x]==x)
		printf(" root");
	else
		printf("  %d      ",parent[x]);
}

