class Solution {
public:
    int fn(vector<int>& v,int idx,int n,int buy,int k, vector<vector<vector<int>>>&dp)
    {
        if(idx>=n) return 0;
        
        if(k==0) return 0;
        
        if(dp[idx][k][buy]!=-1) return dp[idx][k][buy];
        
        int curr_res{};
        
        if(buy)
        {
            int bought=fn(v,idx+1,n,false,k,dp)-v[idx];
            int notbought=fn(v,idx+1,n,buy,k,dp);
            curr_res=max(bought,notbought);
        }
        else{
            int sold=fn(v,idx+1,n,true,k-1,dp)+v[idx];
            int notsold=fn(v,idx+1,n,buy,k,dp);
            curr_res=max(sold,notsold);
        }
        return dp[idx][k][buy]=curr_res;
        
    }
    int maxProfit(int k, vector<int>& v) {
        int n=v.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return fn(v,0,n,1,k,dp);
    }
};