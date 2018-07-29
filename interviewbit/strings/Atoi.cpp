int Solution::atoi(const string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if(A.empty())
		return 0;
	long long k = 0;
	int flag = 1, i = 0;
	while(i<A.length()){
		if(i == 0){
			if(A[i] == '+'){
				flag = 1;
				i++;
			}
			else if(A[i] == '-'){
				flag = -1;
				i++;
			}
		}
		if(!isdigit(A[i])){
			break;
		}else{
			if(k == 0){
				k = flag*(k*10 + (A[i]-'0'));
			}
			else{
				k = k*10 + (flag*(A[i]-'0'));
			}

		}
		if(k >= INT_MAX)
			return (INT_MAX);
		else if(k <= INT_MIN)
			return INT_MIN;
		i++;
	}
	if(k >= INT_MAX)
		return (INT_MAX);
	else if(k <= INT_MIN)
		return INT_MIN;

	return ((int)k);
}