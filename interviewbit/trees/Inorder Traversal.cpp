/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* root) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if(root == NULL)
		return vector<int>();

	stack<TreeNode*> nodes;
	TreeNode *curr = root;
	bool isfinish = true;
	vector<int> inorder;
	while(isfinish){
		while(curr){
			nodes.push(curr);
			curr = curr->left;
		}
		if(!nodes.empty()){
			TreeNode *n = nodes.top();
			nodes.pop();
			inorder.push_back(n->val);
			curr = curr->right;
		}
		if(!curr && nodes.empty())
			isfinish = false;
	}
	return inorder;
}