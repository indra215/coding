#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isOperator(char ch){
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
		return true;
	return false;
}

int precedence(char ch){
	switch(ch){
		case '+': return 1;
		case '-': return 1;
		case '*': return 2;
		case '/': return 2;
		case '^': return 3;
	}
	return -1;
}

string infixToPostfix(string inp){
	int len = inp.length();
	string res = "";
	stack<char> s;
	for(int i=0;i<len;i++){
		char ch = inp[i];
		if(ch == '(')
			s.push(ch);
		else if(!isOperator(ch) && ch != ')')
			res += ch;
		else if(isOperator(ch)){
			if(s.empty() || precedence(ch) > precedence(s.top()))
				s.push(ch);
			else{
				while(!s.empty() && precedence(ch) <= precedence(s.top())){
					res += s.top();
					s.pop();
				}
				s.push(ch);
			}
		}
		else if(ch == ')'){
			while(!s.empty() && s.top() != '('){
				res += s.top();
				s.pop();
			}
			s.pop();
		}
	}
	while(!s.empty()){
		res += s.top();
		s.pop();
	}
	return res;
}

int main() {
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		string inp;
		cin >> inp;
		string ans = infixToPostfix(inp);
		cout << ans << "\n";
	}
	return 0;
}