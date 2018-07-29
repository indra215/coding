#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

int isPreorder(vector<int>& v, int N)
{
	int root = INT_MIN;
	stack<int> s;
	for(int i=0;i<N;i++){
		if(v[i] < root)
			return 0;
		
		while(!s.empty() && s.top() < v[i]){
			root = s.top();
			s.pop();
		}
		s.push(v[i]);
	}
	return 1;
}

int main()
{
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		int N;
		cin >> N;
		vector<int> v(N);
		for(int i=0;i<N;i++){
			cin >> v[i];
		}
		cout << isPreorder(v, N) << "\n";
	}
	return 0;
}