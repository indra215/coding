int Solution::cntBits(vector<int> &A) {
     
    long long   ans = 0; 
    for (int i = 0; i < 32; i++)
    {
        long long   cnt = 0;
        for (int j = 0; j < A.size(); j++)
            if ( (A[j] & (1 << i)) )
                cnt++;
        ans += (cnt * (A.size() - cnt) * 2);
        ans %= 1000000007;
    }
 
    return ans;
}