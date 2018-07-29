int Solution::isInterleave(string A, string B, string C) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	int m = A.length(), n = B.length(), p = C.length();
	if(p != m+n)
		return false;

	vector<vector<int>> IL;
	for(int i=0;i<=m;i++){
		vector<int> v(n+1, 0);
		IL.push_back(v);
	}

	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i == 0 && j == 0)
				IL[i][j] = 1;
			else if(i == 0 && (B[j-1] == C[j-1]))
				IL[i][j] = IL[i][j-1];
			else if(j == 0 && (A[i-1] == C[i-1]))
				IL[i][j] = IL[i-1][j];
			else if(A[i-1] == C[i+j-1] && B[j-1] != C[i+j-1])
				IL[i][j] = IL[i-1][j];
			else if(A[i-1] != C[i+j-1] && B[j-1] == C[i+j-1])
				IL[i][j] = IL[i][j-1];
			else if(A[i-1] == C[i+j-1] && B[j-1] == C[i+j-1])
				IL[i][j] = IL[i-1][j] || IL[i][j-1];
		}
	}

	return IL[m][n];
}