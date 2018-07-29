int Solution::uniquePathsWithObstacles(vector<vector<int> > &path) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(path.empty()){
		return 0;
	}

	if(path[0][0] == 1){
		return 0;
	}

	int m = path.size(), n = path[0].size();
	vector<vector<int>> uniquePaths;
	for(int i=0;i<m;i++){
		vector<int> v(n);
		uniquePaths.push_back(v);
	}

	for(int i=0;i<m;i++){
		if(path[i][0] == 1){
			uniquePaths[i][0] = 0;
		}else{
			uniquePaths[i][0] = (i == 0) ? 1 : uniquePaths[i-1][0];
		}
	}

	for(int i=1;i<n;i++){
		if(path[0][i] == 1){
			uniquePaths[0][i] = 0;
		}else{
			uniquePaths[0][i] = uniquePaths[0][i-1];
		}
	}

	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			if(path[i][j] == 1){
				uniquePaths[i][j] = 0;
			}else{
				uniquePaths[i][j] = uniquePaths[i-1][j] + uniquePaths[i][j-1];
			}
		}
	}

	return uniquePaths[m-1][n-1];
}