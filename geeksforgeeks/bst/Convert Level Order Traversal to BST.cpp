/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


//User function Template for C++
/*
Structure of the Node of the node of the bst 
should be as
struct Node
{
	int data;
	Node *left, *right;
};
*/
// You are required to complete this function
struct node
{
	Node* tree;
	int min;
	int max;
	node(Node* n, int mn, int mx) : tree(n), min(mn), max(mx) {}
};

Node* createNode(int v)
{
	Node *n = (Node*)malloc(sizeof(Node*));
	n->data = v;
	n->left = NULL;
	n->right = NULL;
	return n;
}

Node* constructBst(int arr[], int N)
{
    if(N == 0)
    	return NULL;
    
    int i = 0;
    Node *root = createNode(arr[i++]);
    queue<node> q;
    node newn(root, INT_MIN, INT_MAX);
    q.push(newn);

    while(i < N){
    	node temp = q.front();
    	q.pop();

    	if(i < N && arr[i] < temp.tree->data &&
    				arr[i] >= temp.min &&
    				arr[i] <= temp.max){
    		Node *n = createNode(arr[i++]);
    		node newn(n, temp.min, temp.tree->data-1);
    		q.push(newn);
    		temp.tree->left = n; 
    	}

    	if(i < N && arr[i] > temp.tree->data &&
    				arr[i] >= temp.min &&
    				arr[i] <= temp.max){
    		Node *n = createNode(arr[i++]);
    		node newn(n, temp.tree->data+1, temp.max);
    		q.push(newn);
    		temp.tree->right = n; 
    	}
    }

	return root;
}
