#include <iostream>
#include <vector>

using namespace std;

int gcd(int n1, int n2){
	if(n2 != 0)
		return gcd(n2, n1%n2);
	else return n1;
}

int minInsertions(vector<int>& v, int N){
	int ans = 0;
	for(int i=0;i<N-1;i++){
		int n1 = v[i], n2 = v[i+1];
		if(gcd(n1, n2) != 1){
			ans++;
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
		int ans = minInsertions(v, N);
		cout << ans << "\n";
	}
	return 0;
}