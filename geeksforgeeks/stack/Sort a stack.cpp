/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/
/* The below method sorts the stack s 
you are required to complete the below method */

void sortStack(stack<int>& s, int elem)
{
	if(s.empty() || s.top() <= elem){
		s.push(elem);
	}else{
		if(!s.empty()){
			int temp = s.top();
			s.pop();
			sortStack(s, elem);
			s.push(temp);
		}
	}
}

void SortedStack :: sort()
{
	if(s.empty())
		return;
	int temp = s.top();
	s.pop();
	sort();
	sortStack(s, temp);
}