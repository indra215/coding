#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int saveGotham(vector<int>& v, int N){
	int res = 0;
	stack<int> s;
	for(int i=0;i<N;i++){
		if(s.empty() || v[s.top()] >= v[i]){
			s.push(i);
		}else{
			int e = s.top();
			s.pop();
			while(v[e] < v[i]){
				res += v[i];
				if(s.empty())
					break;
				e = s.top();
				s.pop();
			}
			if(v[e] >= v[i])
				s.push(e);
			s.push(i);
		}
	}
	return res;
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
		int ans = saveGotham(v, N);
		cout << ans << "\n";
	}
	return 0;
}