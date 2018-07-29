int Solution::anytwo(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(A.length() < 2){
		return 0;
	}

	int m = A.length();
	vector<vector<int>> lcs;
	for(int i=0;i<=m;i++){
		vector<int> v(m+1);
		lcs.push_back(v);
	}

	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(A[i-1] == A[j-1] && i != j){
				lcs[i][j] = 1 + lcs[i-1][j-1];
			}else{
				lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
			}
		}
	}

	return lcs[m][m] >=2 ? 1 : 0;
}