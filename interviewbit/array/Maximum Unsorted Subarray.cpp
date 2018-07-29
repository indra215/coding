vector<int> Solution::subUnsort(vector<int> &A) {
	int n = A.size();
	int s=-1,e=-1;
	for(int i=0;i<n-1;i++){
		if(A[i] > A[i+1]){
			s = i;
			break;
		}
	}

	for(int i=n-1;i>0;i--){
		if(A[i] < A[i-1]){
			e = i;
			break;
		}
	}

	vector<int> result;
	if(s == -1 || e == -1){
		result.push_back(-1);
		return result;
	}

	int min_elem=INT_MAX,max_elem=INT_MIN;
	for(int i=s;i<=e;i++){
		min_elem = min(min_elem, A[i]);
		max_elem = max(max_elem, A[i]);
	}

	cout << s << " " << e << "\n";

	for(int i=0;i<s;i++){
		if(A[i] > min_elem){
			s = i;
			break;
		}
	}

	for(int i=e+1;i<n;i++){
		if(A[i] < max_elem){
			e = i;
		}
	}

	result.push_back(s);
	result.push_back(e);
	return result;
}