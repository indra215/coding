#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxProduct(vector<int>& v, int N){
	if(N == 2){
		return (v[0]*v[1]);
	}
	int max1 = v[0], max2 = INT_MIN;
	for(int i=1;i<N;i++){
		if(v[i] > max1){
			max2 = max1;
			max1 = v[i];
		}else if(v[i] > max2){
			max2 = v[i];
		}
	}
	return (max1*max2);
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
		int ans = maxProduct(v, N);
		cout << ans << "\n";
	}
	return 0;
}