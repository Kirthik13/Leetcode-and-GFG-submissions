class Solution {
public:
    int fn(vector<int>&v,int idx,int n,int status,int k, vector<vector<vector<int>>>&dp)
    {
        if(idx>=n) return 0;
        if(k==0) return 0;
        
        if(dp[idx][k][status]!=-1)  return dp[idx][k][status];
        
        int curr{};
        
        if(status==0)
        {
            int buy=fn(v,idx+1,n,1,k,dp)-v[idx];
            int notbuy=fn(v,idx+1,n,0,k,dp);
            curr=max(buy,notbuy);
        }
        else{
             int sell=fn(v,idx+1,n,0,k-1,dp)+v[idx];
            int notsell=fn(v,idx+1,n,1,k,dp);
            curr=max(sell,notsell);
            
        }
        
        return dp[idx][k][status]=curr;
        
    }
    int maxProfit(int k1, vector<int>& v) {
        int n=v.size();
       vector<vector<int>>dp(k1+1,vector<int>(2,0));
        
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int k=1;k<=k1;k++)
            {
                for(int status=1;status>=0;status--)
                {
                    int curr{};
        
                    if(status==0)
                    {
                        int buy=dp[k][1]-v[idx];
                        int notbuy=dp[k][0];
                        curr=max(buy,notbuy);
                    }
                    else{
                         int sell=dp[k-1][0]+v[idx];
                        int notsell=dp[k][1];
                        curr=max(sell,notsell);

                    }

                    dp[k][status]=curr;
                }
            }
        }
        
        return dp[k1][0];
        // return fn(v,0,n,0,k,dp);
    }
};