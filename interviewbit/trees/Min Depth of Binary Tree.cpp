/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* root) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if(root == NULL)
		return 0;

	queue<pair<TreeNode*,int>> nodes;
	nodes.push(make_pair(root,0));
	while(!nodes.empty()){
		pair<TreeNode*,int> n = nodes.front();
		nodes.pop();
		TreeNode *t = n.first;
		if(t->left == NULL && t->right == NULL){
			return (n.second+1);
		}
		if(t->left){
			nodes.push(make_pair(t->left, n.second+1));
		}
		if(t->right){
			nodes.push(make_pair(t->right, n.second+1));
		}
	}
}