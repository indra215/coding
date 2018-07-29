/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* root) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if(root == NULL)
		return vector<int>();

	vector<int> preorder;
	stack<TreeNode*> nodes;
	nodes.push(root);
	while(!nodes.empty()){
		TreeNode *n = nodes.top();
		nodes.pop();
		preorder.push_back(n->val);
		if(n->right)
			nodes.push(n->right);
		if(n->left)
			nodes.push(n->left);
	}
	return preorder;
}