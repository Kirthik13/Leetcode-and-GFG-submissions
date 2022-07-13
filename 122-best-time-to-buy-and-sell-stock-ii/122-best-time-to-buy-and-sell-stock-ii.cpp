class Solution {
public:
    int dp[30001][2];
    int fn(vector<int>&v,int idx,int n,int flag)
    {
        if(idx>=n) return 0;
        
        if(dp[idx][flag]!=-1) return dp[idx][flag];
        
        int curr_res{};
        if(flag==0)
        {
            int buy=fn(v,idx+1,n,1)-v[idx];
            int notbuy=fn(v,idx+1,n,0);
            curr_res=max(buy,notbuy);
        }
        else{
             int sell=fn(v,idx+1,n,0)+v[idx];
            int notsell=fn(v,idx+1,n,1);
            curr_res=max(sell,notsell);
        }
        return dp[idx][flag]=curr_res;
    }
    int maxProfit(vector<int>& v) {
        memset(dp,-1,sizeof(dp));
        return fn(v,0,v.size(),0);
    }
};