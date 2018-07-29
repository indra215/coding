int Solution::maximumGap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	int n = A.size();
	vector<int> LMin(n),RMax(n);
	LMin[0] = A[0];
	RMax[n-1] = A[n-1];
	for(int i=1;i<n;i++){
		LMin[i] = min(LMin[i-1], A[i]);
	}

	for(int j=n-2;j>=0;j--){
		RMax[j] = max(RMax[j+1], A[j]);
	}

	int i=0,j=0,max_diff=0;
	while(i < n && j < n){
		if(LMin[i] <= RMax[j]){
			max_diff = max(max_diff, j-i);
			j++;
		}else{
			i++;
		}
	}
	return max_diff;
}