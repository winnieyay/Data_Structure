#include<stdio.h>
#include<stdlib.h>

int nnode=0;
int h=0;


typedef struct node{
	struct node* parent;
	struct node* left;
	struct node* right;
	int number;
}node;
node *root;

struct node* insert(int value,node *tmpparent);
struct node* search(node* root, int num);
struct node* Level(node* root, int level);
struct node* del(node* root);
struct node* sp1(node* search1,node* root);
struct node* sp2(node* search2,node* root);

int main(){
	
	int i,n;
    int num[100]={0};
	
	
	for(i=0;i<100;++i){
		scanf("%d,",&num[i]);
		h++;
		if(num[i]==-1){
			n=i;
			break;
		}	
	} 
	
	root = (node*) malloc(sizeof(node));
	root->number = num[0];
	root->left = root->right=NULL;	

	for(i=1;i<n;i++){
		insert(num[i],root);
	}
	
	
	printf("Create Binary search tree\n");
	
	nnode=0;
    for (i=1; i<=h; i++)
    {
        Level(root, i);
        printf("\n");
        if(nnode==h-1) 
		break;
    }
    	
	char c;
	int x;
	int j;
	for(i=0;i<100;++i){
	
		printf("Delete element?(Y/N):");
		c=getchar();
		c=getchar();
	
		switch(c){
		case 'Y':
			printf("Choice element:");
			scanf("%d",&x);
			search(root,x);
			nnode=0;
			
    		for (j=1; j<=h; j++){
        		Level(root,j);
        		printf("\n");
        		if(nnode==h-1){
        			break;	
				}
    		}
			break;
		case 'N':
			printf("Bye bye!");
			return 0;
		default:
			printf("Error!\n");
		}
	}

	return 0;
} 
 
struct node* insert(int value,node *tmpparent){
	
	node *newnode = (node*) malloc(sizeof(node));
	
	//比較value值和parent值
	//狀況1:value較大 
	//如果右子樹是空白的，放進右子樹 
	if(tmpparent->number < value){ 
		if(tmpparent->right==NULL){
			newnode->parent = tmpparent;
			newnode->left = newnode->right = NULL;
			newnode->number = value;		
			tmpparent->right = newnode;
		}
		//不是空白則繼續找右邊
		else if	(tmpparent->right!=NULL){
			insert(value,tmpparent->right);
		}
	}
	//狀況2:value較小 
	//若左子樹是空白的，放進左子樹
	else{
		if(tmpparent->left==NULL){
			newnode->parent = tmpparent;
			newnode->number = value;
			newnode->right = newnode->left = NULL;		
			tmpparent->left = newnode;
		}
		//不是空白則繼續找左邊
		else if(tmpparent->left!=NULL){
			insert(value,tmpparent->left);
		}
	}
	 	
}

//尋找 
struct node* search(node* root, int num){
	
	if(root->number==num) {
		h--;
		printf("Binary search tree\n");	
		del(root);
	}
	//比較num值，決定往左找或往右找
	//往左找 
	else if((root->number > num)&&(root->left!=NULL)){
		search(root->left,num);
	}
	//往右找 
	else if((root->number<num)&&(root->right!=NULL)){
		search(root->right,num);
	}
	//找不到 
	else printf("%d is not in the tree\n",num);
}

//利用level印出 
struct node* Level(node* root, int level){
	
    if (root == NULL)
        printf("  *  ");
    else{
		if(level == 1){
        	printf(" %2d  ", root->number);    	
        	nnode++;
    	}
    	else if (level > 1){
        	Level(root->left, level-1);
        	Level(root->right, level-1);
    	} 	
	}
}

struct node* del(node* root){
	
	//第一種情況:右子樹空白 
	if(root->left!=NULL && root->right==NULL){
		//爸爸大於小孩 
		if(((root->parent)->number) > root->number){
			((root->parent)->left)=root->left;
			((root->left)->parent)=root->parent;
		}
		//爸爸小於小孩 
		else if(((root->parent)->number) < root->number){
			((root->parent)->right)=root->left;
			((root->left)->parent)=root->parent;
		} 
		//沒有爸爸 
		else if(root->parent==NULL){
			root->number=(root->left)->number;
			root->left=(root->left)->left;
		} 
	}
	//第二種情況:左子樹空白
	else if(root->left==NULL && root->right!=NULL){
		
		//爸爸大於小孩 
		if(((root->parent)->number) > root->number){
			((root->parent)->left)=root->right;
			((root->right)->parent)=root->parent;
		}
		//爸爸小於小孩 
		else if(((root->parent)->number) < root->number){
			((root->parent)->right)=root->right;
			((root->right)->parent)=root->parent;
		}
		//沒有爸爸 
		else if(root->parent==NULL){
			root->number=(root->right)->number;
			root->right=(root->right)->right;
		}
	}
	//第三種情況:左右子樹都是空白的
	else if((root->left==NULL)&& (root->right ==NULL)){
		//爸爸大於小孩 
		if(root->number<((root->parent)->number)){
			((root->parent)->left)=NULL;
		} 
		//爸爸小於小孩 
		else{
			((root->parent)->right)=NULL;				
		}
	}
	//第四種情況:左右子樹皆非空白 
	else{
		/*
				root
				 /\
				1  2
			   /\ /\
			  3 *4 5		
		*/ 
		if(root->left->right==NULL){
			//如果3為NULL 
			if(root->left->left==NULL) {
				//用他的左子樹取代自己 
				root->number = root->left->number;
				(root->left->parent)->left = NULL;
			}
			else{
				
				if((root->right)->left==NULL && (root->right)->right!=NULL){
				/*
				    root
					/\
				   1 2
				  /\/\
				 3 **4
				
				        的情況 
				
				*/
						//用2來取代root 
						root->number = (root->right)->number;
						root->right = root;				
						root->right = (root->right)->right;
				}
			
				else{
					sp2(root->right,root);
				}
			}
		}
		else{ 
			sp1(root->left,root);
		}
	}
}

struct node* sp1(node* search1,node* root){
	if(search1->right==NULL){
		/*
			root
			 /\
			1  2
		   /\ /\
		  3 *4 5
		 			
		*/ 
		root->number = search1->number;
		if(search1->left==NULL){
			/*
				root
				/\
			   1  2
			  /\ /\
			 * *4 5
			
			*/ 
			(search1->parent)->right = NULL;
		}
		else{
			(search1->left)->parent = search1->parent;
			(search1->parent)->right = search1->left;
		}
	}
	//找不到NULL就繼續往下找 
	else {	
		sp1(search1->right,root);
	}	
}

struct node* sp2(node* search2,node* root){
	if(search2->left==NULL){
		/*
			root
			 /\
			1 2
		   /\ /\
		  3 4* 5	
		
		*/ 
		root->number=search2->number;
		if(search2->right==NULL){
			
		/*
			root
			 /\
			1 2
		   /\ /\
		  3 4* * 
		
		*/ 
			(search2->parent)->left = NULL;
		}
		else {
			(search2->right)->parent = search2->parent;
			(search2->parent)->left = search2->right;
		}
	}
	//找不到NULL就繼續往下找
	else{
		sp2(search2->left,root);
	}
}



