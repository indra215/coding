vector<vector<int> > Solution::threeSum(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if(A.size() < 3)
		return vector<vector<int>>();

	sort(A.begin(), A.end());
	int i=0,j,k;
	vector<vector<int>> result;
	vector<vector<int>>::iterator it;
	for(int i=0;i<=A.size()-3;i++){
		j = i+1;
		k = A.size()-1;
		while(j < k){
			if(A[i]+A[j]+A[k] == 0){
				vector<int> v;
				v.push_back(A[i]);
				v.push_back(A[j]);
				v.push_back(A[k]);
				it = find(result.begin(),result.end(),v);
				if(it == result.end())
					result.push_back(v);
				j++;
				k--;
			}else if(A[i]+A[j]+A[k] < 0){
				j++;
			}else{
				k--;
			}
		}
	}
	return result;
}	