int getLeft(const vector<int> &A, int l, int r, int target) {
	int mid;
	while(l <= r){
		mid = l + (r - l)/2;
		if((mid == 0 || A[mid-1] < target) && A[mid] == target)
			return mid;
		else if(A[mid] < target)
			l = mid+1;
		else r = mid-1;
	}
	return -1;
}

int getRight(const vector<int> &A, int l, int r, int target){
	int mid;
	while(l <= r){
		mid = l + (r - l)/2;
		if((mid == r || A[mid+1] > target) && A[mid] == target)
			return mid;
		else if(A[mid] > target)
			r = mid-1;
		else l = mid+1;
	}
	return -1;
}

vector<int> Solution::searchRange(const vector<int> &A, int target) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	vector<int> result;
	if(A.empty()){
		result.push_back(-1);
		result.push_back(-1);
		return result;
	}

	int n = A.size();
	int left = getLeft(A, 0, n-1, target);
	if(left == -1){
		result.push_back(-1);
		result.push_back(-1);
		return result;
	}
	int right = getRight(A, left, n-1, target);
	result.push_back(left);
	result.push_back(right);
	return result;
}