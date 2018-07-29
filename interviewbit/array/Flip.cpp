vector<int> Solution::flip(string A) {
	int n = A.length();
	if(n == 0)
		return vector<int>();

	// replace 1 with -1
	vector<int> nums(n,0);
	int count = 0;
	for(int i=0;i<n;i++){
		if(A[i] == '1'){
			nums[i] = -1;
			count += 1;
		}
	}

	// kadene's algorithm 
	int left = 0, right = 0, curr_max = nums[0], max_sum = nums[0];
	for(int i=1;i<n;i++){
		if(curr_max+nums[i] > nums[i]){
			curr_max = curr_max + nums[i];
			if(max_sum < curr_max){
				right = i;
				max_sum = curr_max;
			}
		}
		else if(curr_max+nums[i] < nums[i]){
			curr_max = nums[i];
			if(max_sum < curr_max){
				left = i;
				right = i;
				max_sum = curr_max;
			}
		}
	}

	cout << left << " " << right << endl;

	int cnt = 0;
	for(int i=0;i<n;i++){
		if(i >= left && i <= right){
			nums[i] = -1;
		}
		cnt += (nums[i] == -1) ? 1 : 0;
	}

	if(cnt <= count){
		return vector<int>();
	}

	vector<int>result;
	result.push_back(left+1);
	result.push_back(right+1);

	return result;
}
