/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* The structure of Node
struct Node{
    int data;
    Node *left,*right;
}; */

void pthCommonAncestorUtil(int x,int y,NODE *root,vector<int>& vec)
{
	if(root == NULL)
		return;
	if(root->data > x && root->data > y){
		vec.push_back(root->data);
		pthCommonAncestorUtil(x, y, root->left, vec);
	}
	else if(root->data < x && root->data < y){
		vec.push_back(root->data);
		pthCommonAncestorUtil(x, y, root->right, vec);
	}
	else if(root->data == x || root->data == y || 
						(root->data >= x && root->data <= y) ||
						(root->data >= y && root->data <= x)){
		vec.push_back(root->data);
		return;
	}
}

int pthCommonAncestor(int x,int y,NODE *root,int p,vector<int> &vec)
{
	pthCommonAncestorUtil(x, y, root, vec);
	int n = vec.size();
	/*for(int i=0;i<n;i++){
		cout << vec[i] << " ";
	}
	cout << "\n";*/
	if((n-p) < 0)
		return -1;
	return vec[vec.size()-p];
}