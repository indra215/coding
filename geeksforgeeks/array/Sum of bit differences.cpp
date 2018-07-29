#include <iostream>
#include <vector>

using namespace std;

int countBitDiff(vector<int>& v, int N){
	// count the number of set bits for each bit (assume INT32 nums)
	int ans = 0;
	for(int i=0;i<32;i++){
		int count = 0;
		for(int j=0;j<N;j++){
			if(v[j] & (1 << i))
				count++;
		}
		ans += (count * (N-count) * 2);
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
		int ans = countBitDiff(v, N);
		cout << ans << "\n";
	}
	return 0;
}