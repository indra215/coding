/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
Structure of the binary Search Tree is as
struct node
{
	int key;
	struct node *left, *right;
};
*/
// your task is to complete the Function
// Function is used to change a key value in the given BST
// Note: Function should return root node to the new modified BST
struct node* minValueNode(struct node* root)
{
	if(root != NULL){
		struct node* curr = root;
		while(curr->left != NULL)
			curr = curr->left;
		return curr;
	}
}

struct node* deleteNode(struct node* root, int key)
{
	if(root == NULL)
		return root;
	if(root->key > key){
		root->left = deleteNode(root->left, key);
	}
	else if(root->key < key){
		root->right = deleteNode(root->right, key);
	}
	else{
		if(root->right == NULL){
			struct node* temp = root->left;
			free(root);
			return temp;
		}
		else if(root->left == NULL){
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		struct node* temp = minValueNode(root->right);
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

struct node* createNode(int data)
{
	struct node* n = (struct node*)malloc(sizeof(struct node&));
	n->key = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

struct node* insertNode(struct node* root, int data)
{
	if(root == NULL){
		struct node* n = createNode(data);
		return n;
	}
	else if(root->key < data){
		root->right = insert(root->right, data);
	}
	else if(root->key > data){
		root->left = insert(root->left, data);
	}
	return root;
}

struct node *changeKey(struct node *root, int oldVal, int newVal)
{
	// delete the oldVal node
	root = deleteNode(root, oldVal);
	// insert the newVal node
	root = insertNode(root, newVal);

	return root;
}