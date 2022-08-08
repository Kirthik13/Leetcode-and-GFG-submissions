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
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int prev=n-1;prev>=-1;prev--)
            {
                int call1{},call2{};
                if(prev==-1 or v[prev]<v[idx])
                {
                    call1=1+dp[idx+1][idx+1];
                }
                
                
                call2=dp[idx+1][prev+1];
        
                dp[idx][prev+1]=max({call1,call2});
        
            }
        }
        
        return dp[0][0];
        // return fn(v,0,n,-1,dp);
    }
};