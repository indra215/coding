vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
	vector<int> result;
	// DO STUFF HERE AND POPULATE result
	int m = A.size(), n = A[0].size();
	int l=0,r=n,t=0,b=m;
	while(l < r && t < b){
		if(l < r){
			for(int i=l;i<r;i++)
				result.push_back(A[t][i]);
		}
		t++;
		if(t < b){
			for(int j=t;j<b;j++)
				result.push_back(A[j][r-1]);
		}
		r--;
		if(b > t){
			for(int i=r-1;i>=l;i--)
				result.push_back(A[b-1][i]);
		}
		b--;
		if(r > l){
			for(int j=b-1;j>=t;j--)
				result.push_back(A[j][l]);
		}
		l++;
	}


	return result;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
