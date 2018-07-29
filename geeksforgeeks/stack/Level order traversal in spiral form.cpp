/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
void printSpiral(Node *root)
{
	if(root == NULL){
		return;
	}
	stack<Node*> ltr, rtl;
	rtl.push(root);
	while(!ltr.empty() || !rtl.empty()){
		while(!rtl.empty()){
			Node* n = rtl.top();
			rtl.pop();
			cout << n->data << " ";
			if(n->right)
				ltr.push(n->right);
			if(n->left)
				ltr.push(n->left);
		}
		while(!ltr.empty()){
			Node* n = ltr.top();
			ltr.pop();
			cout << n->data << " ";
			if(n->left)
				rtl.push(n->left);
			if(n->right)
				rtl.push(n->right);
		}
	}
}