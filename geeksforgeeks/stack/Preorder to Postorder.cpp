#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

void print(vector<int> v, int N){
	for(int i=0;i<N;i++){
		cout << v[i] << " ";
	}
	cout << "\n";
}

vector<int> nextGreater(vector<int>& v, int N){
	stack<int> s;
	vector<int> result(N);
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
		result[e] = -1;
	}
	// print(result, N);
	return result;
}

bool preToPost(vector<int>& v, int s, int e, int min, int max, vector<int>& great, vector<int>& post){
	if(s > e)
		return true;
	static int end = v.size()-1;
	cout << end << "\n";
	post[end] = v[s];	
	end--;
	int index = great[s];
	if(v[s] < min || v[s] > max)
		return false;
	if(index == -1)
		return true;
	bool left = false, right = false;
	right = preToPost(v, index, e, v[s]+1, max, great, post);
	left = preToPost(v, s+1, index-1, min, v[s]-1, great, post);
	return (left && right);
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
		vector<int> great = nextGreater(v, N);
		vector<int> post(N);
		if(preToPost(v, 0, N-1, INT_MIN, INT_MAX, great, post)){
			print(post, N);
		}else{
			cout << "NO\n";
		}
	}
	return 0;
}