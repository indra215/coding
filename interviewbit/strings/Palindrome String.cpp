int Solution::isPalindrome(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(A.empty())
		return 1;
	int n = A.length();
	int i=0,j=n-1;
	while(i <= j){
		if(!isalnum(A[i])){
			i++;
			continue;
		}
		if(!isalnum(A[j])){
			j--;
			continue;
		}
		if(char(tolower(A[i])) != char(tolower(A[j])))
			return 0;
		else{
			i++;
			j--;
		}
	}
	return 1;
}