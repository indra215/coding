#include <iostream>
#include <vector>
#include <stack>

#define NOTP -1

using namespace std;

void print(vector<int> v, int N){
	for(int i=0;i<N;i++)
		cout << v[i] << " ";
	cout << "\n";
}

vector<int> nextgreater(vector<int>& v, int N){
	stack<int> s;
	vector<int> result(N, NOTP);
	for(int i=0;i<N;i++){
		if(s.empty() || v[s.top()] >= v[i]){
			s.push(i);
		}else{
			int e = s.top();
			s.pop();
			while(v[e] < v[i]){
				result[e] = i;
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
	while(!s.empty()){
		int e = s.top();
		s.pop();
		result[e] = NOTP;
	}
	// print(result, N);
	return result;
}

void leafnodes(vector<int>& v, int s, int e, vector<int>& great){
	if(s > e)
		return;

	if(s == e){
		cout << v[s] << " ";
		return;
	}
	int index = great[s];
	if(index == -1){
		leafnodes(v, s+1, e, great);
		return;
	}
	else if(index > e){
		leafnodes(v, s+1, index-1, great);
		return;
	}
	else{
		leafnodes(v, s+1, index-1, great);
		leafnodes(v, index, e, great);
	}
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
		vector<int> great;
		great = nextgreater(v, N);
		leafnodes(v, 0, N-1, great);
		cout << "\n";
	}
	return 0;
}