vector<int> Solution::findPerm(const string s, int B) {

	if(s.length() == 0){
		return vector<int>();
	}
	vector<int> result;
	if(s.length() == 1){
		result.push_back(B);
		return result;
	}

	int max_num = B, min_num = 1;
	for(int i=0;i<s.length();i++){
		if(s[i] == 'I'){
			result.push_back(min_num);
			min_num++;
		}
		else if(s[i] == 'D'){
			result.push_back(max_num);
			max_num--;
		}
	}
	result.push_back(min_num);
	return result;
}