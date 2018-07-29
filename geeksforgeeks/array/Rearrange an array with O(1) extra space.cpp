#include <iostream>
#include <vector>

using namespace std;

void rearrange(vector<int>& v, int N){
	// Step1: make v'[i] = v[i] + (v[v[i]] % N)*N
	// this way older element is given by v'[i]%N and 
	// new element is given by v'[i]/N
	for(int i=0;i<N;i++){
		v[i] += (((v[v[i]])%N)*N);
	}
	// replace the array with new element now
	for(int i=0;i<N;i++){
		v[i] = v[i]/N;
	}
}

int main() {
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		int N, key;
		cin >> N;
		vector<int> v(N);
		for(int i=0;i<N;i++){
			cin >> v[i];
		}
		rearrange(v, N);
		for(int i=0;i<N;i++){
			cout << v[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}