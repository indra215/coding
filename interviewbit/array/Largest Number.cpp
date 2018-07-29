static bool mycompare(int a, int b){
	string a1 = to_string(a) + to_string(b);
	string b1 = to_string(b) + to_string(a);

	return (a1 > b1);
}

string Solution::largestNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	int n = A.size();
	if(n == 0)
		return string();
	if(n == 1)
		return to_string(A[0]);

	// sort the array based on the largest number upon concatenation
	sort(A.begin(), A.end(), mycompare);

	string result;
	for(int i=0;i<n;i++){
		result += to_string(A[i]);
	}
	return result;
}
