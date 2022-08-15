class Solution {
public:
    int fn(vector<int>& v,int idx,int n,int status,int k,vector<vector<vector<int>>>&dp) 
    {
                if(k==0) return 0;

        if(idx>=n)
        {
            return 0;
        }
        
        
        if( dp[idx][k][status]!=-1) return dp[idx][k][status];
        int curr{};
        if(status==0)
        {
            int buy=fn(v,idx+1,n,1,k,dp)-v[idx];
            int notbuy=fn(v,idx+1,n,status,k,dp);
            
            curr=max(buy,notbuy);
        }
        else{
            
            int sell=fn(v,idx+1,n,0,k-1,dp)+v[idx];
            int notsell=fn(v,idx+1,n,status,k,dp);
            
            curr=max(sell,notsell);
        }
        
        return dp[idx][k][status]=curr;
            
    }
    int maxProfit(vector<int>& v) {
        int n=v.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(2,-1)));
        return fn(v,0,n,0,2,dp);
    }
};