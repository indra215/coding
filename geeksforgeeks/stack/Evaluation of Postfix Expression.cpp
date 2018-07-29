#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isOpertor(char ch){
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
		return true;
	return false;
}

int compute(int v1, int v2, char ch){
	switch(ch){
		case '+': return v1+v2;
		case '-': return v1-v2;
		case '*': return v1*v2;
		case '/': return v1/v2;
	}
}

int evaluate(string inp){
	int len = inp.length();
	stack<int> s;
	for(int i=0;i<len;i++){
		char ch = inp[i];
		if(isOpertor(ch)){
			int val1 = s.top();s.pop();
			int val2 = s.top();s.pop();
			int res = compute(val2, val1, ch);
			s.push(res);
		}else{
			s.push(ch-'0');
		}
	}
	int res = s.top();s.pop();
	return res;
}

int main() {
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		string inp;
		cin >> inp;
		int ans = evaluate(inp);
		cout << ans << "\n";
	}
	return 0;
}