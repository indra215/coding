/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int findinInorder(vector<int> &inorder, int start, int end, int val){
	for(int i=start;i<=end;i++){
		if(inorder[i] == val)
			return i;
	}
}

TreeNode *makeTree(vector<int> &preorder, vector<int> &inorder, int instart,
						int inend, int *preindex){
	if(instart > inend)
		return NULL;

	TreeNode *root = new TreeNode(preorder[*preindex]);
	(*preindex)++;

	if(instart == inend)
		return root;

	int index = findinInorder(inorder, instart, inend, root->val);

	root->left = makeTree(preorder, inorder, instart, index-1, preindex);
	root->right = makeTree(preorder, inorder, index+1, inend, preindex);

	return root;
}

TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(preorder.empty())
		return NULL;

	int preindex = 0;
	return makeTree(preorder, inorder, 0, inorder.size()-1, &preindex);
}