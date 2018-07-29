vector<vector<int> > Solution::generate(int n) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(n == 0)
		return vector<vector<int>>();

	vector<vector<int>> pascal;
	if(n == 1){
		vector<int> v(n);
		pascal.push_back(v);
		pascal[0][0] = 1;
		return pascal;
	}

	vector<int> v(1);
	pascal.push_back(v);
	pascal[0][0] = 1;
	for(int i=1;i<n;i++){
		vector<int> v(i+1);
		pascal.push_back(v);
		pascal[i][0] = 1;
		pascal[i][i] = 1;
		for(int j=1;j<i;j++){
			pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
		}
	}

	return pascal;
}
