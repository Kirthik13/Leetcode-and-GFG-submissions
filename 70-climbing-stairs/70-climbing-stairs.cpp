class Solution {
public:
    int fn(int idx,int n, vector<int>&dp)
    {
        if(idx==n) return 1;
        if(idx>n) return 0;
        
        if(dp[idx]!=-1) return dp[idx];
        
        return dp[idx]=fn(idx+1,n,dp)+fn(idx+2,n,dp);
    }
        
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return fn(0,n,dp);   
    }
};