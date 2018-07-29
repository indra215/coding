/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Complete the function
Node is as follows:
struct node
{
    int data;
    struct node *left, *right;
};
*/
void print(vector<int> v)
{
	for(int i=0;i<v.size();i++){
		cout << v[i] << " ";
	}
	cout << "\n";
}

void getInorder(struct node* root, vector<int>& inorder)
{
	if(root == NULL)
		return;
	getInorder(root->left, inorder);
	inorder.push_back(root->data);
	getInorder(root->right, inorder);
}

/*struct node* freeTree(struct node*& root)
{
	if(root == NULL)
		return root;
	struct node *l = freeTree(root->left);
	struct node *r = freeTree(root->right);
	free(root);
	return NULL;
}*/

struct node* createNode(int v)
{
	struct node* n = (struct node*)malloc(sizeof(struct node*));
	n->data = v;
	n->left = NULL;
	n->right = NULL;
	return n;
}

struct node* constructBSTUtil(vector<int>& inorder, int s, int e)
{
	if(s > e)
		return NULL;
	int mid = s + (e-s)/2;
	struct node* root = createNode(inorder[mid]);
	root->left = constructBSTUtil(inorder, s, mid-1);
	root->right = constructBSTUtil(inorder, mid+1, e);
	return root;
}

struct node* constructBST(vector<int>& inorder)
{
	int n = inorder.size();
	struct node* root = constructBSTUtil(inorder, 0, n-1);
	return root;
}

struct node *correctBST( struct node* root )
{
	if(root == NULL)
		return root;

	vector<int> inorder;
	getInorder(root, inorder);

	bool isfirst = false, islast = false;
	int first, middle, last;
	for(int i=1;i<inorder.size();i++){
		if(inorder[i] < inorder[i-1]){
			if(!isfirst){
				first = i-1;
				middle = i;
				isfirst = true;
			}else if(!islast){
				last = i;
				islast = true;
			}
		}
	}
	if(islast){
		swap(inorder[first], inorder[last]);
	}else{
		swap(inorder[first], inorder[middle]);
	}
	// print(inorder);

	// freeTree(root);
	struct node* tree = constructBST(inorder);
	/*vector<int> ino;
	getInorder(tree,ino);
	print(ino);*/
	
	return tree;
}