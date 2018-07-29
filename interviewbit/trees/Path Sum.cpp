/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool findtarget(TreeNode *root, int target) {
	if(root == NULL)
		return false;
	if(root->left == NULL && root->right == NULL){
		if(root->val == target)
			return true;
		return false;
	}
	return (findtarget(root->left, target-root->val) ||
				findtarget(root->right, target-root->val));
}

int Solution::hasPathSum(TreeNode* root, int target) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(root == NULL)
		return 0;

	return findtarget(root, target);
}
