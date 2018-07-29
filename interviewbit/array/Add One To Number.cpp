vector<int> Solution::plusOne(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	int i = 0;
	while(i < A.size()){
		if(A[i] == 0){
			A.erase(A.begin());
		}else{
			break;
		}
	}
	
	int n = A.size();
	if(n == 0){
		A.push_back(1);
		return A;
	}

	int sum, carry=0;
	sum = A[n-1] + 1;
	if(sum > 9){
		carry = sum/10;
		sum = sum%10;
	}
	A[n-1] = sum;

	for(int i=n-2;i>=0;i--){
		sum = A[i] + carry;
		carry = sum/10;
		sum = sum%10;
		A[i] = sum;
	}

	if(carry > 0){
		A.insert(A.begin(), carry);
	}

	return A;
}
