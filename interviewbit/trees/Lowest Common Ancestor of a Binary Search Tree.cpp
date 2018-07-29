/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
		if(root == NULL)
			return root;
		
		if(root == p){
			return root;
		}

		if(root == q){
			return root;
		}

		TreeNode* left_lca = findLCA(root->left, p, q);
		TreeNode* right_lca = findLCA(root->right, p, q);

		if(left_lca && right_lca){
			return root;
		}

		return (left_lca != NULL) ? left_lca : right_lca;
	}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	if(root == NULL){
    		return NULL;
    	}       

    	TreeNode *lca = findLCA(root, p, q);

    	return lca;
    }
};