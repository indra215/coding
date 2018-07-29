#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int sumDigits(vector<int>& v, int N){
	if(N == 1)
		return v[0];

	// sort the digits array
	sort(v.begin(), v.end());
	int carry = 0, k = 0, num = 0, sum, i = N-1, j = N-2;
	while(i >= 0 && j >= 0){
		sum = v[i] + v[j] + carry;
		carry = sum/10;
		sum %= 10;
		num += (sum*pow(10,k++));
		i -= 2;
		j -= 2;
	}
	if(i == 0){
		sum = v[i] + carry;
		carry = sum/10;
		sum %= 10;
		num += (sum*pow(10,k++));
	}
	if(carry > 0){
		num += (carry*pow(10, k));
	}
	return num;
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
		int ans = sumDigits(v, N);
		cout << ans << "\n";
	}
	return 0;
}