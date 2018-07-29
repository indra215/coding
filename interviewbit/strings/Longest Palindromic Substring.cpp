string Solution::longestPalindrome(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(A.empty())
		return A;
	int n = A.length();
	if(n == 1)
		return A;

	vector<vector<bool>> table;
	for(int i=0;i<n;i++){
		vector<bool> v(n,false);
		table.push_back(v);
	}

	// for gap = 1
	int maxlength = 1,start = -1;
	for(int i=0;i<n;i++){
		table[i][i] = true;
		start = (start == -1) ? i : start;
	}

	// for gap = 2
	for(int i=0;i<n-1;i++){
		if(A[i] == A[i+1]){
			table[i][i+1] = true;
			if(maxlength < 2){
				start = i;
				maxlength = 2;
			}else if(maxlength == 2){
				start = min(start, i);
			}
		}
	}

	// for gap >= 3
	for(int gap=3;gap<=n;gap++){
		for(int l=0,h=gap-1;h < n;l++,h++){
			if(table[l+1][h-1] && A[l] == A[h]){
				table[l][h] = true;
				if(maxlength < gap){
					start = l;
					maxlength = max(maxlength, gap);
				}else if(maxlength == gap){
					start = min(start, l);
				}
			}
		}
	}
	return A.substr(start, maxlength);
}