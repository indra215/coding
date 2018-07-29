int Solution::maximumGap(const vector<int> &nums) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	int n = nums.size();
	if(n == 0 || n < 2)
		return 0;
	
	int minVal = *min_element(nums.begin(), nums.end());
	int maxVal = *max_element(nums.begin(), nums.end());

	// average gap 
	int gap = (maxVal - minVal - 1)/(n-1) + 1;

	// number of buckets = n-1
	vector<int> bucketMin(n-1, INT_MAX);
	vector<int> bucketMax(n-1, INT_MIN);

	// fill the buckets
	for(int i=0;i<n;i++){
		if(nums[i] != maxVal){
			int bind = (nums[i] - minVal)/gap;
			bucketMin[bind] = min(bucketMin[bind], nums[i]);
			bucketMax[bind] = max(bucketMax[bind], nums[i]);
		}
	}

	// compute max gap
	int max_gap = INT_MIN;
	int prev = minVal;
	for(int i=0;i<n-1;i++){
		if(bucketMax[i] == INT_MIN && bucketMin[i] == INT_MAX)
			continue;	// empty bucket
		max_gap = max(max_gap, bucketMin[i]-prev);
		prev = bucketMax[i];
	}
	max_gap = max(max_gap, maxVal-prev);
	return max_gap;
}
