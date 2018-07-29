#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void firstNegative(vector<int>& v, int N, int k){
	deque<int> D;
	int i = 0;
	for(;i<k;i++){
		if(v[i] < 0)
			D.push_back(i);
	}

	for(;i<N;i++){
		if(!D.empty()){
			cout << v[D.front()] << " ";
		}else{
			cout << 0 << " ";
		}

		while(!D.empty() && D.front() < i-k+1){
			D.pop_front();
		}

		if(v[i] < 0){
			D.push_back(i);
		}
	}

	if(!D.empty()){
		cout << v[D.front()] << "\n";
	}else{
		cout << 0 << "\n";
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
		int k;
		cin >> k;
		firstNegative(v, N, k);
	}
	return 0;
}