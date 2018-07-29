vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if(A.empty() || B.empty())
		return vector<int>();

	int nA = A.size(),nB = B.size();
	int i = 0,j = 0;
	vector<int> result;
	while(i < nA && j < nB){
		if(A[i] == B[j]){
			result.push_back(A[i]);
			i++;
			j++;
		}else if(A[i] < B[j]){
			i++;
		}else{
			j++;
		}
	}
	return result;
}