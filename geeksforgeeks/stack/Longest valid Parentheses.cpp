#include <iostream>
#include <string>
#include <stack>

using namespace std; 

int longestValid(string inp){
	int len = inp.length(), curr = 0;
	stack<int> s;
	s.push(-1);
	for(int i=0;i<len;i++){
		if(inp[i] == '('){
			s.push(i);
		}
		else if(inp[i] == ')'){
			s.pop();
			if(!s.empty()){
				curr = max(curr, i-s.top());
			}else{
				s.push(i);
			}
		}
	}
	return curr;
}

int main() {
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		string inp;
		cin >> inp;
		int ans = longestValid(inp);
		cout << ans << "\n";
	}
	return 0;
}