int Solution::trap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(A.empty())
		return 0;

	int n = A.size();
	vector<int> left(n), right(n);

	// fill the left array -> max height on the left side
	left[0] = A[0];
	for(int i=1;i<A.size();i++)
		left[i] = max(left[i-1], A[i]);

	right[n-1] = A[n-1];
	for(int i=n-2;i>=0;i--)
		right[i] = max(right[i+1], A[i]);

	int water = 0;
	for(int i=0;i<n;i++){
		water += min(left[i], right[i]) - A[i];
	}

	return water;
}