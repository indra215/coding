int Solution::firstMissingPositive(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(A.empty())
		return 1;
	if(A.size() == 1){
		if(A[0] <= 0)
			return 1;
		else
			return A[0] == 1? 2 : 1;
	}

	// move all non-positive (including 0) to left side
	int j = 0,temp;
	for(int i=0;i<A.size();i++){
		if(A[i] <= 0){
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			j++;
		}
	}

	A.erase(A.begin(), A.begin()+j);
	for(int i=0;i<A.size();i++){
		if(abs(A[i])-1 < A.size() && A[abs(A[i])-1] > 0){
			A[abs(A[i])-1] = -A[abs(A[i])-1];
		}
	}

	for(int i=0;i<A.size();i++){
		if(A[i] > 0)
			return i+1;
	}

	return A.size()+1;

}