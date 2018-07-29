/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode *makeTree(const vector<int> &A, int low, int high) {
	if(low > high)
		return NULL;
	
	int mid = low + (high-low)/2;
	TreeNode *root = new TreeNode(A[mid]);
	root->left = makeTree(A, low, mid-1);
	root->right = makeTree(A, mid+1, high);
	return root;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	
	if(A.empty())
		return NULL;
	return makeTree(A, 0, A.size()-1);
}