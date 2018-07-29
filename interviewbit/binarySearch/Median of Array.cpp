double median(const vector<int> &arr) {
	int l = arr.size();
	if(l%2 != 0)
		return (arr[l/2-1] + arr[l/2])/2.0;
	return (double)arr[l/2];
}

double getMedian(const vector<int> &A, const vector<int> &B) {
	double m1 = median(A);
	double m2 = median(B);

	if(m1 == m2)
		return m1;

	int m = A.size(), n = B.size();
	if(m1 < m2){
		if(m%2 == 0)
			A.erase(A.begin(), A.begin()+m/2-1-1);
		else A.erase(A.begin(), A.begin()+m/2-1);
		B.erase(B.begin()+n/2+1, B.end());
		return getMedian(A, B);
	}

	if(n%2 == 0)
		B.erase(B.begin(), B.begin()+n/2-1-1);
	else B.erase(B.begin(), B.begin()+n/2-1);
	A.erase(A.begin()+m/2+1, A.end());
	return getMedian(A, B);
}

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(A.empty() && !B.empty()){
		if(B.size()%2 == 0){
			double m = (B[B.size()/2-1] + B[B.size()/2])/2.0;
			return m;
		}
		return B[B.size()/2];
	}
	if(B.empty() && !A.empty()){
		if(A.size()%2 == 0){
			double m = (A[A.size()/2-1] + A[A.size()/2])/2.0;
			return m;
		}
		return A[A.size()/2];
	}

	return getMedian(A, B);
}