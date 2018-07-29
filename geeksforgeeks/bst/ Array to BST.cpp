#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printPreorder(TreeNode* root){
	if(root == NULL)
		return;
	cout << root->val << " ";
	printPreorder(root->left);
	printPreorder(root->right);
}

TreeNode* construtTreeUtil(vector<int>& v, int s, int e){
	if(s > e)
		return NULL;
	int mid = s + (e - s)/2;
	TreeNode* root = new TreeNode(v[mid]);
	root->left = construtTreeUtil(v, s, mid-1);
	root->right = construtTreeUtil(v, mid+1, e);
	return root;
}

void construtTree(vector<int>& v, int N){
	if(N == 1){
		cout << v[N-1] << "\n";
		return;
	}
	TreeNode* root = construtTreeUtil(v, 0, N-1);
	printPreorder(root);
	cout << "\n";
}

int main() {
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		int N;
		cin >> N;
		vector<int> v(N);
		for(int i=0;i<N;i++){
			cin >> v[i];
		}
		construtTree(v, N);
	}
	return 0;
}