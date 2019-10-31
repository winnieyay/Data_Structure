這個程式比較困難的地方是要依序level來排列輸出整個tree。
原本我嘗試用queue的方法，卻一直失敗。
上網查詢資料之後發現有人提供利用level排序的方法，因此最後我採用這個方法。
而在刪除的部分，因為想不到有效率的方法，只好把每個條件都列出來硬幹QWQ

程式裡面包含

(1)放入new node
struct node* insert(int value,node *tmpparent);

(2)找尋是否有此node
struct node* search(node* root, int num);

(3)依照level排列來輸出tree
struct node* Level(node* root, int level);

(4)刪除node
struct node* del(node* root);
struct node* sp1(node* search1,node* root);
struct node* sp2(node* search2,node* root);






<Time complexity>


The depth of tree:h

deletion:O(h)
search:O(h)
Preorder traversal:O(n)

Answer: O(n+h)