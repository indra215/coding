vector<int> Solution::maxset(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	int n = A.size();
	if(n == 0){
		return vector<int>();
	}

	if(n == 1){
		if(A[n-1] >= 0)
			return A;
		else return vector<int>();
	}

	int max_s=-1,max_e=-1,i=0,st,ed;
	long long max_sum=INT_MIN, sum;
	while(i < n){
		while(i < n){
			if(A[i] >= 0){
				st = i;
				break;
			}else{
				i++;
			}
		}
		if(i >= n)
			break;
		sum = 0;
		ed = st;
		while(ed < n){
			if(A[ed] >= 0){
				sum += (long long)A[ed];
				ed++;
			}else{
				if(max_sum < sum){
					max_sum = sum;
					max_e = ed-1;
					max_s = st;
					sum = 0;
					i = ed+1;
				}
				else if(max_sum == sum){
					if((max_e-max_s+1) < (ed-st)){
						max_e = ed-1;
						max_s = st;
						sum = 0;
						i = ed+1;
					}
				}
				break;
			}
		}
		if(ed == n){
			if(max_sum < sum){
				max_sum = sum;
				max_e = ed-1;
				max_s = st;
				sum = 0;
				i = ed+1;
			}
			else if(max_sum == sum){
				if((max_e-max_s+1) < (ed-st)){
					max_e = ed-1;
					max_s = st;
					sum = 0;
					i = ed+1;
				}
			}
			break;
		}else{
			i = ed+1;
		}
	}

	if(max_s == -1 || max_e == -1)
		return vector<int>();
	vector<int> result;
	for(int i=max_s;i<=max_e;i++){
		result.push_back(A[i]);
	}
	return result;
}
