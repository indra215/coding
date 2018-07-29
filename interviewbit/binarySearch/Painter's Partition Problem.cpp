bool isPossible(int K, int T, vector<int>& C, long long time){
	int curr_painter = 1;
	long long curr_time = 0;
	for(int i=0;i<C.size();){
		if(curr_time + ((long long)T)*C[i] > time){
			curr_painter += 1;
			curr_time = 0;
			if(curr_painter > K)
				return false;
		}else{
			curr_time += ((long long)T)*C[i];
			i++;
		}
	}

	return true;
}

int Solution::paint(int K, int T, vector<int> &C) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	long long start_time = 0, end_time = 0;
	for(int i=0;i<C.size();i++){
		end_time += ((long long)T)*C[i];
	}

	int ans;
	while(start_time <= end_time){
		long long mid = start_time + (end_time - start_time)/2;
		if(isPossible(K, T, C, mid)){
			end_time = mid - 1;
			ans = mid%10000003;
		}
		else start_time = mid + 1;
	}
	return ans;
}