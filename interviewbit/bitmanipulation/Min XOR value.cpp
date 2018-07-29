int Solution::findMinXor(vector<int> &A) {
	// sort the array
	sort(A.begin(), A.end());

	int minXor = INT_MAX;
	for(int i=1;i<A.size();i++){
		minXor = min(minXor, (A[i-1]^A[i]));
	}
	return minXor;
}