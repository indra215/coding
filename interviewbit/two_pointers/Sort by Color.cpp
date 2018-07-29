void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	
	if(A.empty())
		return;
	int i = 0,j = 0,end = A.size()-1;
	while(i <= end){
		if(A[i] == 0){
			swap(A[i], A[j]);
			i++;
			j++;
		}else if(A[i] == 1){
			i++;
		}else{
			swap(A[i],A[end]);
			end--;
		}
	}
}