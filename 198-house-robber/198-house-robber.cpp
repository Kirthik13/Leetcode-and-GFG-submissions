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
        vector<int>dp(n+1,-1);
        return fn(v,0,n,dp);
    }
};