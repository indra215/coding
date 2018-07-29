int integer(char ch){
	switch(ch){
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
	}
}

int Solution::romanToInt(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if(A.empty())
		return 0;
	int n = A.length();
	int i = 0, sum = 0;
	while(i < n-1){
		if(integer(A[i+1]) > integer(A[i])){
			sum += (integer(A[i+1]) - integer(A[i]));
			i += 2;
		}else{
			sum += integer(A[i]);
			i += 1;
		}
	}
	if(i == n-1){
		sum += integer(A[i]);
	}
	return sum;
}