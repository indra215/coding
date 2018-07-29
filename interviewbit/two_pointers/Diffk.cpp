int Solution::diffPossible(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if(A.empty())
		return 0;
	int i = 0,j = 1;
	while(i < A.size() && j < A.size()){
		if(i != j && (A[j]-A[i] == B))
			return 1;
		else if(A[j]-A[i] < B)
			j++;
		else i++;
	}
	return 0;
}