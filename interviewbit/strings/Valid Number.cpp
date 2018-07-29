int Solution::isNumber(const string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if(A.empty())
		return 0;
	int i = 0;
	if(A[i] == '+'){
		flag = 1;
		i++;
	}
	else if(A[i] == '-'){
		flag = -1;
		i++;
	}
	while(i < A.length()){
		if(isdigit(A[i]))
			break;
		i++;
	}
	if(i == A.length())
		return 0;
	for(;i<A.length();i++){
		if(A[i] != '.')
	}
}