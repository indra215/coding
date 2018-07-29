/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void findKthSmallest(TreeNode *root, int k, int *count, int *answer){
	if(root == NULL)
		return;
	
	findKthSmallest(root->left, k, count, answer);
	
	(*count)++;
	if(*count == k)
		*answer = root->val;

	findKthSmallest(root->right, k, count, answer);
}

int Solution::kthsmallest(TreeNode* root, int k) {
	
	int count = 0, answer;
	findKthSmallest(root, k, &count, &answer);

	return answer;
}