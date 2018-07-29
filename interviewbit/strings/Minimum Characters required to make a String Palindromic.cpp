int Solution::solve(string A) {
	if(A.empty())
		return 0;
	
	int n = A.size();
	vector<vector<int>> table;
	for(int i=0;i<n;i++){
		vector<int> v(n,0);
		table.push_back(v);
	}

	for(int gap=1;gap<n;gap++){
		for(int l=0,h=gap;h<n;l++,h++){
			table[l][h] = (A[l]==A[h]) ? table[l+1][h-1] 
											: min(table[l+1][h],table[l][h-1])+1;
		}
	}
	return table[0][n-1];
}