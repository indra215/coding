/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool findKey(TreeNode *node, int key) {
	if(node == NULL)
		return false;

	if(node->val == key || findKey(node->left, key) || findKey(node->right, key))
		return true;

	return false;
}

TreeNode *findLCA(TreeNode *root, int val1, int val2, bool &isVal1, bool &isVal2) {
	if(root == NULL)
		return root;

	// if any of the key is present in tree
	if(root->val == val1){
		isVal1 = true;
		return root;
	}
	if(root->val == val2){
		isVal2 = true;
		return root;
	}

	TreeNode *left_lca = findLCA(root->left, val1, val2, isVal1, isVal2);
	TreeNode *right_lca = findLCA(root->right, val1, val2, isVal1, isVal2);

	if(left_lca && right_lca)
		return root;
	return (left_lca != NULL) ? left_lca : right_lca;
}


int Solution::lca(TreeNode* root, int val1, int val2) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(root == NULL)
		return -1;

	bool isVal1 = false, isVal2 = false;
	TreeNode *lca = findLCA(root, val1, val2, isVal1, isVal2);
	// check whether both the keys are in the tree
	if((isVal1 && isVal2) || (isVal1 && findKey(lca, val2)) || 
								(isVal2 && findKey(lca, val1)))
		return lca->val;

	return -1;
}