/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */
void printBoundaryLeft(Node* root)
{
	if(root){
		if(root->left){
			cout << root->data << " ";
			printBoundaryLeft(root->left);
		}else if(root->right){
			cout << root->data << " ";
			printBoundaryLeft(root->right);
		}
	}
}

void printLeaves(Node* root)
{
	if(root == NULL)
		return;
	
	printLeaves(root->left);
	printLeaves(root->right);
	if(root->left == NULL && root->right == NULL)
		cout << root->data << " ";
}

void printBoundaryRight(Node* root)
{
	if(root){
		if(root->right){
			printBoundaryRight(root->right);
			cout << root->data << " ";
		}else if(root->left){
			printBoundaryRight(root->left);
			cout << root->data << " ";
		}
	}
}

void printBoundary(Node *root)
{
	if(root == NULL)
		return;

	if(root){
		cout << root->data << " ";
		printBoundaryLeft(root->left);

		printLeaves(root->left);
		printLeaves(root->right);

		printBoundaryRight(root->right);
	}
}