int Solution::threeSumClosest(vector<int> &A, int target) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	sort(A.begin(),A.end());
	int j,k,minsum,finalsum,sum;
	minsum = INT_MAX;
	for(int i=0;i<A.size()-2;i++){
		j = i+1;
		k = A.size()-1;
		while(j < k){
			sum = A[i]+A[j]+A[k];
			if(sum == target)
				return target;
			else if(sum < target)
				j++;
			else k--;
			if(minsum > abs(target-sum)){
				minsum = abs(target-sum);
				finalsum = sum;
			}
		}
	}
	return finalsum;
}