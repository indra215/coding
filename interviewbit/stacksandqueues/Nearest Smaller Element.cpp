vector<int> Solution::prevSmaller(vector<int> &A) {

	if(A.empty())
		return A;

	vector<int> smaller(A.size());
	smaller[0] = -1;
	stack<int> elem;
	elem.push(A[0]);

	for(int i=1;i<A.size();i++){
		while(1){
			if(elem.empty()){
				smaller[i] = -1;
				elem.push(A[i]);
				break;
			}
			if(elem.top() < A[i]){
				smaller[i] = elem.top();
				elem.push(A[i]);
				break;
			}else{
				elem.pop();
			}
		}
	}

	return smaller;
}