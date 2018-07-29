#include <iostream>
#include <string>
#include <stack>

using namespace std;

string decode(string inp){
	int len = inp.length();
	stack<char> chars;
	stack<int> nums;
	for(int i=0;i<len;i++){
		if(isdigit(inp[i])){
			int num = 0;
			while(isdigit(inp[i])){
				num = num*10 + (inp[i] - '0');
				i++;
			}
			i--;
			nums.push(num);
		}else if(isalpha(inp[i]) || inp[i] == '['){
			chars.push(inp[i]);
		}else if(inp[i] == ']'){
			int num = nums.top();
			nums.pop();
			string temp = "";
			while(!chars.empty() && chars.top() != '['){
				temp = chars.top() + temp;
				chars.pop();
			}
			chars.pop();
			// cout << "Yo\t" << temp << "\n";
			string result = "";
			for(int i=0;i<num;i++){
				result += temp;
			}
			for(int i=0;i<result.length();i++){
				chars.push(result[i]);
			}
		}
	}
	string result = "";
	while(!chars.empty()){
		result = chars.top() + result;
		chars.pop();
	}
	return result;
}

int main() {
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		string inp;
		cin >> inp;
		string ans = decode(inp);
		cout << ans << "\n";
	}
	return 0;
}