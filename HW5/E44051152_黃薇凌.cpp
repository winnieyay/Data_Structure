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
	
	//���value�ȩMparent��
	//���p1:value���j 
	//�p�G�k�l��O�ťժ��A��i�k�l�� 
	if(tmpparent->number < value){ 
		if(tmpparent->right==NULL){
			newnode->parent = tmpparent;
			newnode->left = newnode->right = NULL;
			newnode->number = value;		
			tmpparent->right = newnode;
		}
		//���O�ťիh�~���k��
		else if	(tmpparent->right!=NULL){
			insert(value,tmpparent->right);
		}
	}
	//���p2:value���p 
	//�Y���l��O�ťժ��A��i���l��
	else{
		if(tmpparent->left==NULL){
			newnode->parent = tmpparent;
			newnode->number = value;
			newnode->right = newnode->left = NULL;		
			tmpparent->left = newnode;
		}
		//���O�ťիh�~��䥪��
		else if(tmpparent->left!=NULL){
			insert(value,tmpparent->left);
		}
	}
	 	
}

//�M�� 
struct node* search(node* root, int num){
	
	if(root->number==num) {
		h--;
		printf("Binary search tree\n");	
		del(root);
	}
	//���num�ȡA�M�w������Ω��k��
	//������ 
	else if((root->number > num)&&(root->left!=NULL)){
		search(root->left,num);
	}
	//���k�� 
	else if((root->number<num)&&(root->right!=NULL)){
		search(root->right,num);
	}
	//�䤣�� 
	else printf("%d is not in the tree\n",num);
}

//�Q��level�L�X 
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
	
	//�Ĥ@�ر��p:�k�l��ť� 
	if(root->left!=NULL && root->right==NULL){
		//�����j��p�� 
		if(((root->parent)->number) > root->number){
			((root->parent)->left)=root->left;
			((root->left)->parent)=root->parent;
		}
		//�����p��p�� 
		else if(((root->parent)->number) < root->number){
			((root->parent)->right)=root->left;
			((root->left)->parent)=root->parent;
		} 
		//�S������ 
		else if(root->parent==NULL){
			root->number=(root->left)->number;
			root->left=(root->left)->left;
		} 
	}
	//�ĤG�ر��p:���l��ť�
	else if(root->left==NULL && root->right!=NULL){
		
		//�����j��p�� 
		if(((root->parent)->number) > root->number){
			((root->parent)->left)=root->right;
			((root->right)->parent)=root->parent;
		}
		//�����p��p�� 
		else if(((root->parent)->number) < root->number){
			((root->parent)->right)=root->right;
			((root->right)->parent)=root->parent;
		}
		//�S������ 
		else if(root->parent==NULL){
			root->number=(root->right)->number;
			root->right=(root->right)->right;
		}
	}
	//�ĤT�ر��p:���k�l�𳣬O�ťժ�
	else if((root->left==NULL)&& (root->right ==NULL)){
		//�����j��p�� 
		if(root->number<((root->parent)->number)){
			((root->parent)->left)=NULL;
		} 
		//�����p��p�� 
		else{
			((root->parent)->right)=NULL;				
		}
	}
	//�ĥ|�ر��p:���k�l��ҫD�ť� 
	else{
		/*
				root
				 /\
				1  2
			   /\ /\
			  3 *4 5		
		*/ 
		if(root->left->right==NULL){
			//�p�G3��NULL 
			if(root->left->left==NULL) {
				//�ΥL�����l����N�ۤv 
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
				
				        �����p 
				
				*/
						//��2�Ө��Nroot 
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
	//�䤣��NULL�N�~�򩹤U�� 
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
	//�䤣��NULL�N�~�򩹤U��
	else{
		sp2(search2->left,root);
	}
}



