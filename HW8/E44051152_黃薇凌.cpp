#include<stdio.h>
#include<stdlib.h>
#define MAX 9


void search(int tmp[][MAX],int start,int end);

int main(){
		
	int m,n,k;
	int cost[9][9];
	int dis[9][9];
	int tmp[9][9];
	
	int i,j;
	printf("(i,j)\n");
	scanf("%d %d",&i,&j);
	
	
	for(m=0;m<9;m++){
		for(n=0;n<9;n++){
			cost[m][n]=10000;
			dis[m][n]=10000;
			tmp[m][n]=10000;
		}
	}
	
	cost[0][1]=5;cost[0][2]=4;cost[0][3]=2;
	cost[1][4]=3;
	cost[2][1]=1;cost[2][4]=2;cost[2][5]=8;
	cost[3][2]=1;cost[3][5]=7;
	cost[4][6]=7;cost[4][8]=15;cost[4][7]=10;
	cost[5][7]=3;
	cost[6][8]=6;
	cost[7][8]=5;
	
	//allCosts
	for(m=0;m<9;m++){
		for(n=0;n<9;n++){
			dis[m][n] = cost[m][n];
		}
	}
	
	for(k=0;k<9;k++){
		for(m=0;m<9;m++){
			for(n=0;n<9;n++){
				if(dis[m][k]+dis[k][n]<dis[m][n]){
				dis[m][n]=dis[m][k]+dis[k][n];
				tmp[m][n]=k;	
				}
			}
		}
	}
	
	
	if(dis[i][j]>=10000){
		printf("No solution!\n");
	}
	else{
		printf("Distance:%d\n",dis[i][j]);
		printf("The route for the shortest path:");
		printf("%d",i);
		search(tmp,i,j);
	}
}

 
void search(int tmp[][MAX], int start, int end) {
	
	if(tmp[start][end]==10000){
		printf("->%d",end);
		return;
	}
	else if (tmp[start][end] != 10000) {
		search(tmp, start, tmp[start][end]);
		search(tmp,tmp[start][end],end);
	}
	
}



