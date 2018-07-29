void Solution::reverseWords(string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if(A.empty())
		return;

	// get the start index by removing leading spaces
	int start=0;
	while(start < A.length()){
		if(A[start] == ' ')
			start++;
		else break;
	}

	// get the end index by removing trailing spaces
	int end = A.length()-1;
	while(end >= 0){
		if(A[end] == ' ')
			end--;
		else break;
	}

	// take the substring by removing leading and trailing spaces
	A = A.substr(start, end-start+1);
	size_t first = 0, last = 0, next = 0;
	int count;
	while((next = A.find(' ', last)) != string::npos){
		// reverse string from first to last
		reverse(A.begin()+first, A.begin()+next);
		last = next + 1;

		// remove extra spaces
		count = 0;
		while(A[last] == ' '){
			count++;
			last++;
		}
		if(count > 0){
			A.erase(next+1, count);
		}
		first = next+1;
		last = first;
	}

	// reverse the last word
	reverse(A.begin()+last, A.end());
	
	// reverse the entire string
	reverse(A.begin(), A.end());
}