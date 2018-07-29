#include <iostream>
#include <vector>
#define MAXN 1001

using namespace std;

int sumDistinct(vector<int>& v, int N){
	if(N == 1)
		return v[0];
	vector<int> count(MAXN, 0);
	int sum = 0;
	for(int i=0;i<N;i++){
		count[v[i]]++;
		if(count[v[i]] == 1)
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
		int ans = sumDistinct(v, N);
		cout << ans << "\n";
	}
	return 0;
}