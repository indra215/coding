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
void insertNodes(Node* root, unordered_set<int>& nodes, 
								unordered_set<int>& leaves)
{
	if(root == NULL)
		return;

	if(root->left == NULL && root->right){
		leaves.insert(root->data);
	}
	nodes.insert(root->data);
	
	insertNodes(root->left, nodes, leaves);
	insertNodes(root->right, nodes, leaves);
}

bool isDeadEnd(Node *root)
{
	if(root == NULL)
		return true;

	unordered_set<int> nodes, leaves;
	insertNodes(root, nodes, leaves);

	unordered_set<int>::const_iterator nit1, nit2;
	for(auto it=leaves.begin();it!=leaves.end();it++){
		nit1 = nodes.find((*it)+1);
		nit2 = nodes.find((*it)-1);
		if(nit1 == nodes.end() && nit2 == nodes.end())
			continue;
		else
			return true;
	}
	return false;
}