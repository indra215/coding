/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* The structure of Node
struct Node{
    int data;
    Node *left,*right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
}; */
/*You are required to complete below method */
struct TreeNode
{
	int val;
	int size;
	TreeNode *left, *right;
	TreeNode(int v) : val(v), size(1), left(NULL), right(NULL) {}
};

void print(vector<int>& v)
{
	for(int i=0;i<v.size();i++)
		cout << v[i] << " ";
	cout << "\n";
}

void getInorder(Node* root, vector<int>& inorder)
{
	if(root == NULL)
		return;
	getInorder(root->left, inorder);
	inorder.push_back(root->data);
	getInorder(root->right, inorder);
}

int getSize(TreeNode* n)
{
	if(n == NULL)
		return 0;
	return n->size;
}

TreeNode* insertBST(TreeNode* tree, int key, int& cnt)
{
	if(tree == NULL){
		TreeNode *n = new TreeNode(key);
		return n;
	}

	if(tree->val > key){
		tree->left = insertBST(tree->left, key, cnt);
	}
	else if(tree->val < key){
		tree->right = insertBST(tree->right, key, cnt);
		cnt += (getSize(tree->left) + 1);
	}

	tree->size = getSize(tree->left) + getSize(tree->right) + 1;

	return tree;
}

int pairsViolatingBST(Node *root, int n)
{
	if(n == 0)
		return 0;
	vector<int> inorder;
	getInorder(root, inorder);
	// print(inorder);

	vector<int> count(n+1, 0);
	int pairs = 0;
	TreeNode *tree = NULL;
	for(int i=n;i>=0;i--){
		tree = insertBST(tree, inorder[i], count[i]);
		// cout << inorder[i] << "\t" << count[i] << "\n";
		pairs += count[i];
	}

	return pairs;
}