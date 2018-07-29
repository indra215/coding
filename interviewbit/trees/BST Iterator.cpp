/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

stack<TreeNode*> nodes;

void pushNodes(TreeNode *root){
	while(root != NULL){
		nodes.push(root);
		root = root->left;
	}
}

BSTIterator::BSTIterator(TreeNode *root) {
	pushNodes(root);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
	if(!nodes.empty())
		return true;
	return false;
}

/** @return the next smallest number */
int BSTIterator::next() {
	TreeNode *n = nodes.top();
	nodes.pop();
	pushNodes(n->right);
	return n->val;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
 