/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


//User function Template for C++
queue<ll> modifyQueue(queue<ll> q, int k)
{
	stack<ll> s;
	for(int i=0;i<k;i++){
		s.push(q.front());
		q.pop();
	}
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	}
	int n = q.size();
	for(int i=0;i<n-k;i++){
		q.push(q.front());
		q.pop();
	}
	return q;
}