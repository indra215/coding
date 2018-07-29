/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Tree node structure  used in the program
 struct Node
 {
     int data;
     struct Node* left, *right;
};*/
/*You are required to complete this method */
struct Info{
	int size;
	bool isBST;
	int min;
	int max;
	Info(int s, bool is, int mn, int mx) : size(s), isBST(is), min(mn), max(mx) {}
};

bool isleaf(Node* root)
{
	if(root->left == NULL && root->right == NULL)
		return true;
	return false;	
}

void largestBstUtil(Node* root)
{
	if(root == NULL){
		Info n(0, true, INT_MIN, INT_MAX);
	}

	Info left = largestBstUtil(root->left);
	Info right = largestBstUtil(root->right);
	if(left.isBST && right.isBST && 
			root->data > left.max &&
			root->data < right.min){
		Info n(left.size+right.size+1, true, )
	}
}

int largestBst(Node *root)
{
	if(root == NULL)
		return 0;
	
	largestBstUtil(root);
}