 /*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
	if(root == NULL)
		return;

	if(root->key == key){
		if(root->left != NULL){
			Node* curr = root->left;
			while(curr->right != NULL){
				curr = curr->right;
			}
			pre = curr;
		}
		if(root->right != NULL){
			Node* curr = root->right;
			while(curr->left != NULL){
				curr = curr->left;
			}
			suc = curr;
		}
		return;
	}

	if(root->key > key){
		suc = root;
		findPreSuc(root->left, pre, suc, key);
	}
	else{
		pre = root;
		findPreSuc(root->right, pre, suc, key);
	}
}