int Solution::maxSubArray(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	int n = A.size();
	if(n == 1)
		return A[n-1];

	int curr_max = A[0], max_sum = A[0];
	for(int i=1;i<n;i++){
		curr_max = max(curr_max+A[i], A[i]);
		max_sum = max(max_sum, curr_max);
	}

	return max_sum;
}
