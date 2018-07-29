/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int heightTree(TreeNode *root) {
	if(root == NULL)
		return 0;
	return (1 + max(heightTree(root->left), heightTree(root->right)));
}

int findBalanced(TreeNode *root) {
	if(root == NULL)
		return 1;
	int lheight = heightTree(root->left);
	int rheight = heightTree(root->right);
	if(abs(lheight - rheight) > 1)
		return 0;
	return (findBalanced(root->left) && findBalanced(root->right));
}

int Solution::isBalanced(TreeNode* root) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if(root == NULL)
		return 1;
	return findBalanced(root);
}