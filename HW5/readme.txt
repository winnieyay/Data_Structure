�o�ӵ{������x�����a��O�n�̧�level�ӱƦC��X���tree�C
�쥻�ڹ��ե�queue����k�A�o�@�����ѡC
�W���d�߸�Ƥ���o�{���H���ѧQ��level�ƧǪ���k�A�]���̫�ڱĥγo�Ӥ�k�C
�Ӧb�R���������A�]���Q���즳�Ĳv����k�A�u�n��C�ӱ��󳣦C�X�ӵw�FQWQ

�{���̭��]�t

(1)��Jnew node
struct node* insert(int value,node *tmpparent);

(2)��M�O�_����node
struct node* search(node* root, int num);

(3)�̷�level�ƦC�ӿ�Xtree
struct node* Level(node* root, int level);

(4)�R��node
struct node* del(node* root);
struct node* sp1(node* search1,node* root);
struct node* sp2(node* search2,node* root);






<Time complexity>


The depth of tree:h

deletion:O(h)
search:O(h)
Preorder traversal:O(n)

Answer: O(n+h)