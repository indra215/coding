unsigned int Solution::reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	vector<int> bits(32,0);
	int i = 31,j;
	while(A > 1){
		bits[i] = A%2;
		A /= 2;
		i--;
	}
	bits[i] = A;
	i = 0,j=31;
	A = 0;
	while(i < j){
		if(bits[i] != bits[j]){
			bits[i] = bits[i] ^ 1;
			bits[j] = bits[j] ^ 1;
		}
		A += (bits[i]*pow(2,31-i) + bits[j]*pow(2,31-j));
		i++;
		j--;
	}
	return A;
}