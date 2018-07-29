void combineUtil(int n, int k, int start, vector<int>& v, 
							vector<vector<int>>& combinations) {
	if(v.size() == k){
		combinations.push_back(v);
		return;
	}
	for(int i=start;i<=n;i++){
		v.push_back(i);
		combineUtil(n, k, i+1, v, combinations);
		v.pop_back();
	}
}

vector<vector<int> > Solution::combine(int n, int k) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	vector<int> v;
	vector<vector<int>> combinations;
	combineUtil(n, k, 1, v, combinations);

	return combinations;
}
