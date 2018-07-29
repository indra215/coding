#include <iostream>
#include <string>
#include <stack>

using namespace std;

string compress(string inp)
{
	int len = inp.length(), i = 0;
	stack<char> s;
	string res = "";
	while(i < len){
		if(s.empty() || s.top() == tolower(inp[i])){
			s.push(tolower(inp[i]));
			i++;
		}else{
			int count = 0;
			char ch = s.top();
			// cout << ch << "\n";
			while(!s.empty()){
				count++;
				s.pop();
			}
			res += (to_string(count) + ch);
			// cout << res << "\n";
		}
	}
	int count = 0;
	char ch = s.top();
	// cout << ch << "\n";
	while(!s.empty()){
		count++;
		s.pop();
	}
	res += (to_string(count) + ch);
	// cout << res << "\n";
	return res;
}

int main() {
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		string inp;
		cin >> inp;
		string res = compress(inp);
		cout << res << "\n";
	}
	return 0;
}