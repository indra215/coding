/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


//User function Template for C++
/*
Structure of the Node of the BST is as
struct Node {
	int key;
	Node* left, *right;
};
*/
void findMaxforNUtil(Node* root, int N, int& min_diff, int& min_key)
{
	if(root == NULL)
		return;
	
	if(root->key == N){
		min_key = root->key;
		return;
	}
	
	if(min_diff > abs(root->key - N)){
		min_diff = abs(root->key - N);
		min_key = root->key;
	}
	
	if(root->key < N)
		findMaxforNUtil(root->right, N, min_diff, min_key);
	else if(root->key > N)
		findMaxforNUtil(root->left, N, min_diff, min_key);
}

int findMaxforN(Node* root, int N)
{
	int min_diff = 0, min_key = -1;
	findMaxforNUtil(root, N, min_diff, min_key);
	return min_key;
}