/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode *flattenTree(TreeNode *root){
	
	if(root == NULL)
		return NULL;

	if(root->left == NULL && root->right == NULL)
		return root;
	
	TreeNode *lnode = flattenTree(root->left);
	TreeNode *rnode = flattenTree(root->right);

	if(lnode == NULL)
		return root;

	// find the right most node for the lnode
	// and make rnode the right child of that node
	TreeNode *curr = lnode;
	while(curr->right != NULL){
		curr = curr->right;
	}

	curr->right = rnode;
	root->right = lnode;
	root->left = NULL;

	return root;
}

TreeNode* Solution::flatten(TreeNode* root) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(root == NULL)
		return NULL;

	return flattenTree(root);
}