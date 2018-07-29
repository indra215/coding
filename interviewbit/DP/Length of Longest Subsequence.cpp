int Solution::longestSubsequenceLength(const vector<int> &A) {
	if(A.size() <= 1){
		return A.size();
	}

	// comoute LIS from left and store in an array
	int n = A.size();
	vector<int> LISFromLeft(n);
	for(int i=0;i<n;i++){
		LISFromLeft[i] = 1;
	}

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(A[i] > A[j] && LISFromLeft[i] < 1 + LISFromLeft[j]){
				LISFromLeft[i] = 1 + LISFromLeft[j];
			}
		}
	}

	// compute LIS from right and store in an array
	vector<int> LISFromRight(n);
	for(int i=n-1;i>=0;i--){
		LISFromRight[i] = 1;
	}

	for(int i=n-2;i>=0;i--){
		for(int j=n-1;j>i;j--){
			if(A[i] > A[j] && LISFromRight[i] < 1 + LISFromRight[j]){
				LISFromRight[i] = 1 + LISFromRight[j];
			}
		}
	}

	// return max(LISFromLeft[i] + LISFromRight[i] - 1)
	int lls = 1;
	for(int i=0;i<n;i++){
		lls = max(lls, LISFromLeft[i]+LISFromRight[i]-1);
	}

	return lls;
}
