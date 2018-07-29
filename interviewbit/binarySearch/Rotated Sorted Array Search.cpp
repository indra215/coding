int findElement(const vector<int> &A, int l, int r, int target) {
	int mid;
	while(l <= r){
		mid = l + (r - l)/2;
		if(A[mid] == target)
			return mid;
		if(A[mid] < target)
			l = mid+1;
		else r = mid-1;
	}
	return -1;
}

int findPivot(const vector<int> &A, int l, int r, int target) {
	int mid;
	while(l <= r){
		mid = l + (r - l)/2;
		if(mid > l && A[mid-1] > A[mid])
			return mid-1;
		if(mid < r && A[mid] > A[mid+1])
			return mid;
		if(A[l] < A[mid])
			l = mid+1;
		else r =mid-1;
	}
	return -1;
}

int Solution::search(const vector<int> &A, int target) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if(A.empty())
		return -1;

	int n = A.size();

	// find pivot where the array is rotated
	int pivot = findPivot(A, 0, n-1, target);
	if(pivot == -1)
		return findElement(A, 0, n-1, target);

	if(A[pivot] == target)
		return pivot;

	if(A[0] < target)
		return findElement(A, 0, pivot-1, target);
	return findElement(A, pivot+1, n-1, target);
}