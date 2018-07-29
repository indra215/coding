bool checkSame(vector<vector<int>> answer, vector<int> v2){

	vector<int> v1;
	bool flag = false;

	for(int i=0;i<answer.size();i++){
		v1 = answer[i];
		if(v1.size() != v2.size()){
			flag = false;
			continue;
		}

		int j;
		for(j=0;j<v1.size();j++){
			if(v1[j] != v2[j])
				break;
		}

		if(j == v1.size())
			return true;
		else flag = false;
	}
	
	return flag;
}

void combinationSumUtil(vector<int> &C, int T, int start, vector<int>& v,
										vector<vector<int>>& result){
	if(T < 0){
		return;
	}
	if(T == 0){
		if(result.empty()){
			result.push_back(v);
		}
		else{
			if(checkSame(result, v)){
				return;
			}
			else{
				result.push_back(v);
			}
		}
		return;
	}
	for(int i=start;i<C.size();i++){
		v.push_back(C[i]);
		combinationSumUtil(C, T-C[i], i+1, v, result);
		v.pop_back();
	}
}

vector<vector<int> > Solution::combinationSum(vector<int> &C, int T) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(C.empty()){
		return vector<vector<int>>();
	}

	vector<int> v;
	vector<vector<int>> result;
	sort(C.begin(), C.end());
	combinationSumUtil(C, T, 0, v, result);

	return result;
}