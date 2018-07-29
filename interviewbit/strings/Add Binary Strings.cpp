string Solution::addBinary(string A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(A.empty())
		return B;
	if(B.empty())
		return A;
	string result;
	int i=A.length()-1, j=B.length()-1;
	int carry = 0,sum;
	while(i >= 0 && j >= 0){
		sum = (A[i]-'0') + (B[j]-'0') + carry;
		carry = sum/2;
		sum = sum%2;
		cout << carry << "\t" << sum << endl;
		cout << "in\n";
		result.insert(0,1,(sum+'0'));
		i--;
		j--;
	}

	while(i >= 0){
		sum = (A[i]-'0') + carry;
		carry = sum/2;
		sum = sum%2;
		result.insert(0,1,(sum+'0'));
		i--;
	}
	while(j >= 0){
		sum += (B[j]-'0') + carry;
		carry = sum/2;
		sum = sum%2;
		result.insert(0,1,(sum+'0'));
		j--;
	}
	if(carry > 0){
		result.insert(0,1,(carry+'0'));
	}
	return result;
}