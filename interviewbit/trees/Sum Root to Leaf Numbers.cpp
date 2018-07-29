/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void computePathSum(TreeNode *root, int K, int *sum){
	K = ((K*10)%1003 + root->val)%1003;
	if(root->left == NULL && root->right == NULL){
		*sum = (*sum + K)%1003;
		return;
	}
	if(root->left)
		computePathSum(root->left, K, sum);
	if(root->right)
		computePathSum(root->right, K, sum);
}

int Solution::sumNumbers(TreeNode* root) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(root == NULL)
		return 0;
	int sum;
	sum = computePathSum(root, 0);
	return sum;
}