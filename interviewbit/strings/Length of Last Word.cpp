int Solution::lengthOfLastWord(const string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(A.empty())
		return 0;
	int n = A.length();
	int count=0,lastwordCount;
	char prev;
	for(int i=0;i<n;i++){
		if(isalpha(A[i])){
			count++;
			prev = A[i];
		}
		else{
			if(prev != ' '){
				lastwordCount = count;
				count = 0;
				prev = ' ';
			}
		}
	}
	if(count != 0)
		lastwordCount = count;
	return lastwordCount;
}