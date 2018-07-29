/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int heightofTree(TreeNode *root) {
	if(root == NULL)
		return 0;

	return (1 + max(heightofTree(root->left), heightofTree(root->right)));
}

void printLevel(TreeNode *root, int level, bool ltr, vector<int>& level_val) {
	if(root == NULL)
		return;
	if(level == 1){
		level_val.push_back(root->val);
	}
	else{
		if(ltr){
			printLevel(root->left, level-1, ltr, level_val);
			printLevel(root->right, level-1, ltr, level_val);
		}else{
			printLevel(root->right, level-1, ltr, level_val);
			printLevel(root->left, level-1, ltr, level_val);
		}
	}
	return;
}

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* root) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(root == NULL)
		return vector<vector<int>>();

	int height = heightofTree(root);
	vector<vector<int>> spiralTree;
	bool ltr = true;
	for(int i=1;i<=height;i++){
		vector<int> level_val;
		printLevel(root, i, ltr, level_val);
		spiralTree.push_back(level_val);
		ltr = !ltr;
	}

	return spiralTree;
}