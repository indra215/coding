#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

int minReversals(string inp){
	int len = inp.length();
	if(len%2 != 0)
		return -1;
	stack<char> s;
	for(int i=0;i<len;i++){
		char ch = inp[i];
		if(ch == '}' && !s.empty()){
			if(s.top() == '{')
				s.pop();
			else s.push(ch);
		}else{
			s.push(ch);
		}
	}

	int m = 0, n = 0;
	while(!s.empty()){
		if(s.top() == '{')
			m++;
		else n++;
		s.pop();
	}
	// cout << m << " " << n << "\n";
	return ceil(m/2.0) + ceil(n/2.0);
}

int main() {
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		string inp;
		cin >> inp;
		int ans = minReversals(inp);
		cout << ans << "\n";
	}
	return 0;
}