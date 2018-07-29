int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	int n = A.size();
	int valueRange = n-1;
	int sqrtn = sqrt(valueRange);
	if(sqrtn*sqrtn < valueRange)
		sqrtn += 1;
	vector<int> count(sqrtn,0);
	for(int i=0;i<n;i++){
		count[A[i]-1/sqrtn] += 1;
	}

	int index;
	for(index=0;index<sqrtn;index++){
		if(count[index] > sqrtn){
			break;
		}
	}

	int repeatingrange = -1;
	for(int i=0;i<sqrnt)

}