void Solution::rotate(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	int N = A.size();
	for(int x=0;x<N/2;x++){
		for(int y=x;y<N-x-1;y++){
			int temp = A[x][y];
			
			// left to top
			A[x][y] = A[N-y-1][x];

			// bottom to left
			A[N-y-1][x] = A[N-x-1][N-y-1];

			// right to bottom
			A[N-x-1][N-y-1] = A[y][N-x-1];

			// top to right
			A[y][N-x-1] = temp;
		}
	}
}
