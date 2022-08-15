class Solution {
public:
    int fn(vector<int>& v,int idx,int n,int status,vector<vector<int>>&dp)
    {
        if(idx>=n)
        {
            return 0;
        }
         if(  dp[idx][status]!=-1)return dp[idx][status];
        int curr=0;
        
        if(status==0)
        {
            
           int buy=fn(v,idx+1,n,1,dp)-v[idx];
           int notbuy=fn(v,idx+1,n,0,dp);
        
            curr=max(buy,notbuy);
            
        }
        if(status)
        {
          int sell=fn(v,idx+1,n,0,dp)+v[idx];
           int notsell=fn(v,idx+1,n,1,dp);
        
            curr=max(sell,notsell);
        }
    return dp[idx][status]=curr;
    }
    int maxProfit(vector<int>& v) {
        
        int n=v.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return fn(v,0,n,0,dp);
    }
};