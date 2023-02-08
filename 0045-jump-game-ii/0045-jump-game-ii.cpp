class Solution {
public:
    int fn(vector<int>&v,int idx,int n,vector<int>&dp)
    {
        // if(idx==n-1) return 0;
        if(idx>=n-1) return 0;
        
        if(dp[idx]!=-1) return dp[idx];
        
        // int ans=0;
        int ans=100001;
        for(int i=1;i<=v[idx];i++)
        {
            int call1=fn(v,idx+i,n,dp);
            // if(call1!=INT_MAX) call1++;
            ans=min(call1,ans);
        }
        
//         if(ans!=INT_MAX)
//         {

        
//         return dp[idx]=ans+1;
//         }
        return dp[idx]=ans+1;
        
    }
    int jump(vector<int>& v) {
        
        int n=v.size();
        vector<int>dp(n+1,-1);
        return fn(v,0,n,dp);
        
    }
};