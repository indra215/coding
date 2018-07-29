int Solution::maxArr(vector<int> &A) {
	// construct two auxillary arrays 
	// A[i] + i and A[i] - i

	// A[i] + i
	vector<int> A1,A2;
	int min1,max1,min2,max2;
	min1 = min2 = INT_MAX;
	max1 = max2 = INT_MIN;
	for(int i=0;i<A.size();i++){
		min1 = min(min1, A[i]+i);
		max1 = max(max1, A[i]+i);

		min2 = min(min2, A[i]-i);
		max2 = max(max2, A[i]-i);
	}

	return max((max1 - min1),(max2 - min2));

}
