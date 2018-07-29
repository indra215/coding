#include <iostream>
#include <vector>

using namespace std;

int maxSumSub(vector<int>& v, int N)
{
	int res = 0;
	for(int i=0;i<N-1;i++){
		res = max(res, v[i]+v[i+1]);
	}
	return res;
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
		int ans = maxSumSub(v, N);
		cout << ans << "\n";
	}
	return 0;
}