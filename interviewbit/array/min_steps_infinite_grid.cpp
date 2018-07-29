// Input : X and Y co-ordinates of the points in order. 
// Each point is represented by (X[i], Y[i])
int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
	int n = X.size();
	int mindis = 0;
	for(int i=0;i<n-1;i++){
		mindis += max(abs(X[i+1]-X[i]), abs(Y[i+1]-Y[i]));
	}
	return mindis;
}
