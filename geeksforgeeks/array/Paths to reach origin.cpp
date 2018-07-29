#include <iostream>

using namespace std;

int countPaths(int n, int m){
	if(n == 0 || m == 0)
		return 1;
	vector<vector<int>> paths(m, vector<int> v(n));
	for(int i=0;i<m;i++){
		paths[]
	}
}

int main() {
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		int n,m;
		cin >> n >> m;
		int paths = countPaths(n, m);
	}

	return 0;
}