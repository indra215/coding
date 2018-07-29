int Solution::power(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if(A.empty())
		return 1;
	int n = A.length();
	long long num = 0;
	int i = 0;
	while(i < n){
		num = num*10 + (A[i]-'0');
		i++;
	}
	if(num == 1)
		return 0;
	long long prev = num-1;
	if((num & prev) == 0)
		return 1;
	return 0;
}