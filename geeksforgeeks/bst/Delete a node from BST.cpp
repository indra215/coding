/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* The structure of a BST Node is as follows:
struct Node {
  int data;
  Node * right, * left;
}; */

Node* getMinNode(Node* root)
{
	Node* curr = root;
	while(curr->left != NULL){
		curr = curr->left;
	}
	return curr;
}

Node* deleteNode(Node *root, int x)
{
	if(root == NULL)
		return root;

	if(root->data < x){
		root->right = deleteNode(root->right, x);
	}
	else if(root->data > x){
		root->left = deleteNode(root->left, x);
	}
	else{
		if(root->right == NULL){
			Node* temp = root->left;
			free(root);
			return temp;
		}
		else if(root->left == NULL){
			Node* temp = root->right;
			free(root);
			return temp;
		}
		else{
			Node* minNode = getMinNode(root->right);
			swap(root->data, minNode->data);
			root->right = deleteNode(root->right, minNode->data);
		}
	}
	return root;
}