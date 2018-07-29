vector<int> Solution::getRow(int n) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	vector<int> v(n+1);
	if(n == 0){
		v[0] = 1;
		return v;
	}
	if(n == 1){
		v[0] = 1;
		v[1] = 1;
		return v;
	}
	for(int i=0;i<=n/2;i++){
		if(i == 0){
			v[i] = 1;
			v[n-i] = 1;
		}
		else if(i == 1){
			v[i] = n;
			v[n-i] = n;
		}
		else{
			v[i] = (v[i-1]*(n-i+1))/i;
			v[n-i] = v[i];
		}
	}
	return v;
}
