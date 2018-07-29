/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::hasPathSum(TreeNode* root, int target) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if(root == NULL)
		return 0;

	queue<pair<TreeNode*,int>> nodes;
	nodes.push(make_pair(root, target));
	while(!nodes.empty()){
		pair<TreeNode*,int> n = nodes.front();
		nodes.pop();
		TreeNode *t = n.first;
		if(t->left == NULL && t->right == NULL){
			if(t->val == n.second)
				return 1;
		}
		if(t->left){
			nodes.push(make_pair(t->left, n.second-t->val));
		}
		if(t->right){
			nodes.push(make_pair(t->right, n.second-t->val));
		}
	}
	return 0;
}