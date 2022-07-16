class Solution {
public:
    int fn(vector<int>&v,int idx,int n,int buy, vector<vector<int>>&dp)
    {
        if(idx>=n) return 0;
        
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        
        int curr_res{};
        
        
        
        if(buy)
        {
            int bought=fn(v,idx+1,n,false,dp)-v[idx];
            int notbought=fn(v,idx+1,n,buy,dp);
            
            curr_res=max(bought,notbought);

        }
        else{
             int sold=fn(v,idx+2,n,true,dp)+v[idx];
            int notsold=fn(v,idx+1,n,buy,dp);
            
            curr_res=max(sold,notsold);

            
        }
        return dp[idx][buy]=curr_res;
    }
    int maxProfit(vector<int>& v) {
        int n=v.size();
        
        // vector<vector<int>>dp(n+2,vector<int>(2,0));

        vector<int>dp(2,0);
        vector<int>curr(2,0);
            int temp=dp[1];

        
        for(int idx=n-1;idx>=0;idx--)
        {
            

          
                
                    int bought=dp[false]-v[idx];
                    int notbought=dp[true];

                   curr[1]=max(bought,notbought);

              
                     int sold=temp+v[idx];
                    int notsold=dp[false];

                    curr[0]=max(sold,notsold);


                
              
            
            temp=dp[true];
            dp=curr;
        }
        
        
        return dp[1];
        // return fn(v,0,n,1,dp);
    }
};