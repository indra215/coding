bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {

	if(K == 0)
		return false;
	
	int n = arrive.size();
	vector<pair<int,int>> times;
	for(int i=0;i<n;i++){
		times.push_back(make_pair(arrive[i],1));
		times.push_back(make_pair(depart[i],0));
	}

	sort(times.begin(), times.end());
	int curr = 0,max_rooms = 0;
	for(int i=0;i<times.size();i++){
		if(times[i].second == 1){
			curr += 1;
			max_rooms = max(max_rooms, curr);
		}else{
			curr -= 1;
		}
	}

	if(max_rooms > K)
		return false;
	return true;
}