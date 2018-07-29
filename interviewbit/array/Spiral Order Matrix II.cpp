vector<vector<int> > Solution::generateMatrix(int n) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	vector<vector<int>> spiral;
	for(int i=0;i<n;i++){
		vector<int> v(n);
		spiral.push_back(v);
	}

	if(n == 1){
		spiral[0][0] = 1;
		return spiral;
	}

	int l=0,r=n-1,t=0,b=n-1,num=1;
	while(l <= r && t <= b){
		for(int i=l;i<=r;i++){
			spiral[t][i] = num;
			num += 1;
		}
		t++;

		for(int i=t;i<=b;i++){
			spiral[i][r] = num;
			num += 1;
		}
		r--;
		if(t < b){
			for(int i=r;i>=l;i--){
				spiral[b][i] = num;
				num += 1;
			}
			b--;
		}
		if(l < r){
			for(int i=b;i>=t;i--){
				spiral[i][l] = num;
				num += 1;
			}
			l++;
		}
	}

	return spiral;
}
