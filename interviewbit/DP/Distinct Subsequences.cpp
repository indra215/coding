int Solution::numDistinct(string S, string T) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(S.empty() && T.empty())
		return 1;

	int m = S.length(), n = T.length();
	vector<vector<int>> subseq;
	for(int i=0;i<=m;i++){
		vector<int> v(n+1, 0);
		subseq.push_back(v);
	}

	// if S is empty
	for(int i=0;i<=n;i++){
		subseq[0][i] = 0;
	}

	// if T is empty
	for(int i=0;i<=m;i++){
		subseq[i][0] = 1;
	}

	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			// Case 1:- S[i-1] == T[j-1]
			if(S[i-1] == T[j-1]){
				subseq[i][j] = subseq[i-1][j-1] + subseq[i-1][j];
			}else{
				subseq[i][j] = subseq[i-1][j];
			}
		}
	}

	return subseq[m][n];
}