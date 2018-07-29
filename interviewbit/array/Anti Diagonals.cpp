vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {

	if(A.empty())
		return A;

	int n = A.size();
	vector<vector<int>> anti;
	if(n == 1){
		vector<int> v(n);
		anti.push_back(v);
		anti[0][0] = A[0][0];
		return anti;
	}
	
	int a,b,index=0,k;
	for(int i=0;i<n;i++){
		a = 0;
		b = i;
		vector<int> v(b+1);
		anti.push_back(v);
		k = 0;
		while(b >= 0){
			anti[index][k] = A[a][b];
			a++;
			b--;
			k++;
		}
		index += 1;
	}

	for(int i=1;i<n;i++){
		a = i;
		b = n-1;
		vector<int> v(n-i);
		anti.push_back(v);
		k = 0;
		while(k < n-i){
			anti[index][k] = A[a][b];
			a++;
			b--;
			k++;
		}
		index += 1;
	}
	return anti;
}
