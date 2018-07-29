int Solution::calculateMinimumHP(vector<vector<int> > &dungeon) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(dungeon.empty()){
		return 0;
	}

	int m = dungeon.size(), n = dungeon[0].size();
	vector<vector<int>> minHP;
	for(int i=0;i<m;i++){
		vector<int> v(n);
		minHP.push_back(v);
	}

	minHP[m-1][n-1] = max(1-dungeon[m-1][n-1], 1);
	// for the walls
	for(int i=m-2;i>=0;i--){
		minHP[i][n-1] = max(minHP[i+1][n-1]-dungeon[i][n-1], 1);
	}

	for(int i=n-2;i>=0;i--){
		minHP[m-1][i] = max(minHP[m-1][i+1]-dungeon[m-1][i], 1);
	}

	for(int i=m-2;i>=0;i--){
		for(int j=n-2;j>=0;j--){
			minHP[i][j] = min(minHP[i][j+1], minHP[i+1][j]) - dungeon[i][j];
			minHP[i][j] = (minHP[i][j] <= 0) ? 1 : minHP[i][j];
		}
	}

	return minHP[0][0];
}