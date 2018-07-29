/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
void kthAncestorUtil(Node *root, int k, int node, vector<int>& ancs)
{
	if(root == NULL)
		return;

	if(root->data == node){
		int n = ancs.size();
		cout << "Yo" << " " << n << "\n";
		if(n < k)
			cout << -1;
		else{
			cout << "Yo1" << " " << n-k << "\n";
			cout << ancs[n-k];
		}
		return;
	}

	ancs.push_back(root->data);
	kthAncestorUtil(root->left, k, node, ancs);
	kthAncestorUtil(root->right, k, node, ancs);
	ancs.pop_back();
}

int kthAncestor(Node *root, int k, int node)
{
	if(root == NULL)
		return -1;

	vector<int> ancs;
	kthAncestorUtil(root, k, node, ancs);
}
