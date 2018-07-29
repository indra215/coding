#include <iostream>
#include <vector>

using namespace std;

int maxBitonic(vector<int>& v, int N){
	if(N == 1)
		return v[0];
	for(int i=0;i<N-1;i++){
		if(v[i] > v[i+1])
			return i;
	}
	return N-1;
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
		int ans = maxBitonic(v, N);
		cout << v[ans] << "\n";
	}
	return 0;
}