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
         dp[n]=1;
        for(int i=n-1;i>=0;i--)
        {
            int f{},s=0;
            if(i+2<=n)
            {
                s=dp[i+2];
            }
            f=dp[i+1];
            dp[i]=f+s;
        }
        // return fn(0,n,dp);   
        return dp[0];
    }
};