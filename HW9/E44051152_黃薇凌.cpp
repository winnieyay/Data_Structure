#include<stdio.h>
#include<stdlib.h>
#define MAX 100 

typedef struct node *nodepointer;

typedef struct node{
	int vertex;
	nodepointer link;
	int dur;
}node;

node* num;

typedef struct{
	int count;
	nodepointer link;
}hdnodes;

hdnodes graph[MAX];

void topsort(hdnodes graph[],int n,int tmp[][MAX],int earliest[],int latest[],int m);
void topsortback(hdnodes graph[],int n,int tmp[][MAX],int earliest[],int latest[],int m);
void activity(hdnodes graph[],int n,int tmp[][MAX],int earliest[],int latest[],int m,int connect[][MAX],int time[][MAX],int e[],int t[],int s[]);


int main(){
	
	int tmp[100][100];
	int connect[100][100];
	int time[100][100];
	int i,j;
	int n,all;
	int earliest[100]={0};
	int latest[100]={0};
	int e[100]={0};
	int t[100]={0};
	int s[100]={0};
	

	
	for(i=0;i<100;++i){
		for(j=0;j<100;j++){
			tmp[i][j]=0;
			connect[i][j]=0;
			time[i][j]=0;
		}
	}
	int totalnum;
	
	scanf("%d",&n);
	printf("\n");
	
	for(i=0;i<n;++i){
		for(j=0;j<4;j++){
			scanf("%d",&tmp[i][j]);
		}
	}
	
	int x,y,z,c;
	for(i=0;i<n;++i){
		c=tmp[i][3];
		x=tmp[i][1];
		y=tmp[i][2];
		z=tmp[i][0];
		connect[x][y]=z;
		time[x][y]=c;
	}
	
	
	for(i=0;i<n;++i){
		
			if(tmp[i][2] >= tmp[i][1])
			 totalnum=tmp[i][2];
			else
				totalnum=tmp[i][1];
	}
	
	topsort(graph,n,tmp,earliest,latest,totalnum);
	topsortback(graph,n,tmp,earliest,latest,totalnum);
	 
	printf("(a)\n     ee   le\n");
	
	for(i=0;i<totalnum+1;i++){
		
		printf("%2d   %2d   %2d\n",i,earliest[i],latest[i]);
	}
	printf("\n");
	activity(graph,n,tmp,earliest,latest,totalnum,connect,time,e,t,s);
	
	printf("(b)\n       e     l     s    c\n");
	for(i=1;i<=n;i++){
		printf("%2d    %2d    %2d    %2d    ",i,e[i],t[i],s[i]);
		if(s[i]==0) printf("Y");
		else printf("N");
		printf("\n");
	}
	
	
}




void topsort(hdnodes graph[],int n,int tmp[][MAX],int earliest[],int latest[],int m){
	
	int i,j,k,top,x,y;
	nodepointer ptr;
	nodepointer ptr1;
	nodepointer ptr2;
	int start,end,mid;
	
	top=-1;
	for(i=0;i<n;i++){
		graph[i].count=0;
	}
	
	
	for(i=0;i<n;i++){
		
		num = (node*)malloc(sizeof(node));
		
		start=tmp[i][1];
		end=tmp[i][2];
		mid=tmp[i][3];
		
		graph[end].count++;
				
		if(graph[start].link==NULL){
			graph[start].link=num;
			num->vertex=end;
			num->dur=mid;
			num->link=NULL;
		}		
		else{
			if(graph[start].link->link==NULL){
				ptr1=graph[start].link->link;
				graph[start].link->link=num;
				num->vertex=end;
				num->dur=mid;
				num->link=ptr1;
			}
			else{
				ptr1=graph[start].link->link->link;
				graph[start].link->link->link=num;
				num->vertex=end;
				num->dur=mid;
				num->link=ptr1;
			}
			
		}
	}
	for(i=0;i<m+1;i++){
		if(!graph[i].count){
			graph[i].count=top;
			top=i;
		}
	}
	
	for(i=0;i<m+1;i++){
		if(top==-1){
			printf("\n Network has a cycle. Sort terminated.\n");
			break;
		}
		else{
		j=top;
		//stack pop out 
		//printf("\n %d-> \n",j);
		top=graph[top].count;
			
			for(ptr=graph[j].link;ptr;ptr=ptr->link ){
				 
				k=ptr->vertex;
				
				if(earliest[k]<earliest[j]+ptr->dur)
					earliest[k]=earliest[j]+ptr->dur;
						
				graph[k].count--;
				if(!graph[k].count ){
					graph[k].count=top;
					top=k;
				}
			}
		}
	}
}

void topsortback(hdnodes graph[],int n,int tmp[][MAX],int earliest[],int latest[],int m){
	nodepointer ptr;
	int j,k;
	int i;
	for(i=m; i>=0; i--){
		if(i==m){
			latest[i]=earliest[i];
		}
		for(ptr=graph[i].link;ptr;ptr=ptr->link ){ 
			k=ptr->vertex;
			if(latest[i] > latest[k] - ptr->dur || latest[i]==0)
				latest[i] = latest[k] - ptr->dur; 	
		}
	}	
}

void activity(hdnodes graph[],int n,int tmp[][MAX],int earliest[],int latest[],int m,int connect[][MAX],int time[][MAX],int e[],int t[],int s[]){
	int i,x,y;
	for(i=1;i<=n;i++){
		for(x=0;x<=m;x++){
			for(y=0;y<=m;y++){
				if(connect[x][y]==i){
					e[i]=earliest[x];
					t[i]=latest[y]-time[x][y];
					s[i]=t[i]-e[i];	
				}
			}
		}
	}
}

