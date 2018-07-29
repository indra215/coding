#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void print(vector<int> v, int N){
	for(int i=0;i<N;i++){
		cout << v[i] << " ";
	}
	cout << "\n";
}

void nextGreater(vector<int>& v, int N){
	if(N == 1)
		cout << -1 << "\n";
	vector<int> res(N);
	stack<int> s;
	for(int i=0;i<N;i++){
		if(s.empty() || v[s.top()] >= v[i])
			s.push(i);
		else{
			int elem = s.top();
			s.pop();
			while(v[elem] < v[i]){
				res[elem] = v[i];
				if(s.empty())
					break;
				elem = s.top();
				s.pop();
			}
			if(v[elem] > v[i])
				s.push(elem);
			s.push(i);
		}
	}
	while(!s.empty()){
		int elem = s.top();
		s.pop();
		res[elem] = -1;
	}
	print(res, N);
}

int main() {
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		int N;
		cin >> N;
		vector<int> v(N);
		for(int i=0;i<N;i++){
			cin >> v[i];
		}
		nextGreater(v, N);
	}
	return 0;
}