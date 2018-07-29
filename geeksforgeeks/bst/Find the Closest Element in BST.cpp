/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/
/*You are required to complete below method */
void maxDiffUtil(Node* root, int k, int& minkey, int& mindiff)
{
	if(root == NULL)
		return;
	if(root->data == k){
		minkey = root->data;
		mindiff = 0;
		return;
	}
	if(mindiff > abs(root->data - k)){
		mindiff = abs(root->data - k);
		minkey = root->data;
	}
	if(root->data < k)
		maxDiffUtil(root->right, k, minkey, mindiff);
	if(root->data > k)
		maxDiffUtil(root->left, k, minkey, mindiff);
}

int maxDiff(Node *root, int k)
{
	int mindiff = INT_MAX, minkey;
	maxDiffUtil(root, k, minkey, mindiff);
	return minkey;
}
