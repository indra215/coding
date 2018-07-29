int maxAreaHist(vector<int> hist) {
	stack<int> result;
	int i = 0, n = hist.size(), tp, area, max_area = 0;


	while(i < n){
		if(result.empty() || hist[i] >= hist[result.top()]){
			result.push(i);
			i++;
		}else{
			tp = result.top();
			result.pop();
			area = hist[tp]*(result.empty() ? i : (i - result.top() - 1));
			max_area = max(max_area, area);
		}
	}

	while(!result.empty()){
		tp = result.top();
		result.pop();
		area = hist[tp]*(result.empty() ? i : (i - result.top() - 1));
		max_area = max(max_area, area);
	}

	return max_area;
}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(A.empty()){
		return 0;
	}

	// use the largest rectangle histogram as subroutine
	int result = maxAreaHist(A[0]);
	int m = A.size(), n = A[0].size();

	for(int i=1;i<m;i++){
		for(int j=0;j<n;j++){
			if(A[i][j] == 1){
				A[i][j] += A[i-1][j];
			}
		}
		result = max(result, maxAreaHist(A[i]));
	}

	return result;
}