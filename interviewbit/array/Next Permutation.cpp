void Solution::nextPermutation(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	int n = A.size();

	// find the last index i s.t A[i] < A[i+1]
	int first = -1;
	for(int i=n-2;i>=0;i--){
		if(A[i] < A[i+1]){
			first = i;
			break;
		}
	}

	// if first == -1 then the array is sorted and
	// it's the last permutation
	if(first == -1){
		// sort the array
		int i=0,j=n-1;
		int temp;
		while(i < j){
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			i++;
			j--;
		}
		return;
	}

	// find the last index j after first s.t A[first] < A[j]
	int second = -1;
	for(int j=n-1;j>first;j--){
		if(A[first] < A[j]){
			second = j;
			break;
		}
	}

	// swap A[first] and A[second]
	int temp = A[first];
	A[first] = A[second];
	A[second] = temp;

	// reverse the array from first+1 to n-1
	first = first + 1;
	int last = n-1;
	while(first < last){
		temp = A[first];
		A[first] = A[last];
		A[last] = temp;
		first++;
		last--;
	}
}
