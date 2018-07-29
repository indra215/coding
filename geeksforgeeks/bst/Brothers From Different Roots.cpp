/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


//User function Template for C++
/*Structure of the Node of the BST is as
struct Node {
	int data;
	Node* left, *right;
};*/
// You are required to complete this function
int countPairs(Node* root1, Node* root2, int x)
{
	if(root1 == NULL || root2 == NULL)
		return 0;
	Node* c1;
	Node* c2;
	stack<Node*> s1, s2;
	int count = 0;
	while(1){
		while(root1 != NULL){
			s1.push(root1);
			root1 = root1->left;
		}
		while(root2 != NULL){
			s2.push(root2);
			root2 = root2->right;
		}
		
		if(s1.empty() || s2.empty())
			break;

		c1 = s1.top();
		c2 = s2.top();
		if((c1->data + c2->data) == x){
			count++;
			s1.pop();
			s2.pop();
			root1 = c1->right;
			root2 = c2->left;
		}
		else if((c1->data + c2->data) < x){
			s1.pop();
			root1 = c1->right;
		}else if((c1->data + c2->data) > x){
			s2.pop();
			root2 = c2->left;
		}
	}
	return count;
}