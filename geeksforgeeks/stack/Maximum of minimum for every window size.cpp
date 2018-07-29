#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void print(vector<int> v){
	for(int i=0;i<v.size();i++){
		cout << v[i] << " ";
	}
	cout << "\n";
}

vector<int> leftSmallerElement(vector<int>& v, int N){
	vector<int> small(N);
	stack<int> s;
	for(int i=N-1;i>=0;i--){
		if(s.empty() || v[s.top()] <= v[i]){
			s.push(i);
		}else{
			int elem = s.top();
			s.pop();
			while(v[elem] > v[i]){
				small[elem] = i;
				if(s.empty())
					break;
				elem = s.top();
				s.pop();
			}
			if(v[elem] <= v[i])
				s.push(elem);
			s.push(i);
		}
	}
	while(!s.empty()){
		small[s.top()] = -1;
		s.pop();
	}
	return small;
}

vector<int> rightsmallerElement(vector<int>& v, int N){
	vector<int> small(N);
	stack<int> s;
	for(int i=0;i<N;i++){
		if(s.empty() || v[s.top()] <= v[i]){
			s.push(i);
		}else{
			int elem = s.top();
			s.pop();
			while(v[elem] > v[i]){
				small[elem] = i;
				if(s.empty())
					break;
				elem = s.top();
				s.pop();
			}
			if(v[elem] <= v[i])
				s.push(elem);
			s.push(i);
		}
	}
	while(!s.empty()){
		small[s.top()] = N;
		s.pop();
	}
	return small;
}

int maxMinWindow(vector<int>& v, int N){
	vector<int> left(N), right(N);
	left = leftSmallerElement(v, N);
	right = rightsmallerElement(v, N);
	vector<int> result(N, 0);
	for(int i=0;i<N;i++){
		int len = right[i]-left[i]-1;
		result[len-1] = max(result[len-1], v[i]);
	}
	for(int i=N-2;i>=0;i--){
		result[i] = max(result[i], result[i+1]);
	}
	print(result);
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
		maxMinWindow(v, N);
	}	
	return 0;
}