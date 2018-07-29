#include <iostream>
#include <vector>

using namespace std;

int main(){

	int n = 5;
	vector<vector<int>> result;
	for(int i=0;i<n;i++){
		vector<int> v;
		result.push_back(v);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=2*i;j++){
			result[i].push_back(j);
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<result[i].size();j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}