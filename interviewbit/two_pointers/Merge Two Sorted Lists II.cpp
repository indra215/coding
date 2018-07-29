void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	
	// if B is empty then return
	if(B.empty())
		return;
	// if A is empty then copy B into A
	if(A.empty()){
		for(int i=0;i<B.size();i++){
			A.push_back(B[i]);
		}
		return;
	}
	int i = 0,j = 0;
	while(i < A.size() && j < B.size()){
		if(A[i] <= B[j]){
			i++;
		}else{
			A.insert(A.begin()+i,1,B[j]);
			j++;
			i++;
		}
	}
	while(j < B.size()){
		A.push_back(B[j]);
		j++;
	}
}