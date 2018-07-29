#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int friendliness(vector<int>& v, int N){
	if(N == 2){
		return 2*abs(v[0]-v[1]);
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for(int i=0;i<N;i++){
		if(i == 0){
			ans += abs(v[i]-v[i+1]);
		}else if(i == N-1){
			ans += abs(v[i]-v[i-1]);
		}else{
			ans += min(abs(v[i]-v[i-1]), abs(v[i]-v[i+1]));
		}
	}
	return ans;
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
		int ans = friendliness(v, N);
		cout << ans << "\n";
	}
	return 0;
}