#include<stdio.h>


//�g�c���H 
int maze[1010][1010];

//�ΨӬ����g�c�w�T�{�L����m 
int mark[1010][1010]; 


//�s0~7���ʤ�V���}�C 
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

//�Ū����|
int top = -1;

//�X�f���� 
int exit_row;
int exit_col;

//�J�f���� 
int start_row;
int start_col;


//��l�Ȭ�0�A���\�h��1 
int found = 0;

//N*M matrix(�D�حn�D) 
int N;
int M;

void map();
void path();


int main(){
	
	//���ʤ�V 
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
	
	//����a��Ū�i�� 
	map();
	
	int nextrow;
	int nextcol;
	int row;
	int col;
	int dir;
	
 	//while(stack���O�Ū�) 
	while(top > -1 && !found){
		//���ʦ�stack�����x�s����m 
		row = pos[top].row;
		col = pos[top].col;
		dir = pos[top].dir;
		top --;
		
		//while(�q�ثe��m�X�o�٦��i�H���ʪ���m) 
		while(dir < 8 && !found){
			int nextrow = row + move[dir].vert;
			int nextcol = col + move[dir].horiz;
			
			//����X�f 
			if((nextrow == exit_row)&&(nextcol == exit_col)){
				top ++;
				pos[top].row = row;
				pos[top].col = col;
				pos[top].dir = dir;
				found = 1;
			}
			
			//�X�z���ʥB���e�S��L�o�� 
			else if(maze[nextrow][nextcol]==0 && mark[nextrow][nextcol]==0){
				//�x�s�ثe����V�M��m
				//�[�J<row,col,dir>��stack����
				 
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

//Ū�a�� 
void map(){

	
	int i,j;
	
	//��l�ư}�C 
	for(i=0;i<1010;++i){
		for(j=0;j<1010;++j){
			maze[i][j] = 0;
			mark[i][j] = 0;
		}
	}

	
	
	scanf("%d%d",&M,&N);


	//����1����t��_�� 
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
	
	//Ū���a�� 
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


//��X�g�c���| 
void path(){
	
	int k=1;
	int i;
	int j;

	
	//�p�G�����| 
	if(found){
		while(top > -1){
			maze[pos[top].row][pos[top].col] = 666;
			k++;
			top--;
		}
		//�}�l�L�X���| 
		for(i=1;i<M+1;++i){
			for(j=1;j<N+1;++j){
				//�J�f 
				if(i==start_row&&j==start_col){
					printf("s");
				}
				//�X�f 
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
	//�p�G�S�����| 
	else{ 
		printf("No route\n");
		} 
	//�L�X�B�� 
	printf("%d steps\n",k);
	return;
}
