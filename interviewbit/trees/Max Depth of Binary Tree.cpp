/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int depth(TreeNode *root) {
	if(root == NULL)
		return 0;
	return 1 + max(depth(root->left), depth(root->right));
}

int Solution::maxDepth(TreeNode* root) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if(root == NULL)
		return 0;
	return depth(root);
}