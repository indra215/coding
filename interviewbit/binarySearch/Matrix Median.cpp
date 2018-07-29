int Solution::findMedian(vector<vector<int> > &A) {
	int N = A.size(),M = A[0].size();

	// find min and max elements in the matrix
	int min_elem = INT_MAX,max_elem = INT_MIN;

	// for minimum element compare first element in each row
	// for maximum element compare last element in each row
	for(int i=0;i<N;i++){
		min_elem = min(min_elem, A[i][0]);
		max_elem = max(max_elem, A[i][M-1]);
	}

	// find the count of each number in the range [min_elem,max_elem]
	int req = (N*M+1)/2;
	while(min_elem < max_elem){
		int mid = min_elem + (max_elem - min_elem)/2;
		int num = 0;
		for(int i=0;i<N;i++){
			num += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
		}
		if(num < req)
			min_elem = mid+1;
		else max_elem = mid;
	}
	return min_elem;
}