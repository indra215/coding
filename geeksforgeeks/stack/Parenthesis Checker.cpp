#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isOpen(char c){
	if(c == '(' || c == '{' || c == '[')
		return true;
	return false;
}

bool isbalanced(char c1, char c2){
	if((c1 == '(' && c2 == ')') || (c1 == '{' && c2 == '}') || (c1 == '[' && c2 == ']'))
		return true;
	return false;
}

bool checkBraces(string inp){
	int len = inp.length();
	if(len == 0)
		return true;
	if(len == 1)
		return false;
	stack<char> s;
	for(int i=0;i<len;i++){
		char ch = inp[i];
		if(isOpen(ch)){
			s.push(ch);
		}else if(!isOpen(ch)){
			if(s.empty())
				return false;
			else{
				if(isbalanced(s.top(), ch)){
					s.pop();
				}else{
					return false;
				}
			}
		}
	}
	return (s.empty() ? true : false);
}

int main() {
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		string inp;
		cin >> inp;
		bool ans = checkBraces(inp);
		cout << (ans ? "balanced" : "not balanced") << "\n";
	}
	return 0;
}