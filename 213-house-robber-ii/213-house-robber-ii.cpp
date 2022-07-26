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

        vector<int>dp1(n+2,0);
        vector<int>dp2(n+2,0);
        
        for(int idx=n-1;idx>=1;idx--)
        {
             int call1=v[idx]+dp1[idx+2];
             int call2=dp1[idx+1];
        
             dp1[idx]=max(call1,call2);
        }
        
         for(int idx=n-2;idx>=0;idx--)
        {
             int call1=v[idx]+dp2[idx+2];
             int call2=dp2[idx+1];
        
             dp2[idx]=max(call1,call2);
        }
        
        return max(dp1[1],dp2[0]);
        // return max(fn(v,1,n,dp1),fn(v,0,n-1,dp2));
    }
};