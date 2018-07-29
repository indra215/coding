vector<int> Solution::wave(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	sort(A.begin(), A.end());
	int i=0,n = A.size();
	vector<int> wav;
	int count = 1;
	while(i < n-1){
		wav.push_back(A[i+1]);
		wav.push_back(A[i]);
		i += 2;
		count += 1;
	}
	if(i == n-1)
		wav.push_back(A[i]);

	return wav;
}
