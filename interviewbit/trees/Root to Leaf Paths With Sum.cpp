/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void computePaths(TreeNode *root, int sum, vector<int> &path,
									vector<vector<int>> &paths){
	if(root == NULL)
		return;
	if(root->left == NULL && root->right == NULL){
		if(root->val == sum){
			path.push_back(root->val);
			paths.push_back(path);
			path.pop_back();
		}
		return;
	}
	path.push_back(root->val);
	if(root->left)
		computePaths(root->left, sum-root->val, path, paths);
	if(root->right)
		computePaths(root->right, sum-root->val, path, paths);
	path.pop_back();
}

vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	vector<vector<int>> paths;
	if(root == NULL)
		return paths;

	vector<int> path;
	computePaths(root, sum, path, paths);
	return paths;
}