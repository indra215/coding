string addString(string prev, string curr, int count){
	string result;
	int i = prev.length()-count-1, j = curr.length()-1;
	while(count > 0){
		result.append(1, prev[prev.length()-count]);
		count--;
	}
	
	int carry = 0, sum;
	while(i >= 0 && j >= 0){
		sum = (prev[i]-'0') + (curr[j]-'0') + carry;
		carry = sum/10;
		sum = sum%10;
		result.insert(0,1,(sum+'0'));
		i--;
		j--;
	}
	while(i >= 0){
		sum = (prev[i]-'0') + carry;
		carry = sum/10;
		sum = sum%10;
		result.insert(0,1,(sum+'0'));
		i--;
	}
	while(j >= 0){
		sum = (curr[j]-'0') + carry;
		carry = sum/10;
		sum = sum%10;
		result.insert(0,1,(sum+'0'));
		j--;
	}
	if(carry > 0){
		result.insert(0,1,(carry+'0'));
	}
	return result;
}


string Solution::multiply(string A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	int n = A.length();
	int num, carry, count = 1;
	string prev;
	for(int i=n-1;i>=0;i--){
		string curr;
		carry = 0;
		for(int j=B.length()-1;j>=0;j--){
			num = (A[i]-'0')*(B[j]-'0') + carry;
			carry = num/10;
			num = num%10;
			curr.insert(0,1,(num+'0'));
		}
		if(carry > 0)
			curr.insert(0,1,(carry+'0'));
		// cout << curr << endl;
		if(prev.empty())
			prev = curr;
		else{
			prev = addString(prev, curr, count);
			count++;
		}
	}
	int i = 0;
	while(i != prev.length()-1 && prev[i] == '0'){
		prev.erase(0,1);
	}
	return prev;
}