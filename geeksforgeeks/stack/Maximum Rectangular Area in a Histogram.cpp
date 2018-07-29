#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int maxRectArea(vector<int>& v, int N){
	if(N == 1)
		return v[0];
	stack<int> s;
	int maxarea = 0, i;
	for(i=0;i<N;i++){
		if(s.empty() || v[s.top()] <= v[i]){
			s.push(i);
		}else{
			int e = s.top();
			s.pop();
			while(v[e] > v[i]){
				int area = v[e]*(s.empty() ? i : i-s.top()-1);
				maxarea = max(area, maxarea);
				if(s.empty())
					break;
				e = s.top();
				s.pop();
			}
			if(v[e] <= v[i])
				s.push(e);
			s.push(i);
		}
	}
	while(!s.empty()){
		int e = s.top();
		s.pop();
		int area = v[e]*(s.empty() ? i : i-s.top()-1);
		maxarea = max(area, maxarea);  
	}
	return maxarea;
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
		int ans = maxRectArea(v, N);
		cout << ans << "\n";
	}
	return 0;
}