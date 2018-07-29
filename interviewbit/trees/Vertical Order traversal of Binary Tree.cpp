/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void findMinMax(TreeNode *root, int *minhd, int *maxhd, int hd) {
	if(root == NULL)
		return;

	if(hd < *minhd)
		*minhd = hd;
	if(hd > *maxhd)
		*maxhd = hd;

	findMinMax(root->left, minhd, maxhd, hd-1);
	findMinMax(root->right, minhd, maxhd, hd+1);
}

void populateVertical(TreeNode *root, vector<vector<int>>& vertical, int minhd) {
	queue<pair<TreeNode*,int>> nodes;
	nodes.push(make_pair(root, 0));
	
	while(!nodes.empty()){
		pair<TreeNode*,int> n = nodes.front();
		nodes.pop();
		
		vertical[n.second-minhd].push_back(n.first->val);
		
		if(n.first->left)
			nodes.push(make_pair(n.first->left, n.second-1));
		if(n.first->right)
			nodes.push(make_pair(n.first->right, n.second+1));
	}
}

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* root) {

	if(root == NULL)
		return vector<vector<int>>();

	// find the min and max horizontal distances w.r.t the root
	int minhd = 0, maxhd = 0;
	findMinMax(root, &minhd, &maxhd, 0);

	if(minhd == INT_MAX)
		minhd = 0;
	if(maxhd == INT_MIN)
		maxhd = 0;

	vector<vector<int>> vertical;
	for(int i=minhd;i<=maxhd;i++){
		vector<int> v;
		vertical.push_back(v);
	}

	populateVertical(root, vertical, minhd);

	return vertical;
}