#include <iostream>
#include <vector>

using namespace std;

int incrSubarrays(vector<int>& v, int N){
	if(N == 1)
		return 0;
	int count = 1, curr_max = v[0], res = 0;
	for(int i=1;i<N;i++){
		if(v[i] > curr_max){
			count++;
			curr_max = v[i];
		}else{
			res += ((count * (count-1))/2);
			curr_max = v[i];
			count = 1;
		}
	}
	res += ((count * (count-1))/2);
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
		int ans = incrSubarrays(v, N);
		cout << ans << "\n";
	}
	return 0;
}