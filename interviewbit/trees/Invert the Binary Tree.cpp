/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void mirrorTree(TreeNode *root) {
	if(root == NULL)
		return;
	mirrorTree(root->left);
	mirrorTree(root->right);
	swap(root->left, root->right);
}

TreeNode* Solution::invertTree(TreeNode* root) {
	if(root == NULL)
		return root;
	mirrorTree(root);
	return root;
}