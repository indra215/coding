string Solution::countAndSay(int n) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	string result;
	if(n == 1){
		result = "1";
		return result;
	}

	if(n == 2){
		result = "11";
		return result;
	}

	string prev = "11";
	for(int i=3;i<=n;i++){
		string curr;
		int j=1, count=1;
		while(j < prev.length()){
			if(prev[j] == prev[j-1])
				count++;
			else{
				curr += to_string(count) + prev[j-1];
				count = 1;
			}
			j++;
		}
		curr += to_string(count) + prev[j-1];
		prev = curr;
	}
	return prev;
}