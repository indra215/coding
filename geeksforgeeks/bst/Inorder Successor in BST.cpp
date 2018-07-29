/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The structure of Node
struct Node {
int data;
Node * right, * left;
};*/
/* The below function should return the node which is 
inorder successor of given node x. */

void inOrderSuccessorUtil(Node* root, Node* x, Node*& succ)
{
	if(root == NULL)
		return;

	if(root->data == x->data){
		if(root->right != NULL){
			Node* curr = root->right;
			while(curr->left != NULL)
				curr = curr->left;
			succ = curr;
		}
	}
	else if(root->data < x->data){
		inOrderSuccessorUtil(root->right, x, succ);
	}else{
		succ = root;
		inOrderSuccessorUtil(root->left, x, succ);
	}
}

Node * inOrderSuccessor(Node *root, Node *x)
{
	if(root == NULL)
		return root;

	Node* succ = NULL;
	inOrderSuccessorUtil(root, x, succ);
	return succ;
}