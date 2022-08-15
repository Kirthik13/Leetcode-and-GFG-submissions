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
        vector<vector<int>>dp(3,vector<int>(2,0));
        
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int k=1;k<=2;k++)
            {
                for(int status=1;status>=0;status--)
                {
                    int curr{};
                    if(status==0)
                    {
                        int buy=dp[k][1]-v[idx];
                        int notbuy=dp[k][status];

                        curr=max(buy,notbuy);
                    }
                    else{

                        int sell=dp[k-1][0]+v[idx];
                        int notsell=dp[k][status];

                        curr=max(sell,notsell);
                    }
                    
                    dp[k][status]=curr;
                    
                }
            }
        }
        
        return dp[2][0];
        // return fn(v,0,n,0,2,dp);
    }
};