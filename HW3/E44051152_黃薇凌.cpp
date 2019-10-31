#include<stdio.h>


//迷宮本人 
int maze[1010][1010];

//用來紀錄迷宮已確認過的位置 
int mark[1010][1010]; 


//存0~7移動方向的陣列 
typedef struct{
	short int vert;
	short int horiz;
} offsets;
offsets move[8];


typedef struct{
	short int row;
	short int col;
	short int dir;
} element;
element pos[1010*1010];

//空的堆疊
int top = -1;

//出口指標 
int exit_row;
int exit_col;

//入口指標 
int start_row;
int start_col;


//初始值為0，成功則為1 
int found = 0;

//N*M matrix(題目要求) 
int N;
int M;

void map();
void path();


int main(){
	
	//移動方向 
	move[0].vert=-1;
	move[1].vert=-1;
	move[2].vert=0;
	move[3].vert=1;
	move[4].vert=1;
	move[5].vert=1;
	move[6].vert=0;
	move[7].vert=-1;
	
	move[0].horiz=0;
	move[1].horiz=1;
	move[2].horiz=1;
	move[3].horiz=1;
	move[4].horiz=0;
	move[5].horiz=-1;
	move[6].horiz=-1;
	move[7].horiz=-1;
	
	//先把地圖讀進來 
	map();
	
	int nextrow;
	int nextcol;
	int row;
	int col;
	int dir;
	
 	//while(stack不是空的) 
	while(top > -1 && !found){
		//移動至stack頂端儲存的位置 
		row = pos[top].row;
		col = pos[top].col;
		dir = pos[top].dir;
		top --;
		
		//while(從目前位置出發還有可以移動的位置) 
		while(dir < 8 && !found){
			int nextrow = row + move[dir].vert;
			int nextcol = col + move[dir].horiz;
			
			//走到出口 
			if((nextrow == exit_row)&&(nextcol == exit_col)){
				top ++;
				pos[top].row = row;
				pos[top].col = col;
				pos[top].dir = dir;
				found = 1;
			}
			
			//合理移動且之前沒到過這裡 
			else if(maze[nextrow][nextcol]==0 && mark[nextrow][nextcol]==0){
				//儲存目前的方向和位置
				//加入<row,col,dir>到stack頂端
				 
				mark[nextrow][nextcol] = 1;
				 
				top ++;
				pos[top].row = row;
				pos[top].col = col;
				pos[top].dir = ++dir;
				row=nextrow;
				col=nextcol;
				dir=0;
			} 
			else 
				++dir;
		}
		
	}
	path();
	return 0;
}

//讀地圖 
void map(){

	
	int i,j;
	
	//初始化陣列 
	for(i=0;i<1010;++i){
		for(j=0;j<1010;++j){
			maze[i][j] = 0;
			mark[i][j] = 0;
		}
	}

	
	
	scanf("%d%d",&M,&N);


	//先用1把邊緣圍起來 
	for(i=0;i<M+2;++i){ 
		maze[i][0] = 1;
		maze[i][N+1] = 1;
		} 
		
	for(j=0;j<N+2;++j){ 
		maze[0][j] = 1;
		maze[M+1][j] = 1;
		} 
	
	
	exit_row = N-1;
	exit_col = M-1;
	int row = 1;
	int col = 1;
	char c;
	
	//讀取地圖 
	c=getchar();
	while((c=getchar())!=EOF){
		if(c=='s'){
			top++;
			pos[top].row = row;
			pos[top].col = col;
			pos[top].dir = 0;
			start_row = row;
			start_col = col;
			mark[row][col]=1;
			col ++;
		}
		else if(c=='d'){
			exit_row = row;
			exit_col = col;
			col++;
		}
		else if(c=='\n'){
	 		row ++;
			col = 1;
			}
		else if(c=='1'){
			maze[row][col] = 1;
			col ++;
		} 
		else if(c=='0'){
			maze[row][col] = 0;
			col ++;
		}
		else{
			printf("error!\n");
		}	
	} 
}


//輸出迷宮路徑 
void path(){
	
	int k=1;
	int i;
	int j;

	
	//如果有路徑 
	if(found){
		while(top > -1){
			maze[pos[top].row][pos[top].col] = 666;
			k++;
			top--;
		}
		//開始印出路徑 
		for(i=1;i<M+1;++i){
			for(j=1;j<N+1;++j){
				//入口 
				if(i==start_row&&j==start_col){
					printf("s");
				}
				//出口 
				else if(i==exit_row&&j==exit_col){
					printf("d");
				}
				else if(maze[i][j] == 666){
					printf("*");
				}
				else
					printf("%d",maze[i][j]);
			}
			printf("\n");
		}	
	}
	//如果沒有路徑 
	else{ 
		printf("No route\n");
		} 
	//印出步數 
	printf("%d steps\n",k);
	return;
}
