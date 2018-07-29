int Solution::largestRectangleArea(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(A.empty())
		return 0;

	stack<int> values;
	int i = 0, tp, area, maxArea = INT_MIN;

	while(i < A.size()){
		if(values.empty() || (A[values.top()] <= A[i])){
			values.push(i);
			i++;
		}else{
			tp = values.top();
			values.pop();
			if(values.empty()){
				area = A[tp]*i;
			}else{
				area = A[tp]*(i-values.top()-1);
			}
			maxArea = max(maxArea, area);
		}
	}

	while(!values.empty()){
		tp = values.top();
		values.pop();
		if(values.empty()){
			area = A[tp]*i;
		}else{
			area = A[tp]*(i-values.top()-1);
		}
		maxArea = max(maxArea, area);
	}

	return maxArea;
}