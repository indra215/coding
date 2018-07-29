int Solution::minDistance(string A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(A.empty() && B.empty()){
		return 0;
	}

	if(A.empty()){
		return B.length();
	}

	if(B.empty()){
		return A.length();
	}

	int m = A.length(), n = B.length();

	vector<vector<int>> editDistance;
	for(int i=0;i<=m;i++){
		vector<int> v(n+1);
		editDistance.push_back(v);
	}

	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i == 0){
				editDistance[i][j] = j;
			}
			else if(j == 0){
				editDistance[i][j] = i;
			}
			else if(A[i-1] == B[j-1]){
				editDistance[i][j] = editDistance[i-1][j-1];
			}
			else{
				editDistance[i][j] = 1 + min(editDistance[i-1][j-1],
											min(editDistance[i][j-1],editDistance[i-1][j]));
			}
		}
	}

	return editDistance[m][n];
}