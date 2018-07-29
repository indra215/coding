int Solution::numDecodings(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(A.empty()){
		return 0;
	}

	if(A[0] == '0'){
		return 0;
	}

	int n = A.length();
	vector<int> decode(n+1);
	decode[0] = 1;
	decode[1] = 1;

	for(int i=2;i<=n;i++){
		if(A[i-1] > '0'){
			decode[i] = decode[i-1];
		}
		if(A[i-2] == '1' || (A[i-2] == '2' && A[i-1] < '7')){
			decode[i] += decode[i-2];
		}
	}

	return decode[n];
}