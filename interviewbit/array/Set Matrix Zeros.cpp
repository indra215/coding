void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(A.empty())
		return;
	int m = A.size(),n = A[0].size();
	bool rowflag = false,colflag = false;
	
	// check whether first row has 0
	for(int i=0;i<n;i++){
		if(A[0][i] == 0){
			rowflag = true;
			break;
		}
	}

	// check whether first col has 0
	for(int i=0;i<m;i++){
		if(A[i][0] == 0){
			colflag = true;
			break;
		}
	}

	// use the first row and first col as auxilary arrays to store the locations 
	// with 0
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			if(A[i][j] == 0){
				A[0][j] = 0;
				A[i][0] = 0;
			}
		}
	}

	for(int i=1;i<m;i++){
		if(A[i][0] == 0){
			for(int j=1;j<n;j++){
				A[i][j] = 0;
			}
		}
	}

	for(int i=1;i<n;i++){
		if(A[0][i] == 0){
			for(int j=1;j<m;j++){
				A[j][i] = 0;
			}
		}
	}	

	if(rowflag){
		for(int i=0;i<n;i++){
			A[0][i] = 0;
		}
	}
	if(colflag){
		for(int i=0;i<m;i++){
			A[i][0] = 0;
		}
	}
}