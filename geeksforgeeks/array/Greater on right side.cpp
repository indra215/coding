#include <iostream>
#include <vector>

using namespace std;

void greaterRight(vector<int>& v, int N){
	if(N == 1){
		v[0] = -1;
		return;
	}
	int max_here = v[N-1];
	v[N-1] = -1;
	for(int i=N-2;i>=0;i--){
		int temp = v[i];
		v[i] = max_here;
		max_here = max(max_here, temp);
	}
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
		greaterRight(v, N);
		for(int i=0;i<N;i++){
			cout << v[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}