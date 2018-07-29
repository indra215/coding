/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool findPath(TreeNode *root, vector<int>& path, int key) {
	if(root == NULL)
		return false;
	
	path.push_back(root->val);

	if(root->val == key)
		return true;

	if((root->left && findPath(root->left, path, key)) ||
			(root->right && findPath(root->right, path, key)))
		return true;

	path.pop_back();
	return false;
}

int findLCA(TreeNode *root, int val1, int val2) {
	if(root == NULL)
		return -1;

	vector<int> path1, path2;
	if(!findPath(root, path1, val1) || !findPath(root, path2, val2))
		return -1;

	// find the last common node in both the paths
	int i;
	for(i=0;i<path1.size() && i<path2.size();i++){
		if(path1[i] != path2[i])
			break;
	}
	return path1[i-1];
}


int Solution::lca(TreeNode* root, int val1, int val2) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(root == NULL)
		return -1;

	return findLCA(root, val1, val2);
}