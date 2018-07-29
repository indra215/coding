/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*You are required to complete this method */

int* leftSmaller(int A[], int N){
	stack<int> s;
	int *result = new int[N];
	for(int i=N-1;i>=0;i--){
		if(s.empty() || A[s.top()] <= A[i]){
			s.push(i);
		}else{
			int e = s.top();
			s.pop();
			while(A[e] > A[i]){
				result[e] = A[i];
				if(s.empty())
					break;
				e = s.top();
				s.pop();
			}
			if(A[e] < A[i])
				s.push(e);
			s.push(i);
		}
	}
	while(!s.empty()){
		int e = s.top();
		s.pop();
		result[e] = 0;
	}
	return result;
}

int* rightSmaller(int A[], int N){
	stack<int> s;
	int *result = new int[N];
	for(int i=0;i<N;i++){
		if(s.empty() || A[s.top()] <= A[i]){
			s.push(i);
		}else{
			int e = s.top();
			s.pop();
			while(A[e] > A[i]){
				result[e] = A[i];
				if(s.empty())
					break;
				e = s.top();
				s.pop();
			}
			if(A[e] < A[i])
				s.push(e);
			s.push(i);
		}
	}
	while(!s.empty()){
		int e = s.top();
		s.pop();
		result[e] = 0;
	}
	return result;
}

void print(int A[], int N){
	for(int i=0;i<N;i++){
		cout << A[i] << " ";
	}
	cout << "\n";
}

int findMaxDiff(int A[], int N)
{
	int *left = new int[N];
	int *right = new int[N];
	left = leftSmaller(A, N);
	// print(left, N);
	right = rightSmaller(A, N);
	// print(right, N);
	int maxdiff = 0;
	for(int i=0;i<N;i++){
		int t = abs(left[i]-right[i]);
		maxdiff = max(maxdiff, t);
	}
	return maxdiff;
}