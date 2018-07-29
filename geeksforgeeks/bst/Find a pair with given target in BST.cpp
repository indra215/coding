/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Complete the function below
Node is as follows
struct node
{
    int val;
    struct node *left, *right;
};
*/
bool isPairPresent(struct node *root, int target)
{
	struct node* c1 = root, *c2 = root;
	stack<struct node*> s1, s2;
	while(1){
		while(c1 != NULL){
			s1.push(c1);
			c1 = c1->left;
		}
		while(c2 != NULL){
			s2.push(c2);
			c2 = c2->right;
		}
		if(s1.empty() || s2.empty())
			break;

		struct node *top1 = s1.top(), *top2 = s2.top();
		if(top1->val >= top2->val)
			break;
		
		if((top1->val + top2->val) == target)
			return true;
		else if((top1->val + top2->val) < target){
			s1.pop();
			c1 = top1->right;
		}else{
			s2.pop();
			c2 = top2->left;
		}
	}
	return false;
}