#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sumSmallest(vector<int>& v, int N, int k1, int k2){
	sort(v.begin(), v.end());
	int sum = 0;
	for(int i=k1;i<k2-1;i++){
		sum += v[i];
	}
	return sum;
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
		int k1, k2;
		cin >> k1 >> k2;
		int ans = sumSmallest(v, N, k1, k2);
		cout << ans << "\n";
	}
	return 0;
}