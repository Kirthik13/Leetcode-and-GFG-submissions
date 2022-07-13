class Solution {
public:
    int fn(vector<int>& v, int idx,int n,int buy,int &fee,  vector<vector<int>>&dp)
    {
        if(idx>=n) return 0;
        
        
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int curr_res;

        if(buy)
        {
            int bought=fn(v,idx+1,n,false,fee,dp)-v[idx];
            int notbought=fn(v,idx+1,n,buy,fee,dp);
            
            curr_res=max(bought,notbought);

        }
        else{
             int sold=fn(v,idx+1,n,true,fee,dp)+(v[idx]-fee);
            int notsold=fn(v,idx+1,n,buy,fee,dp);
            
            curr_res=max(sold,notsold);

        }
        return dp[idx][buy]= curr_res;
    }
    int maxProfit(vector<int>& v, int fee) {
        int n=v.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,0));
        vector<int>dp(2,0);
        // vector<int>curr(2,0);

        
        for(int idx=n-1;idx>=0;idx--)
        {
           
                    int bought=dp[false]-v[idx];
                    int notbought=dp[true];
                    dp[true]=max(bought,notbought);

                    int sold=dp[true]+(v[idx]-fee);
                    int notsold=dp[false];
                    dp[false]=max(sold,notsold);

            
        }
        
        return dp[1];
        // return fn(v,0,n,1,fee,dp);
    }
};