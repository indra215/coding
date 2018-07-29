#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isOpen(char c){
	if(c == '(' || c == '{' || c == '[')
		return true;
	return false;
}

int validSubstring(string inp){
	int len = inp.length();
	if(len == 0 || len == 1)
		return 0;
	stack<int> s;
	s.push(-1);
	int maxlen = 0;
	for(int i=0;i<len;i++){
		char ch = inp[i];
		if(isOpen(ch)){
			s.push(i);
		}else{
			if(!s.empty()){
				s.pop();
				if(!s.empty())
					maxlen = max(maxlen, i-s.top());
				else
					s.push(i);
			}
		}
	}
	return maxlen;
}

int main() {
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		string inp;
		cin >> inp;
		int ans = validSubstring(inp);
		cout << ans << "\n";
	}
	return 0;
}