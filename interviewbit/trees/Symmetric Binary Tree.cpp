/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int isMirror(TreeNode *root1, TreeNode *root2) {
	if(root1 == NULL)
		return (root2 == NULL) ? 1 : 0;
	if(root2 == NULL)
		return (root1 == NULL) ? 1 : 0;
	if(root1->val != root2->val)
		return 0;
	return (isMirror(root1->left, root2->right) && 
				isMirror(root1->right, root2->left));
}

int Solution::isSymmetric(TreeNode* root) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if(root == NULL)
		return 1;
	return isMirror(root->left, root->right);
}