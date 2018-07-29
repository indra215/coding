/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
The structure of a BST node is as follows:
struct Node {
int data;
Node * right, * left;
};
*/
void getCountOfNodeUtil(Node* root, int l, int h, int& count)
{
	if(root == NULL)
		return;
	
	if(root->data > l)
		getCountOfNodeUtil(root->left, l, h, count);
	
	if(root->data >= l && root->data <= h){
		// cout << root->data << "\n";
		count++;
	}
	
	if(root->data < h)
		getCountOfNodeUtil(root->right, l, h, count);
}

int getCountOfNode(Node *root, int l, int h)
{
	int count = 0;
	getCountOfNodeUtil(root, l, h, count);
	return count;
}