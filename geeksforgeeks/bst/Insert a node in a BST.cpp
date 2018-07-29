/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* The structure of a BST node is as follows:
struct node {
  int data;
  struct node * right, * left;
}; */
/* This function should insert a new node with given data and
   return root of the modified tree  */
struct node* createNode(int data)
{
	struct node* n = (struct node*)malloc(sizeof(struct node&));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

struct node* insert(struct node* root, int data)
{
	if(root == NULL){
		struct node* n = createNode(data);
		return n;
	}
	else if(root->data < data){
		root->right = insert(root->right, data);
	}
	else if(root->data > data){
		root->left = insert(root->left, data);
	}
	return root;
}