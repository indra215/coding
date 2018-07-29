#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int manipulate(vector<string>& v, int N){
	if(N == 1)
		return 1;
	stack<int> s;
	int i = 0;
	while(i < N){
		if(!s.empty() && v[s.top()] == v[i]){
			s.pop();
			i++;
		}
		else{
			s.push(i++);
		}
	}
	return s.size();
}

int main() {
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		int N;
		cin >> N;
		vector<string> v(N);
		for(int i=0;i<N;i++){
			cin >> v[i];
		}
		int ans = manipulate(v, N);
		cout << ans << "\n";
	}
	return 0;
}