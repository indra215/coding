#include <iostream>
#include <vector>

using namespace std;

int evenSubarrays(vector<int>& v, int N){
	if(N == 1){
		return (v[0]%2 == 0 ? 1 : 0);
	}
	vector<int> sums(N);
	sums[0] = v[0];
	for(int i=1;i<N;i++){
		sums[i] = sums[i-1] + v[i];
	}
	int nod = 0, nev = 0;
	for(int i=0;i<N;i++){
		if(sums[i]%2 == 0)
			nev++;
		else
			nod++;
	}
	int ans;
	ans = (nod*(nod-1)/2) + nev + (nev*(nev-1)/2);
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
		int ans = evenSubarrays(v, N);
		cout << ans << "\n";
	}
	return 0;
}