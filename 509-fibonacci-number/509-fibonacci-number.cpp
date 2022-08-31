class Solution {
public:
    int dp[31];
    int fn(int n)
    {
        if(n<0) return 0;
        if(n<=1) return n;
        
        if(dp[n]!=-1) return dp[n];
        
        return dp[n]=fn(n-1)+fn(n-2);
    }
    int fib(int n) {
        
        memset(dp,-1,sizeof(dp));
        return fn(n);
        
    }
};