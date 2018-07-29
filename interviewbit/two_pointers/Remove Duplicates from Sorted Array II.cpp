int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	
	if(A.empty())
		return 0;
	int i = 0,j = 0,count = 0,key = A[0];
	while(i < A.size()){
		if(A[i] == key){
			count++;
			A[j] = A[i];
			i++;
			j++;
			if(count >= 2){
				while(A[i] == key)
					i++;
			}
		}else{
			count = 0;
			key = A[i];
		}
	}
	return j;
}