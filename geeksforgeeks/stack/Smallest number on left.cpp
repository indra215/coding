#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void print(vector<int> v, int n){
	for(int i=0;i<n;i++)
		cout << v[i] << " ";
	cout << "\n";
}

void leftSmaller(vector<int>& v, int N){
	stack<int> s;
	vector<int> result(N, -1);
	for(int i=N-1;i>=0;i--){
		if(s.empty() || v[s.top()] < v[i]){
			s.push(i);
		}else{
			int e = s.top();
			s.pop();
			while(v[e] > v[i]){
				result[e] = v[i];
				if(s.empty())
					break;
				e = s.top();
				s.pop();
			}
			if(v[e] < v[i])
				s.push(e);
			s.push(i);
		}
	}
	while(!s.empty()){
		int e = s.top();
		s.pop();
		result[e] = -1;
	}
	print(result, N);
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
		leftSmaller(v, N);
	}
	return 0;
}