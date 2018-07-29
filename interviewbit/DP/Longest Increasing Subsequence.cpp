int Solution::lis(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(A.size() <= 1){
		return A.size();
	}

	int n = A.size();
	vector<int> LIS(n, 1);

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(A[i] > A[j] && LIS[i] < 1 + LIS[j]){
				LIS[i] = 1 + LIS[j];
			}
		}
	}

	int lis = LIS[0];
	for(int i=1;i<n;i++){
		lis = max(lis, LIS[i]);
	}

	return lis;
}