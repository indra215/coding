#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int optimalTree(vector<int>& keys, vector<int>& freq, int N)
{
	if(N == 1)
		return freq[N-1];
	vector<int> sums(N+1);
	sums[0] = 0;
	for(int i=1;i<=N;i++){
		sums[i] = sums[i-1] + freq[i-1];
	}
	vector<vector<int>> cost(N, vector<int>(N, INT_MAX));
	for(int i=0;i<N;i++){
		cost[i][i] = freq[i];
	}
	for(int L=2;L<=N;L++){
		for(int i=0;i<=N-L;i++){
			int j = i+L-1;
			int s = sums[j+1] - sums[i];
			for(int k=i;k<=j;k++){
				int c = s + ((k > i) ? cost[i][k-1] : 0) + 
							((j > k) ? cost[k+1][j] : 0);
				cost[i][j] = min(cost[i][j], c);
				// cout << cost[i][j] << "\n";
			}
		}
	}
	return cost[0][N-1];
}

int main()
{
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		int N;
		cin >> N;
		vector<int> keys(N), freq(N);
		for(int i=0;i<N;i++){
			cin >> keys[i];
		}
		for(int i=0;i<N;i++){
			cin >> freq[i];
		}
		int ans = optimalTree(keys, freq, N);
		cout << ans << "\n";
	}
	return 0;
}