int Solution::isScramble(const string A, const string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(A.length() != B.length()){
		return 0;
	}

	if(A == B){
		return 1;
	}

	int len = A.length();
	vector<vector<vector<int>>> scramble;
	for(int i=0;i<len;i++){
		vector<vector<int>> v1;
		for(int i=0;i<len;i++){
			vector<int> v(len, 0);
			v1.push_back(v);
		}
		scramble.push_back(v1);
	}

	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++){
			scramble[0][i][j] = (A[i] == B[j]);
		}
	}

	for(int l=2;l<=len;l++){
		for(int i=0;i<=len-l;i++){
			for(int j=0;j<=len-l;j++){
				bool r = false;
				for(int k=1;k<l && r==false;k++){
					r = (scramble[k-1][i][j] && scramble[l-k-1][i+k][j+k])
							|| (scramble[k-1][i][j+l-k] && scramble[l-k-1][i+k][j]);
				}
				scramble[l-1][i][j] = r;
			}
		}
	}

	return scramble[len-1][0][0];
}