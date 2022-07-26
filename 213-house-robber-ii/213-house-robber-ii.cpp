class Solution {
public:
    int fn(vector<int>&v,int idx,int n,vector<int>&dp)
    {
        if(idx>=n) return 0;
        
        if(dp[idx]!=-1) return dp[idx];
        
        int call1=v[idx]+fn(v,idx+2,n,dp);
        int call2=fn(v,idx+1,n,dp);
        
        return dp[idx]=max(call1,call2);
        
    }
    int rob(vector<int>& v) {
        int n=v.size();
        if(n==1) return v[0];

        vector<int>dp1(n+2,-1);
        vector<int>dp2(n+2,-1);
        
        return max(fn(v,1,n,dp1),fn(v,0,n-1,dp2));
    }
};