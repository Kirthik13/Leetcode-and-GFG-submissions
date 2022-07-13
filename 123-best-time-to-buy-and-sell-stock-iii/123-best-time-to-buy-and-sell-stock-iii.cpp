class Solution {
public:
    int fn(vector<int>&v,int idx,int n,int nos,int buy, vector<vector<vector<int>>>&dp)
    {
        if(idx>=n)
        {
            return 0;
        }
        if(nos==0)
        {
            return 0;
        }
        
        if(dp[idx][nos][buy]!=-1) return dp[idx][nos][buy];
        
        int curr_ans;
        
        if(buy)
        {
            int bought=fn(v,idx+1,n,nos,false,dp)-v[idx];
            int notbought=fn(v,idx+1,n,nos,true,dp);
            
            curr_ans=max(bought,notbought);

        }
        else{
             int sold=fn(v,idx+1,n,nos-1,true,dp)+v[idx];
            int notsold=fn(v,idx+1,n,nos,false,dp);
            
            curr_ans=max(sold,notsold);
        }
        
        return dp[idx][nos][buy]=curr_ans;
    }
    int maxProfit(vector<int>& v) {
        int n=v.size();
        
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(2,0)));
        
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int nos=1;nos<=2;nos++)
            {
                for(int buy=0;buy<=1;buy++)
                {
            
                
                     int curr_ans;
        
                    if(buy)
                    {
                        int bought=dp[idx+1][nos][false]-v[idx];
                        int notbought=dp[idx+1][nos][buy];

                        curr_ans=max(bought,notbought);

                    }
                    else{
                         int sold=dp[idx+1][nos-1][true]+v[idx];
                        int notsold=dp[idx+1][nos][buy];

                        curr_ans=max(sold,notsold);
                    }

                    dp[idx][nos][buy]=curr_ans;

                    
                }

                
            }
        }
        
        
        // return fn(v,0,n,2,1,dp)
        return dp[0][2][1];
    }
};