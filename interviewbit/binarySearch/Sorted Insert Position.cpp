int Solution::searchInsert(vector<int> &A, int target) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(A.empty())
		return 0;
	int n = A.size();
	int start = 0, end = n-1, mid;
	while(start <= end){
		if(A[start] > target)
			return start;
		if(A[end] < target)
			return end+1;
		mid = start + (end - start)/2;
		if(A[mid] == target)
			return mid;
		else if(A[mid] < target){
			if(mid+1 <= end && A[mid+1] > target)
				return mid+1;
			start = mid+1;
		}
		else{
			if(mid-1 >= start && A[mid-1] < target)
				return mid;
			end = mid-1;
		}
	}
	return start;
}