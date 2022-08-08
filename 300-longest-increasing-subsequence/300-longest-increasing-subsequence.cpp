class Solution {
public:
    // long long dp[2501][2502];
    int fn(vector<int>&v ,int idx,int n,int prev,vector<vector<int>>&dp)
    {
        if(idx>=n)
        {
            return 0;
        }
        
        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
        
        int call1{},call2{};
        if(prev==-1 or v[prev]<v[idx])
        {
            call1=1+fn(v,idx+1,n,idx,dp);
        }
        call2=fn(v,idx+1,n,prev,dp);
        
        return dp[idx][prev+1]=max({call1,call2});
        
    }
    int lengthOfLIS(vector<int>&v ) {
        int n=v.size();
        // memset(dp,-1,sizeof(dp));
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return fn(v,0,n,-1,dp);
    }
};