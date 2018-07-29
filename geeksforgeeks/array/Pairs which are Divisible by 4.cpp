#include <iostream>
#include <vector>

using namespace std;

int pairsby4(vector<int>& v, int N){
	// compute a freq array s.t.
	// freq[i] = no of elements equal to i modulo 4
	vector<int> freq(4, 0);
	for(int i=0;i<N;i++){
		int m = v[i]%4;
		freq[m]++;
	}
	int ans;
	ans = ((freq[0]*(freq[0]-1))/2) + ((freq[2]*(freq[2]-1))/2) + 
							(freq[1]*freq[3]);
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
		int ans = pairsby4(v, N);
		cout << ans << "\n";
	}
	return 0;
}