int Solution::searchMatrix(vector<vector<int> > &A, int target) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if(A.empty())
		return 0;

	int n = A.size(), m = A[0].size(), row;
	for(row=0;row<n;row++){
		if(A[row][0] > target)
			break;
	}
	// first element is itself greater than target -> return 0
	if(row == 0)
		return 0;
	row -= 1;
	// binary search in this row
	int start = 0,end = m-1,mid;
	while(start <= end){
		mid = start + (end - start)/2;
		if(A[row][mid] == target)
			return 1;
		else if(A[row][mid] < target)
			start = mid + 1;
		else end = mid - 1;
	}
	return 0;
}
