string Solution::longestCommonPrefix(vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(A.empty())
		return string();

	int minlen = INT_MAX, minind;
	for(int i=0;i<A.size();i++){
		if(A[i].length() < minlen){
			minind = i;
			minlen = A[i].length();
		}
	}

	int i;
	for(i=0;i<A[minind].length();i++){
		char ch = A[minind][i];
		for(int j=0;j<A.size();j++){
			if(j == minind)
				continue;
			if(A[j][i] != ch){
				return A[minind].substr(0,i);
			}
		}
	}

	return A[minind].substr(0, i);
}