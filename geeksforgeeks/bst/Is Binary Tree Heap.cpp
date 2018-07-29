/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
 A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
/*You are required to complete this method */
int countNodes(Node* root)
{
	if(root == NULL)
		return 0;
	return (1 + countNodes(root->left) + countNodes(root->right));
}

bool isCompleteUtil(Node* root, int index, int no_nodes)
{
	if(root == NULL)
		return true;
	if(index >= no_nodes)
		return false;
	return (isCompleteUtil(root->left, 2*index+1, no_nodes) && 
				isCompleteUtil(root->right, 2*index+2, no_nodes));
}

bool isComplete(Node* root, int no_nodes)
{
	if(root == NULL)
		return true;
	return isCompleteUtil(root, 0, no_nodes);
}

bool checkMaxHeap(Node* root)
{
	if(root->left == NULL && root->right == NULL)
		return true;
	if(root->right == NULL)
		return (root->data >= root->left->data);
	if((root->data >= root->left->data) && 
			(root->data >= root->right->data))
		return (checkMaxHeap(root->left) && checkMaxHeap(root->right));
	return false;
}

bool isHeap(Node * tree)
{
	int no_nodes = countNodes(tree);
	bool iscomp = isComplete(tree, no_nodes);
	bool ismaxheap = checkMaxHeap(tree);
	if(iscomp && ismaxheap)
		return true;
	return false;
}