/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::t2Sum(TreeNode* root, int target) {

	if(root == NULL)
		return 0;

	stack<TreeNode*> nodes1, nodes2;
	TreeNode *curr1 = root, *curr2 = root;
	bool done1 = false, done2 = false;
	int val1, val2;

	while(1){
		while(!done1){
			if(curr1 != NULL){
				nodes1.push(curr1);
				curr1 = curr1->left;
			}
			else{
				if(nodes1.empty())
					done1 = true;
				else{
					curr1 = nodes1.top();
					nodes1.pop();
					val1 = curr1->val;
					curr1 = curr1->right;
					done1 = true;
				}
			}
		}

		while(!done2){
			if(curr2 != NULL){
				nodes2.push(curr2);
				curr2 = curr2->right;
			}
			else{
				if(nodes2.empty())
					done2 = true;
				else{
					curr2 = nodes2.top();
					nodes2.pop();
					val2 = curr2->val;
					curr2 = curr2->left;
					done2 = true;
				}
			}
		}

		if((val1 != val2) && (val1 + val2) == target)
			return 1;
		if((val1 + val2) < target)
			done1 = false;
		else if((val1 + val2) > target)
			done2 = false;

		if(val1 >= val2)
			return 0;
	}	
	return 0;
}