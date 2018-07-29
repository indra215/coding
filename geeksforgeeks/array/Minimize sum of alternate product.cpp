#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSumProd(vector<int>& v, int N){
	// sort the vector
	sort(v.begin(), v.end());
	int l = 0, r = N-1, ans = 0;
	while(l < r){
		ans += (v[l]*v[r]);
		l++;
		r--;
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		int N, key;
		cin >> N;
		vector<int> v(N);
		for(int i=0;i<N;i++){
			cin >> v[i];
		}
		int ans = minSumProd(v, N);
		cout << ans << "\n";
	}
	return 0;
}