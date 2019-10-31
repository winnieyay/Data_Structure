#include<stdio.h>
#include<stdlib.h>

int board[8][8];

int i;
int j;

int x;

int l;
int k;

int m;
int number;

int assume_i;
int assume_j;
int exit_i;
int exit_j;
int npos;
int min;
int assume_min;

static int kmove1[8]={-2,-1,1,2,2,1,-1,-2};
static int kmove2[8]={1,2,2,1,-1,-2,-2,-1};

void move(int m);


int main(){
    for(x=1;x<9;++x){
        printf("%d:\n",x);
        move(x);
        printf("\n");
    }
	return 0;
}



void move(int m){
	
    //��l�ư}�C 
    for(i=0;i<8;++i){ 
		for(j=0;j<8;++j){		
		board[i][j]=0;
		}
	} 
	
	if(m == 1){
        printf("1\n");
        return;
    }
    else{
	
    //�]�w�Ʀr1�}�l����m       
    i=0;
	j=0; 
    board[0][0]=1;
    
    
    for(number=2; number<=m*m;++number){
    	
		l=1;
		npos=0;
		min=0;
		
        int next_i[8]={0};
        int next_j[8]={0};
        int exit[8]={0};
		
		
		for(k=0;k<8;++k){
			assume_i = i + kmove1[k];
			assume_j = j + kmove2[k];
            //�ˬd�O�_�W�L��ɡA�H�άO�_�w�Q��Ʀr 
			if((assume_i>=0) && (assume_i<=m-1) && (assume_j>=0) && (assume_j<=m-1) && (board[assume_i][assume_j]==0)){
				next_i[l] = assume_i;
                next_j[l] = assume_j;
                npos++;
                l++;
            }
        }
        
        //�Y�U�ӥi���m���ƶq�u��1�A���������u 
        if(npos == 1){
            i=next_i[1];
            j=next_j[1];
            board[i][j] = number;
        } 
        
        //�Y�U�ӥi���m���ƶq��0�A�L�� 
        else if(npos == 0){
			printf("no solution.\n");
			break;
		}
		 
        //�Y1<l<npos�A�h�]exit[l]���U�Ӧ�m����D���X�f�� 
        else{
            for(k=0;k<8;++k){
                for(l=1;l<=npos;++l){
                    exit_i=next_i[l]+kmove1[k];
                    exit_j=next_j[l]+kmove2[k];
                    //�ˬd�O�_�W�L��ɡA�H�άO�_���Q��Ʀr 
                    if((exit_i>=0) && (exit_i<=m-1) && (exit_j>=0) && (exit_j<=m-1) && (board[exit_i][exit_j]==0)){
                        exit[l] ++;    //���߫h�X�f�ƼW�[ 
                    }
                }
            }
               
            assume_min=10;
            
            //���̤֥X�f�Ƭ��U�@���D��m 
			for(l=1;l<=npos;++l){
                if(exit[l]<assume_min){
                    assume_min=exit[l];
                    min=l;
                }
            }
            
            i = next_i[min];
            j = next_j[min];
            board[i][j] = number;
            
        }
        
        	//�L�X�}�C    
            if(number == m*m){
                for(i=0;i<m;++i){
                    for(j=0;j<m;++j){
                        printf("%3d",board[i][j]);
                    }
                    printf("\n");
                }
            }
    	}
	}
}

