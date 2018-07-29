void findCutOrder(vector<vector<int>> cost, vector<vector<int>> index, int s,
							int e, vector<int>& result, vector<int>& A) {
	if(s > e)
		return;
	int l = index[s][e];
	result.push_back(A[l]);
	findCutOrder(cost, index, s, l, result, A);
	findCutOrder(cost, index, l, e, result, A);
}

vector<int> rodCutCost(vector<int>& A, int N) {
	vector<vector<long long>> cost, index;
	long long n = A.size();
	for(long long i=0;i<n;i++){
		vector<long long> v(n);
		cost.push_back(v);
		index.push_back(v);
	}

	for(int i=0;i<n-1;i++){
		cost[i][i+1] = 0;
	}

	for(int length=2;length<n;length++){
		for(int i=0;i<n-length;i++){
			int j = i+length;
			int fc = ((long)A[j] - A[i]);
			cost[i][j] = cost[i][i+1] + cost[i+1][j] + fc;
			index[i][j] = i+1;
			for(int k=i+2;k<j;k++){
				int nc = cost[i][k] + cost[k][j] + fc;
				if(nc < cost[i][j]){
					cost[i][j] = nc;
					index[i][j] = k;
				}
			}
		}
	}

	vector<int> result;
	findCutOrder(cost, index, 0, n-1, result, A);
	return result;
}

vector<int> Solution::rodCut(int N, vector<int> &A) {
	if(N == 0 || N == 1 || A.empty())
		return vector<int>();

	// insert 0 and N at the begining and end of the vector
	A.insert(A.begin(), 0);
	A.push_back(N);

	vector<int> result;
	result = rodCutCost(A, N);
	return result;
}