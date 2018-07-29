#include <iostream>
#include <vector>

using namespace std;

int countPairs(vector<int>& v, int N){
	// get the count of elements = 2 ==> tc
	// get the count of elements > 2 ==> tgc
	int tc = 0, tgc = 0;
	for(int i=0;i<N;i++){
		if(v[i] == 2)
			tc++;
		else if(v[i] > 2)
			tgc++;
	}
	int ans;
	ans = (tc * tgc) + ((tgc*(tgc-1))/2);
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
		int ans = countPairs(v, N);
		cout << ans << "\n";
	}
	return 0;
}