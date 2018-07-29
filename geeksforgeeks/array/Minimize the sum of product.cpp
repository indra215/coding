#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSumProd(vector<int>& v1, vector<int>& v2, int N){
	// sort both the arrays
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int l = 0, r = N-1, sum = 0;
	while(l < N && r >= 0){
		sum += (v1[l]*v2[r]);
		l++;
		r--;
	}
	return sum;
}

int main() {
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		int N, key;
		cin >> N;
		vector<int> v1(N), v2(N);
		for(int i=0;i<N;i++){
			cin >> v1[i];
		}
		for(int i=0;i<N;i++){
			cin >> v2[i];
		}
		int ans = minSumProd(v1, v2, N);
		cout << ans << "\n";
	}
	return 0;
}