class Solution {
public:
    int dp[1001][101][2];
    int fn(vector<int>& v,int idx,int n,int k,int canbuy)
    {

        if(idx>=n)
        {
            // if(k==0) return 0;
            return 0;
        }
        
                if(k==0) return 0;

            
        if(dp[idx][k][canbuy]!=-1)   return dp[idx][k][canbuy];
        
        int call1{},call2{};
        if(canbuy)
        {
            call1=fn(v,idx+1,n,k,0)-v[idx];
            call2=fn(v,idx+1,n,k,canbuy);
            
        }
        else{
            call1=fn(v,idx+1,n,k-1,1)+v[idx];
            call2=fn(v,idx+1,n,k,canbuy);
        }
        
        return dp[idx][k][canbuy]=max(call1,call2);
        
    }
    int maxProfit(int k, vector<int>& v) {
        int n=v.size();
        // vector<vector<int>>dp()
        memset(dp,-1,sizeof(dp));
        return fn(v,0,n,k,1);
    }
};