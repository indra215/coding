/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int findinInorder(vector<int> &inorder, int val, int start, int end){
	for(int i=start;i<=end;i++){
		if(inorder[i] == val)
			return i;
	}
}

TreeNode *makeTree(vector<int> &inorder, vector<int> &postorder, int instart,
								int inend, int *postindex){
	if(instart > inend)
		return NULL;

	TreeNode *root = new TreeNode(postorder[*postindex]);
	(*postindex)--;

	if(instart == inend)
		return root;

	int index = findinInorder(inorder, root->val, instart, inend);

	root->right = makeTree(inorder, postorder, index+1, inend, postindex);
	root->left = makeTree(inorder, postorder, instart, index-1, postindex);
	
	return root;
}

TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(inorder.empty())
		return NULL;

	int postindex = postorder.size()-1;
	return makeTree(inorder, postorder, 0, inorder.size()-1, &postindex);
}