/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

TreeLinkNode *getNextRightLevel(TreeLinkNode *node) {
	TreeLinkNode *temp = node->next;
	while(temp != NULL){
		if(temp->left)
			return temp->left;
		if(temp->right)
			return temp->right;
		temp = temp->next;
	}
	return NULL;
}


void Solution::connect(TreeLinkNode* root) {

	if(root == NULL)
		return;

	// next of root is NULL
	root->next = NULL;

	TreeLinkNode *p = root;
	while(p != NULL){
		TreeLinkNode *q = p;
		while(q != NULL){
			if(q->left){
				if(q->right)
					q->left->next = q->right;
				else
					q->left->next = getNextRightLevel(q);
			}
			if(q->right){
				q->right->next =getNextRightLevel(q);
			}
			q = q->next;
		}
		if(p->left)
			p = p->left;
		else if(p->right)
			p = p->right;
		else p = getNextRightLevel(p);
	}
}