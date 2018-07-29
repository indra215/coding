/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* root) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(root == NULL)
		return vector<vector<int>>();

	vector<vector<int>> spiralTree;
	stack<TreeNode*> nodes_ltr, nodes_rtl;

	nodes_ltr.push(root);
	vector<int> level_val;
	while(!nodes_ltr.empty() || !nodes_rtl.empty()){
		// remove nodes from stack1 and fill stack2
		level_val.clear();
		while(!nodes_ltr.empty()){
			TreeNode *n = nodes_ltr.top();
			nodes_ltr.pop();
			level_val.push_back(n->val);

			if(n->left)
				nodes_rtl.push(n->left);
			if(n->right)
				nodes_rtl.push(n->right);
		}
		if(!level_val.empty())
			spiralTree.push_back(level_val);

		level_val.clear();
		while(!nodes_rtl.empty()){
			TreeNode *n = nodes_rtl.top();
			nodes_rtl.pop();
			level_val.push_back(n->val);

			if(n->right)
				nodes_ltr.push(n->right);
			if(n->left)
				nodes_ltr.push(n->left);
		}
		if(!level_val.empty())
			spiralTree.push_back(level_val);
	}

	return spiralTree;
}