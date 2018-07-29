int Solution::minPathSum(vector<vector<int> > &path) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(path.empty()){
		return 0;
	}

	int m = path.size(), n = path[0].size();
	vector<vector<int>> pathSum;
	for(int i=0;i<m;i++){
		vector<int> v(n);
		pathSum.push_back(v);
	}

	for(int i=0;i<m;i++){
		if(i == 0){
			pathSum[i][0] = path[i][0];
		}else{
			pathSum[i][0] = path[i][0] + pathSum[i-1][0];
		}
	}

	for(int i=1;i<n;i++){
		pathSum[0][i] = path[0][i] + pathSum[0][i-1];
	}

	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			pathSum[i][j] = path[i][j] + min(pathSum[i][j-1], pathSum[i-1][j]);
		}
	}

	return pathSum[m-1][n-1];
}