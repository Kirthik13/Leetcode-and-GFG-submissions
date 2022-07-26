class Solution {
public:
    int fn(vector<int>&v,int idx,int n,vector<int>&dp)
    {
        if(idx>=n) return 0;
        
        if(dp[idx]!=-1) return dp[idx];
        
        int call1=v[idx]+fn(v,idx+2,n,dp);
        int call2=fn(v,idx+1,n,dp);
        
        int ans=max(call1,call2);
        return dp[idx]=ans;
        
    }
    int rob(vector<int>& v) {
        int n=v.size();
        vector<int>dp(n+2,0);
        
        for(int idx=n-1;idx>=0;idx--)
        {
            int call1=v[idx]+dp[idx+2];
            int call2=dp[idx+1];
            
            int ans=max(call1,call2);
            
            dp[idx]=ans;
        }
        return dp[0];
        // return fn(v,0,n,dp);
    }
};