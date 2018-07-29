#include <iostream>
#include <vector>

using namespace std;

int sumArray(vector<int>& v, int N){
	int s = 0;
	for(int i=0;i<N;i++){
		s += v[i];
	}
	return s;
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
		int ans = sumArray(v, N);
		cout << ans << "\n";
	}
	return 0;
}