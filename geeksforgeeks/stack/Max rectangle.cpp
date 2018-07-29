/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*You are required to complete this method*/

int maxHist(int v[], int m){
	int maxarea = 0, i = 0;
	stack<int> s;
	while(i < m){
		if(s.empty() || v[s.top()] <= v[i]){
			s.push(i++);
		}else{
			int e = s.top();
			s.pop();
			int area = v[e]*(s.empty() ? i : i-s.top()-1);
			maxarea = max(maxarea, area);
		}
	}
	while(!s.empty()){
		int e = s.top();
		s.pop();
		int area = v[e]*(s.empty() ? i : i-s.top()-1);
		maxarea = max(maxarea, area);
	}
	return maxarea;
}

int maxArea(int M[MAX][MAX],int n,int m)
{
    int maxarea = 0;
    for(int i=0;i<n;i++){
    	if(i == 0){
    		maxarea = max(maxarea, maxHist(M[i], m));
    	}else{
    		for(int j=0;j<m;j++){
    			if(M[i][j] != 0){
    				M[i][j] += M[i-1][j];
    				maxarea = max(maxarea, maxHist(M[i], m));
    			}
    		}
    	}
    }
    return maxarea;
}
