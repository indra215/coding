/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* The structure of Node is
struct Node {
int data;
Node * right, * left;
};*/
/*You are required to complete below method */
void merge(Node *root1, Node *root2)
{
	Node *curr1 = root1, *curr2 = root2;
	stack<Node*> s1, s2;
	Node *top1, *top2;
	while(1){
		while(curr1 != NULL){
			s1.push(curr1);
			curr1 = curr1->left;
		}
		while(curr2 != NULL){
			s2.push(curr2);
			curr2 = curr2->left;
		}
		
		if(s1.empty() && s2.empty())
			break;
		if(!s1.empty()){
			top1 = s1.top();
			// s1.pop();
		}else{
			top1 = NULL;
		}
		if(!s2.empty()){
			top2 = s2.top();
			// s2.pop();
		}else{
			top2 = NULL;
		}

		int v1 = ((top1 != NULL) ? top1->data : INT_MAX);
		int v2 = ((top2 != NULL) ? top2->data : INT_MAX);
		if(v1 <= v2){
			s1.pop();
			cout << v1 << " ";
			curr1 = ((top1 != NULL) ? top1->right : NULL);
		}
		else{
			s2.pop();
			cout << v2 << " ";
			curr2 = ((top2 != NULL) ? top2->right : NULL);
		}
	}
}