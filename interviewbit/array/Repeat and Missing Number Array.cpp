vector<int> Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	long long sum,squareSum,temp;
	sum = 0;
	squareSum = 0;
	for(int i=0;i<A.size();i++){
		temp = A[i];
		sum += temp;
		sum -= (i+1);
		squareSum += (temp*temp);
		squareSum -= ((long long)(i+1) * (long long)(i+1));
	}

	// relation 1
	// r1 = A - B = sum (here)
	// relation 2
	// r2 = A^2 - B^2 = (A-B)*(A+B)
	squareSum = squareSum/sum;		// A + B
	int a = (int)((squareSum + sum)/2);
	int b = squareSum - a;

	vector<int> result;
	result.push_back(a);
	result.push_back(b);

	return result;
}
