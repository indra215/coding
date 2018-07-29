int Solution::climbStairs(int n) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(n <= 1){
		return n;
	}

	vector<int> steps(n+1);
	steps[0] = 0;
	steps[1] = 1;
	for(int i=2;i<=n;i++){
		steps[i] = steps[i-1] + steps[i-2];
	}
	return steps[n];
}